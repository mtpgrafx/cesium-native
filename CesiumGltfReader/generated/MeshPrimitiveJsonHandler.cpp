// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#include "MeshPrimitiveJsonHandler.h"
#include "CesiumGltf/MeshPrimitive.h"

#include <cassert>
#include <string>

using namespace CesiumGltf;

MeshPrimitiveJsonHandler::MeshPrimitiveJsonHandler(
    const JsonReaderContext& context) noexcept
    : ExtensibleObjectJsonHandler(context),
      _attributes(context),
      _indices(context),
      _material(context),
      _mode(context),
      _targets(context) {}

void MeshPrimitiveJsonHandler::reset(
    IJsonHandler* pParent,
    MeshPrimitive* pObject) {
  ExtensibleObjectJsonHandler::reset(pParent, pObject);
  this->_pObject = pObject;
}

MeshPrimitive* MeshPrimitiveJsonHandler::getObject() { return this->_pObject; }

void MeshPrimitiveJsonHandler::reportWarning(
    const std::string& warning,
    std::vector<std::string>&& context) {
  if (this->getCurrentKey()) {
    context.emplace_back(std::string(".") + this->getCurrentKey());
  }
  this->parent()->reportWarning(warning, std::move(context));
}

IJsonHandler*
MeshPrimitiveJsonHandler::readObjectKey(const std::string_view& str) {
  assert(this->_pObject);
  return this->readObjectKeyMeshPrimitive(
      MeshPrimitive::TypeName,
      str,
      *this->_pObject);
}

IJsonHandler* MeshPrimitiveJsonHandler::readObjectKeyMeshPrimitive(
    const std::string& objectType,
    const std::string_view& str,
    MeshPrimitive& o) {
  using namespace std::string_literals;

  if ("attributes"s == str)
    return property("attributes", this->_attributes, o.attributes);
  if ("indices"s == str)
    return property("indices", this->_indices, o.indices);
  if ("material"s == str)
    return property("material", this->_material, o.material);
  if ("mode"s == str)
    return property("mode", this->_mode, o.mode);
  if ("targets"s == str)
    return property("targets", this->_targets, o.targets);

  return this->readObjectKeyExtensibleObject(objectType, str, *this->_pObject);
}
