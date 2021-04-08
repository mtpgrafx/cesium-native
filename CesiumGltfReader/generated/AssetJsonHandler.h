// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "ExtensibleObjectJsonHandler.h"
#include "StringJsonHandler.h"
#include <CesiumGltf/Reader.h>

namespace CesiumGltf {
struct Asset;

class AssetJsonHandler : public ExtensibleObjectJsonHandler {
public:
  AssetJsonHandler(const JsonReaderContext& context) noexcept;
  void reset(IJsonHandler* pHandler, Asset* pObject);
  Asset* getObject();
  virtual void reportWarning(
      const std::string& warning,
      std::vector<std::string>&& context = std::vector<std::string>()) override;

  virtual IJsonHandler* readObjectKey(const std::string_view& str) override;

protected:
  IJsonHandler* readObjectKeyAsset(
      const std::string& objectType,
      const std::string_view& str,
      Asset& o);

private:
  Asset* _pObject = nullptr;
  StringJsonHandler _copyright;
  StringJsonHandler _generator;
  StringJsonHandler _version;
  StringJsonHandler _minVersion;
};
} // namespace CesiumGltf
