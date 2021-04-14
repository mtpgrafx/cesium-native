// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#include "AnimationChannelTargetJsonHandler.h"
#include "CesiumGltf/AnimationChannelTarget.h"

#include <cassert>
#include <string>

using namespace CesiumGltf;

AnimationChannelTargetJsonHandler::AnimationChannelTargetJsonHandler(
    const ReaderContext& context) noexcept
    : ExtensibleObjectJsonHandler(context), _node(), _path() {}

void AnimationChannelTargetJsonHandler::reset(
    CesiumJsonReader::IJsonHandler* pParentHandler,
    AnimationChannelTarget* pObject) {
  ExtensibleObjectJsonHandler::reset(pParentHandler, pObject);
  this->_pObject = pObject;
}

AnimationChannelTarget* AnimationChannelTargetJsonHandler::getObject() {
  return this->_pObject;
}

void AnimationChannelTargetJsonHandler::reportWarning(
    const std::string& warning,
    std::vector<std::string>&& context) {
  if (this->getCurrentKey()) {
    context.emplace_back(std::string(".") + this->getCurrentKey());
  }
  this->parent()->reportWarning(warning, std::move(context));
}

CesiumJsonReader::IJsonHandler*
AnimationChannelTargetJsonHandler::readObjectKey(const std::string_view& str) {
  assert(this->_pObject);
  return this->readObjectKeyAnimationChannelTarget(
      AnimationChannelTarget::TypeName,
      str,
      *this->_pObject);
}

CesiumJsonReader::IJsonHandler*
AnimationChannelTargetJsonHandler::readObjectKeyAnimationChannelTarget(
    const std::string& objectType,
    const std::string_view& str,
    AnimationChannelTarget& o) {
  using namespace std::string_literals;

  if ("node"s == str)
    return property("node", this->_node, o.node);
  if ("path"s == str)
    return property("path", this->_path, o.path);

  return this->readObjectKeyExtensibleObject(objectType, str, *this->_pObject);
}

void AnimationChannelTargetJsonHandler::PathJsonHandler::reset(
    CesiumJsonReader::IJsonHandler* pParent,
    AnimationChannelTarget::Path* pEnum) {
  JsonHandler::reset(pParent);
  this->_pEnum = pEnum;
}

CesiumJsonReader::IJsonHandler*
AnimationChannelTargetJsonHandler::PathJsonHandler::readString(
    const std::string_view& str) {
  using namespace std::string_literals;

  assert(this->_pEnum);

  if ("translation"s == str)
    *this->_pEnum = AnimationChannelTarget::Path::translation;
  else if ("rotation"s == str)
    *this->_pEnum = AnimationChannelTarget::Path::rotation;
  else if ("scale"s == str)
    *this->_pEnum = AnimationChannelTarget::Path::scale;
  else if ("weights"s == str)
    *this->_pEnum = AnimationChannelTarget::Path::weights;
  else
    return nullptr;

  return this->parent();
}
