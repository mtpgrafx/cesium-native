// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#include "KHR_draco_mesh_compressionJsonHandler.h"
#include "CesiumGltf/KHR_draco_mesh_compression.h"

#include <cassert>
#include <string>

using namespace CesiumGltf;

KHR_draco_mesh_compressionJsonHandler::KHR_draco_mesh_compressionJsonHandler(
    const JsonReaderContext& context) noexcept
    : ExtensibleObjectJsonHandler(context),
      _bufferView(context),
      _attributes(context) {}

void KHR_draco_mesh_compressionJsonHandler::reset(
    IJsonHandler* pParent,
    KHR_draco_mesh_compression* pObject) {
  ExtensibleObjectJsonHandler::reset(pParent, pObject);
  this->_pObject = pObject;
}

KHR_draco_mesh_compression* KHR_draco_mesh_compressionJsonHandler::getObject() {
  return this->_pObject;
}

void KHR_draco_mesh_compressionJsonHandler::reportWarning(
    const std::string& warning,
    std::vector<std::string>&& context) {
  if (this->getCurrentKey()) {
    context.emplace_back(std::string(".") + this->getCurrentKey());
  }
  this->parent()->reportWarning(warning, std::move(context));
}

IJsonHandler* KHR_draco_mesh_compressionJsonHandler::readObjectKey(
    const std::string_view& str) {
  assert(this->_pObject);
  return this->readObjectKeyKHR_draco_mesh_compression(
      KHR_draco_mesh_compression::TypeName,
      str,
      *this->_pObject);
}

void KHR_draco_mesh_compressionJsonHandler::reset(
    IJsonHandler* pParentHandler,
    ExtensibleObject& o,
    const std::string_view& extensionName) {
  std::any& value =
      o.extensions.emplace(extensionName, KHR_draco_mesh_compression())
          .first->second;
  this->reset(
      pParentHandler,
      &std::any_cast<KHR_draco_mesh_compression&>(value));
}

IJsonHandler*
KHR_draco_mesh_compressionJsonHandler::readObjectKeyKHR_draco_mesh_compression(
    const std::string& objectType,
    const std::string_view& str,
    KHR_draco_mesh_compression& o) {
  using namespace std::string_literals;

  if ("bufferView"s == str)
    return property("bufferView", this->_bufferView, o.bufferView);
  if ("attributes"s == str)
    return property("attributes", this->_attributes, o.attributes);

  return this->readObjectKeyExtensibleObject(objectType, str, *this->_pObject);
}
