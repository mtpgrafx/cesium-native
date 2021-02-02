// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#include "MaterialNormalTextureInfoJsonHandler.h"
#include "CesiumGltf/MaterialNormalTextureInfo.h"

#include <cassert>
#include <string>

using namespace CesiumGltf;

void MaterialNormalTextureInfoJsonHandler::reset(IJsonHandler* pParent, MaterialNormalTextureInfo* pObject) {
  TextureInfoJsonHandler::reset(pParent, pObject);
  this->_pObject = pObject;
}

MaterialNormalTextureInfo* MaterialNormalTextureInfoJsonHandler::getObject() {
  return this->_pObject;
}

void MaterialNormalTextureInfoJsonHandler::reportWarning(const std::string& warning, std::vector<std::string>&& context) {
  if (this->getCurrentKey()) {
    context.emplace_back(std::string(".") + this->getCurrentKey());
  }
  this->parent()->reportWarning(warning, std::move(context));
}

IJsonHandler* MaterialNormalTextureInfoJsonHandler::Key(const char* str, size_t /*length*/, bool /*copy*/) {
  assert(this->_pObject);
  return this->MaterialNormalTextureInfoKey(str, *this->_pObject);
}

IJsonHandler* MaterialNormalTextureInfoJsonHandler::MaterialNormalTextureInfoKey(const char* str, MaterialNormalTextureInfo& o) {
  using namespace std::string_literals;

  if ("scale"s == str) return property("scale", this->_scale, o.scale);

  return this->TextureInfoKey(str, *this->_pObject);
}
