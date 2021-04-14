// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#include "AccessorSparseJsonHandler.h"
#include "CesiumGltf/AccessorSparse.h"

#include <cassert>
#include <string>

using namespace CesiumGltf;

AccessorSparseJsonHandler::AccessorSparseJsonHandler(
    const ReaderContext& context) noexcept
    : ExtensibleObjectJsonHandler(context),
      _count(),
      _indices(context),
      _values(context) {}

void AccessorSparseJsonHandler::reset(
    CesiumJsonReader::IJsonHandler* pParentHandler,
    AccessorSparse* pObject) {
  ExtensibleObjectJsonHandler::reset(pParentHandler, pObject);
  this->_pObject = pObject;
}

AccessorSparse* AccessorSparseJsonHandler::getObject() {
  return this->_pObject;
}

void AccessorSparseJsonHandler::reportWarning(
    const std::string& warning,
    std::vector<std::string>&& context) {
  if (this->getCurrentKey()) {
    context.emplace_back(std::string(".") + this->getCurrentKey());
  }
  this->parent()->reportWarning(warning, std::move(context));
}

CesiumJsonReader::IJsonHandler*
AccessorSparseJsonHandler::readObjectKey(const std::string_view& str) {
  assert(this->_pObject);
  return this->readObjectKeyAccessorSparse(
      AccessorSparse::TypeName,
      str,
      *this->_pObject);
}

CesiumJsonReader::IJsonHandler*
AccessorSparseJsonHandler::readObjectKeyAccessorSparse(
    const std::string& objectType,
    const std::string_view& str,
    AccessorSparse& o) {
  using namespace std::string_literals;

  if ("count"s == str)
    return property("count", this->_count, o.count);
  if ("indices"s == str)
    return property("indices", this->_indices, o.indices);
  if ("values"s == str)
    return property("values", this->_values, o.values);

  return this->readObjectKeyExtensibleObject(objectType, str, *this->_pObject);
}
