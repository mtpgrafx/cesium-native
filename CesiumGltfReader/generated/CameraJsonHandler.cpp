// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#include "CameraJsonHandler.h"
#include "CesiumGltf/Camera.h"

#include <cassert>
#include <string>

using namespace CesiumGltf;

CameraJsonHandler::CameraJsonHandler(const JsonReaderContext& context) noexcept
    : NamedObjectJsonHandler(context),
      _orthographic(context),
      _perspective(context),
      _type(context) {}

void CameraJsonHandler::reset(IJsonHandler* pParent, Camera* pObject) {
  NamedObjectJsonHandler::reset(pParent, pObject);
  this->_pObject = pObject;
}

Camera* CameraJsonHandler::getObject() { return this->_pObject; }

void CameraJsonHandler::reportWarning(
    const std::string& warning,
    std::vector<std::string>&& context) {
  if (this->getCurrentKey()) {
    context.emplace_back(std::string(".") + this->getCurrentKey());
  }
  this->parent()->reportWarning(warning, std::move(context));
}

IJsonHandler* CameraJsonHandler::readObjectKey(const std::string_view& str) {
  assert(this->_pObject);
  return this->readObjectKeyCamera(Camera::TypeName, str, *this->_pObject);
}

IJsonHandler* CameraJsonHandler::readObjectKeyCamera(
    const std::string& objectType,
    const std::string_view& str,
    Camera& o) {
  using namespace std::string_literals;

  if ("orthographic"s == str)
    return property("orthographic", this->_orthographic, o.orthographic);
  if ("perspective"s == str)
    return property("perspective", this->_perspective, o.perspective);
  if ("type"s == str)
    return property("type", this->_type, o.type);

  return this->readObjectKeyNamedObject(objectType, str, *this->_pObject);
}

void CameraJsonHandler::TypeJsonHandler::reset(
    IJsonHandler* pParent,
    Camera::Type* pEnum) {
  JsonHandler::reset(pParent);
  this->_pEnum = pEnum;
}

IJsonHandler*
CameraJsonHandler::TypeJsonHandler::readString(const std::string_view& str) {
  using namespace std::string_literals;

  assert(this->_pEnum);

  if ("perspective"s == str)
    *this->_pEnum = Camera::Type::perspective;
  else if ("orthographic"s == str)
    *this->_pEnum = Camera::Type::orthographic;
  else
    return nullptr;

  return this->parent();
}
