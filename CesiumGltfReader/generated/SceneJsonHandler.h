// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "CesiumGltf/Reader.h"
#include "CesiumJsonReader/ArrayJsonHandler.h"
#include "CesiumJsonReader/IntegerJsonHandler.h"
#include "NamedObjectJsonHandler.h"

namespace CesiumGltf {
struct ReaderContext;
struct Scene;

class SceneJsonHandler : public NamedObjectJsonHandler {
public:
  SceneJsonHandler(const ReaderContext& context) noexcept;
  void reset(IJsonHandler* pParentHandler, Scene* pObject);
  Scene* getObject();
  virtual void reportWarning(
      const std::string& warning,
      std::vector<std::string>&& context = std::vector<std::string>()) override;

  virtual IJsonHandler* readObjectKey(const std::string_view& str) override;

protected:
  IJsonHandler* readObjectKeyScene(
      const std::string& objectType,
      const std::string_view& str,
      Scene& o);

private:
  Scene* _pObject = nullptr;
  CesiumJsonReader::
      ArrayJsonHandler<int32_t, CesiumJsonReader::IntegerJsonHandler<int32_t>>
          _nodes;
};
} // namespace CesiumGltf
