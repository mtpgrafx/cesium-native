// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#include "AccessorSparseValuesJsonHandler.h"
#include "CesiumGltf/AccessorSparseValues.h"

#include <cassert>
#include <string>

using namespace CesiumGltf;

AccessorSparseValuesJsonHandler::AccessorSparseValuesJsonHandler(
    const ReaderContext& context) noexcept
    : ExtensibleObjectJsonHandler(context), _bufferView(), _byteOffset() {}

void AccessorSparseValuesJsonHandler::reset(
    CesiumJsonReader::IJsonHandler* pParentHandler,
    AccessorSparseValues* pObject) {
  ExtensibleObjectJsonHandler::reset(pParentHandler, pObject);
  this->_pObject = pObject;
}

CesiumJsonReader::IJsonHandler*
AccessorSparseValuesJsonHandler::readObjectKey(const std::string_view& str) {
  assert(this->_pObject);
  return this->readObjectKeyAccessorSparseValues(
      AccessorSparseValues::TypeName,
      str,
      *this->_pObject);
}

CesiumJsonReader::IJsonHandler*
AccessorSparseValuesJsonHandler::readObjectKeyAccessorSparseValues(
    const std::string& objectType,
    const std::string_view& str,
    AccessorSparseValues& o) {
  using namespace std::string_literals;

  if ("bufferView"s == str)
    return property("bufferView", this->_bufferView, o.bufferView);
  if ("byteOffset"s == str)
    return property("byteOffset", this->_byteOffset, o.byteOffset);

  return this->readObjectKeyExtensibleObject(objectType, str, *this->_pObject);
}
