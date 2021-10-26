// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "TextureInfoJsonHandler.h"

#include <CesiumGltf/MaterialNormalTextureInfo.h>
#include <CesiumJsonReader/DoubleJsonHandler.h>

namespace CesiumJsonReader {
class ExtensionReaderContext;
}

namespace CesiumGltf {
class MaterialNormalTextureInfoJsonHandler : public TextureInfoJsonHandler {
public:
  using ValueType = MaterialNormalTextureInfo;

  MaterialNormalTextureInfoJsonHandler(
      const CesiumJsonReader::ExtensionReaderContext& context) noexcept;
  void reset(IJsonHandler* pParentHandler, MaterialNormalTextureInfo* pObject);

  virtual IJsonHandler* readObjectKey(const std::string_view& str) override;

protected:
  IJsonHandler* readObjectKeyMaterialNormalTextureInfo(
      const std::string& objectType,
      const std::string_view& str,
      MaterialNormalTextureInfo& o);

private:
  MaterialNormalTextureInfo* _pObject = nullptr;
  CesiumJsonReader::DoubleJsonHandler _scale;
};
} // namespace CesiumGltf
