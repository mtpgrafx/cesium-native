#include "Cesium3DTilesSelection/WebMapTileServiceRasterOverlay.h"

#include "Cesium3DTilesSelection/CreditSystem.h"
#include "Cesium3DTilesSelection/QuadtreeRasterOverlayTileProvider.h"
#include "Cesium3DTilesSelection/RasterOverlayLoadFailureDetails.h"
#include "Cesium3DTilesSelection/RasterOverlayTile.h"
#include "Cesium3DTilesSelection/TilesetExternals.h"
#include "Cesium3DTilesSelection/spdlog-cesium.h"
#include "Cesium3DTilesSelection/tinyxml-cesium.h"

#include <CesiumAsync/IAssetAccessor.h>
#include <CesiumAsync/IAssetResponse.h>
#include <CesiumGeospatial/GlobeRectangle.h>
#include <CesiumGeospatial/WebMercatorProjection.h>
#include <CesiumUtility/Uri.h>

#include <cstddef>
#include <regex>

using namespace CesiumAsync;
using namespace CesiumUtility;

namespace Cesium3DTilesSelection {

class WebMapTileServiceTileProvider final
    : public QuadtreeRasterOverlayTileProvider {
public:
  WebMapTileServiceTileProvider(
      const IntrusivePointer<const RasterOverlay>& pOwner,
      const CesiumAsync::AsyncSystem& asyncSystem,
      const std::shared_ptr<IAssetAccessor>& pAssetAccessor,
      std::optional<Credit> credit,
      const std::shared_ptr<IPrepareRendererResources>&
          pPrepareRendererResources,
      const std::shared_ptr<spdlog::logger>& pLogger,
      const CesiumGeospatial::Projection& projection,
      const CesiumGeometry::QuadtreeTilingScheme& tilingScheme,
      const CesiumGeometry::Rectangle& coverageRectangle,
      const std::string& url,
      const std::vector<IAssetAccessor::THeader>& headers,
      const bool useKVP,
      const std::string& format,
      uint32_t width,
      uint32_t height,
      uint32_t minimumLevel,
      uint32_t maximumLevel,
      std::string layer,
      std::string style,
      std::string _tileMatrixSetID,
      const std::optional<std::vector<std::string>> tileMatrixLabels,
      const std::optional<std::map<std::string, std::string>> dimensions,
      const std::vector<std::string>& subdomains)
      : QuadtreeRasterOverlayTileProvider(
            pOwner,
            asyncSystem,
            pAssetAccessor,
            credit,
            pPrepareRendererResources,
            pLogger,
            projection,
            tilingScheme,
            coverageRectangle,
            minimumLevel,
            maximumLevel,
            width,
            height),
        _url(url),
        _headers(headers),
        _useKVP(useKVP),
        _format(format),
        _layer(layer),
        _style(style),
        _tileMatrixSetID(_tileMatrixSetID),
        _labels(tileMatrixLabels),
        _staticDimensions(dimensions),
        _subdomains(subdomains) {}

  virtual ~WebMapTileServiceTileProvider() {}

protected:
  virtual CesiumAsync::Future<LoadedRasterOverlayImage> loadQuadtreeTileImage(
      const CesiumGeometry::QuadtreeTileID& tileID) const override {

    LoadTileImageFromUrlOptions options;
    options.rectangle = this->getTilingScheme().tileToRectangle(tileID);
    options.moreDetailAvailable = tileID.level < this->getMaximumLevel();

    uint32_t level = tileID.level;
    uint32_t col = tileID.x;
    uint32_t row = (1u << level) - tileID.y - 1u;

    std::map<std::string, std::string> urlTemplateMap;
    std::string tileMatrix;
    if (_labels && level < _labels.value().size()) {
      tileMatrix = _labels.value()[level];
    } else {
      tileMatrix = std::to_string(level);
    }

    std::string queryString = "?";
    if (this->_url.find(queryString) != std::string::npos) {
      queryString = "&";
    }
    std::string urlTemplate = _url;

    if (!_useKVP) {
      urlTemplateMap.insert(
          {{"Layer", _layer},
           {"Style", _style},
           {"TileMatrix", tileMatrix},
           {"TileRow", std::to_string(row)},
           {"TileCol", std::to_string(col)},
           {"TileMatrixSet", _tileMatrixSetID},
           {"s", _subdomains[(row + col + level) % _subdomains.size()]}});
      if (_staticDimensions) {
        urlTemplateMap.insert(
            _staticDimensions->begin(),
            _staticDimensions->end());
      }
    } else {
      urlTemplateMap.insert(
          {{"layer", _layer},
           {"style", _style},
           {"tilematrix", tileMatrix},
           {"tilerow", std::to_string(row)},
           {"tilecol", std::to_string(col)},
           {"tilematrixset", _tileMatrixSetID},
           {"format", _format}}); // !! These are query parameters
      if (_staticDimensions) {
        urlTemplateMap.insert(
            _staticDimensions->begin(),
            _staticDimensions->end());
      }
      urlTemplateMap.emplace(
          "s",
          _subdomains[(col + row + level) % _subdomains.size()]);

      urlTemplate +=
          queryString +
          "request=GetTile&version=1.0.0&service=WMTS&"
          "format={format}&layer={layer}&style={style}&"
          "tilematrixset={tilematrixset}&"
          "tilematrix={tilematrix}&tilerow={tilerow}&tilecol={tilecol}";
    }

    std::string url = CesiumUtility::Uri::substituteTemplateParameters(
        urlTemplate,
        [&map = urlTemplateMap](const std::string& placeholder) {
          auto it = map.find(placeholder);
          return it == map.end() ? "{" + placeholder + "}"
                                 : CesiumUtility::Uri::escape(it->second);
        });

    return this->loadTileImageFromUrl(url, this->_headers, std::move(options));
  }

private:
  std::string _url;
  std::vector<IAssetAccessor::THeader> _headers;
  bool _useKVP;
  std::string _format;
  std::string _layer;
  std::string _style;
  std::string _tileMatrixSetID;
  std::optional<std::vector<std::string>> _labels;
  std::optional<std::map<std::string, std::string>> _staticDimensions;
  std::vector<std::string> _subdomains;
};

WebMapTileServiceRasterOverlay::WebMapTileServiceRasterOverlay(
    const std::string& name,
    const std::string& url,
    const std::vector<IAssetAccessor::THeader>& headers,
    const WebMapTileServiceRasterOverlayOptions& wmtsOptions,
    const RasterOverlayOptions& overlayOptions)
    : RasterOverlay(name, overlayOptions),
      _url(url),
      _headers(headers),
      _options(wmtsOptions) {}

WebMapTileServiceRasterOverlay::~WebMapTileServiceRasterOverlay() {}

Future<RasterOverlay::CreateTileProviderResult>
WebMapTileServiceRasterOverlay::createTileProvider(
    const CesiumAsync::AsyncSystem& asyncSystem,
    const std::shared_ptr<CesiumAsync::IAssetAccessor>& pAssetAccessor,
    const std::shared_ptr<CreditSystem>& pCreditSystem,
    const std::shared_ptr<IPrepareRendererResources>& pPrepareRendererResources,
    const std::shared_ptr<spdlog::logger>& pLogger,
    CesiumUtility::IntrusivePointer<const RasterOverlay> pOwner) const {

  pOwner = pOwner ? pOwner : this;

  const std::optional<Credit> credit =
      this->_options.credit ? std::make_optional(pCreditSystem->createCredit(
                                  this->_options.credit.value(),
                                  pOwner->getOptions().showCreditsOnScreen))
                            : std::nullopt;

  bool hasError = false;
  std::string errorMessage;

  std::string layer;
  std::string style;
  std::string tileMatrixSetID;
  if (!_options.layer.has_value()) {
    hasError = true;
    errorMessage = "layer is required.";
  } else {
    layer = _options.layer.value();
  }
  if (!_options.style.has_value()) {
    hasError = true;
    errorMessage = "style is required.";
  } else {
    style = _options.style.value();
  }
  if (!_options.tileMatrixSetID.has_value()) {
    hasError = true;
    errorMessage = "tileMatrixSetID is required.";
  } else {
    tileMatrixSetID = _options.tileMatrixSetID.value();
  }
  std::string format = _options.format.value_or("image/jpeg");
  uint32_t tileWidth = _options.tileWidth.value_or(256);
  uint32_t tileHeight = _options.tileHeight.value_or(256);

  uint32_t minimumLevel = std::numeric_limits<uint32_t>::max();
  uint32_t maximumLevel = 0;

  if (maximumLevel < minimumLevel && maximumLevel == 0) {
    // Min and max levels unknown, so use defaults.
    minimumLevel = 0;
    maximumLevel = 25;
  }

  bool useKVP;

  std::regex bracket("\\{");
  std::regex bracketS("\\{s\\}");
  std::smatch matchBracket;
  bool hasMatch = std::regex_search(_url, matchBracket, bracket);
  if (!hasMatch ||
      (matchBracket.size() == 1 && std::regex_match(_url, bracketS))) {
    useKVP = true;
  } else {
    useKVP = false;
  }

  std::optional<std::map<std::string, std::string>> dimensions =
      _options.dimensions;

  minimumLevel = glm::min(minimumLevel, maximumLevel);

  minimumLevel = _options.minimumLevel.value_or(minimumLevel);
  maximumLevel = _options.maximumLevel.value_or(maximumLevel);

  CesiumGeospatial::GlobeRectangle tilingSchemeRectangle =
      CesiumGeospatial::GeographicProjection::MAXIMUM_GLOBE_RECTANGLE;
  CesiumGeospatial::Projection projection;

  if (_options.projection) {
    projection = _options.projection.value();
  } else {
    if (_options.ellipsoid) {
      projection =
          CesiumGeospatial::WebMercatorProjection(_options.ellipsoid.value());
    } else {
      projection = CesiumGeospatial::WebMercatorProjection();
    }
  }
  CesiumGeometry::Rectangle coverageRectangle =
      _options.coverageRectangle.value_or(
          projectRectangleSimple(projection, tilingSchemeRectangle));
  CesiumGeometry::QuadtreeTilingScheme tilingScheme(coverageRectangle, 1, 1);

  std::vector<std::string> subdomains;
  if (_options.subdomains) {
    const std::variant<std::string, std::vector<std::string>>& subdomains_v =
        _options.subdomains.value();
    if (subdomains_v.index() == 0) {
      const std::string& subdomains_s = std::get<std::string>(subdomains_v);
      for (std::string::const_iterator it = subdomains_s.begin();
           it != subdomains_s.end();
           ++it) {
        subdomains.emplace_back(std::to_string(*it));
      }
    } else {
      subdomains = std::get<std::vector<std::string>>(subdomains_v);
    }
  } else {
    subdomains.emplace_back("a");
    subdomains.emplace_back("b");
    subdomains.emplace_back("c");
  }

  if (hasError) {
    return asyncSystem
        .createResolvedFuture<RasterOverlay::CreateTileProviderResult>(
            nonstd::make_unexpected(RasterOverlayLoadFailureDetails{
                RasterOverlayLoadType::TileProvider,
                nullptr,
                errorMessage}));
  }
  return asyncSystem
      .createResolvedFuture<RasterOverlay::CreateTileProviderResult>(
          new WebMapTileServiceTileProvider(
              pOwner,
              asyncSystem,
              pAssetAccessor,
              credit,
              pPrepareRendererResources,
              pLogger,
              projection,
              tilingScheme,
              coverageRectangle,
              _url,
              _headers,
              useKVP,
              format,
              tileWidth,
              tileHeight,
              minimumLevel,
              maximumLevel,
              layer,
              style,
              tileMatrixSetID,
              _options.tileMatrixLabels,
              _options.dimensions,
              subdomains));
}

} // namespace Cesium3DTilesSelection
