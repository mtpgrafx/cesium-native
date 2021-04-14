// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#include "CameraOrthographicJsonHandler.h"
#include "CesiumGltf/CameraOrthographic.h"

#include <cassert>
#include <string>

using namespace CesiumGltf;

CameraOrthographicJsonHandler::CameraOrthographicJsonHandler(
    const ReaderContext& context) noexcept
    : ExtensibleObjectJsonHandler(context),
      _xmag(),
      _ymag(),
      _zfar(),
      _znear() {}

void CameraOrthographicJsonHandler::reset(
    CesiumJsonReader::IJsonHandler* pParentHandler,
    CameraOrthographic* pObject) {
  ExtensibleObjectJsonHandler::reset(pParentHandler, pObject);
  this->_pObject = pObject;
}

CameraOrthographic* CameraOrthographicJsonHandler::getObject() {
  return this->_pObject;
}

void CameraOrthographicJsonHandler::reportWarning(
    const std::string& warning,
    std::vector<std::string>&& context) {
  if (this->getCurrentKey()) {
    context.emplace_back(std::string(".") + this->getCurrentKey());
  }
  this->parent()->reportWarning(warning, std::move(context));
}

CesiumJsonReader::IJsonHandler*
CameraOrthographicJsonHandler::readObjectKey(const std::string_view& str) {
  assert(this->_pObject);
  return this->readObjectKeyCameraOrthographic(
      CameraOrthographic::TypeName,
      str,
      *this->_pObject);
}

CesiumJsonReader::IJsonHandler*
CameraOrthographicJsonHandler::readObjectKeyCameraOrthographic(
    const std::string& objectType,
    const std::string_view& str,
    CameraOrthographic& o) {
  using namespace std::string_literals;

  if ("xmag"s == str)
    return property("xmag", this->_xmag, o.xmag);
  if ("ymag"s == str)
    return property("ymag", this->_ymag, o.ymag);
  if ("zfar"s == str)
    return property("zfar", this->_zfar, o.zfar);
  if ("znear"s == str)
    return property("znear", this->_znear, o.znear);

  return this->readObjectKeyExtensibleObject(objectType, str, *this->_pObject);
}
