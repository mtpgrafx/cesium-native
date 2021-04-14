// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#include "ModelJsonHandler.h"
#include "CesiumGltf/Model.h"

#include <cassert>
#include <string>

using namespace CesiumGltf;

ModelJsonHandler::ModelJsonHandler(const ReaderContext& context) noexcept
    : ExtensibleObjectJsonHandler(context),
      _extensionsUsed(),
      _extensionsRequired(),
      _accessors(context),
      _animations(context),
      _asset(context),
      _buffers(context),
      _bufferViews(context),
      _cameras(context),
      _images(context),
      _materials(context),
      _meshes(context),
      _nodes(context),
      _samplers(context),
      _scene(),
      _scenes(context),
      _skins(context),
      _textures(context) {}

void ModelJsonHandler::reset(
    CesiumJsonReader::IJsonHandler* pParentHandler,
    Model* pObject) {
  ExtensibleObjectJsonHandler::reset(pParentHandler, pObject);
  this->_pObject = pObject;
}

Model* ModelJsonHandler::getObject() { return this->_pObject; }

void ModelJsonHandler::reportWarning(
    const std::string& warning,
    std::vector<std::string>&& context) {
  if (this->getCurrentKey()) {
    context.emplace_back(std::string(".") + this->getCurrentKey());
  }
  this->parent()->reportWarning(warning, std::move(context));
}

CesiumJsonReader::IJsonHandler*
ModelJsonHandler::readObjectKey(const std::string_view& str) {
  assert(this->_pObject);
  return this->readObjectKeyModel(Model::TypeName, str, *this->_pObject);
}

CesiumJsonReader::IJsonHandler* ModelJsonHandler::readObjectKeyModel(
    const std::string& objectType,
    const std::string_view& str,
    Model& o) {
  using namespace std::string_literals;

  if ("extensionsUsed"s == str)
    return property("extensionsUsed", this->_extensionsUsed, o.extensionsUsed);
  if ("extensionsRequired"s == str)
    return property(
        "extensionsRequired",
        this->_extensionsRequired,
        o.extensionsRequired);
  if ("accessors"s == str)
    return property("accessors", this->_accessors, o.accessors);
  if ("animations"s == str)
    return property("animations", this->_animations, o.animations);
  if ("asset"s == str)
    return property("asset", this->_asset, o.asset);
  if ("buffers"s == str)
    return property("buffers", this->_buffers, o.buffers);
  if ("bufferViews"s == str)
    return property("bufferViews", this->_bufferViews, o.bufferViews);
  if ("cameras"s == str)
    return property("cameras", this->_cameras, o.cameras);
  if ("images"s == str)
    return property("images", this->_images, o.images);
  if ("materials"s == str)
    return property("materials", this->_materials, o.materials);
  if ("meshes"s == str)
    return property("meshes", this->_meshes, o.meshes);
  if ("nodes"s == str)
    return property("nodes", this->_nodes, o.nodes);
  if ("samplers"s == str)
    return property("samplers", this->_samplers, o.samplers);
  if ("scene"s == str)
    return property("scene", this->_scene, o.scene);
  if ("scenes"s == str)
    return property("scenes", this->_scenes, o.scenes);
  if ("skins"s == str)
    return property("skins", this->_skins, o.skins);
  if ("textures"s == str)
    return property("textures", this->_textures, o.textures);

  return this->readObjectKeyExtensibleObject(objectType, str, *this->_pObject);
}
