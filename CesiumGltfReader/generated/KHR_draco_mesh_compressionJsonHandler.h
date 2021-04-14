// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "CesiumGltf/Reader.h"
#include "CesiumJsonReader/DictionaryJsonHandler.h"
#include "CesiumJsonReader/IntegerJsonHandler.h"
#include "ExtensibleObjectJsonHandler.h"

namespace CesiumGltf {
struct ReaderContext;
struct KHR_draco_mesh_compression;

class KHR_draco_mesh_compressionJsonHandler
    : public ExtensibleObjectJsonHandler,
      public IExtensionJsonHandler {
public:
  static inline const std::string ExtensionName = "KHR_draco_mesh_compression";

  KHR_draco_mesh_compressionJsonHandler(const ReaderContext& context) noexcept;
  void reset(IJsonHandler* pParentHandler, KHR_draco_mesh_compression* pObject);
  KHR_draco_mesh_compression* getObject();
  virtual void reportWarning(
      const std::string& warning,
      std::vector<std::string>&& context = std::vector<std::string>()) override;

  virtual IJsonHandler* readObjectKey(const std::string_view& str) override;

  virtual void reset(
      IJsonHandler* pParentHandler,
      ExtensibleObject& o,
      const std::string_view& extensionName) override;

  virtual IJsonHandler* readNull() override {
    return ExtensibleObjectJsonHandler::readNull();
  };
  virtual IJsonHandler* readBool(bool b) override {
    return ExtensibleObjectJsonHandler::readBool(b);
  }
  virtual IJsonHandler* readInt32(int32_t i) override {
    return ExtensibleObjectJsonHandler::readInt32(i);
  }
  virtual IJsonHandler* readUint32(uint32_t i) override {
    return ExtensibleObjectJsonHandler::readUint32(i);
  }
  virtual IJsonHandler* readInt64(int64_t i) override {
    return ExtensibleObjectJsonHandler::readInt64(i);
  }
  virtual IJsonHandler* readUint64(uint64_t i) override {
    return ExtensibleObjectJsonHandler::readUint64(i);
  }
  virtual IJsonHandler* readDouble(double d) override {
    return ExtensibleObjectJsonHandler::readDouble(d);
  }
  virtual IJsonHandler* readString(const std::string_view& str) override {
    return ExtensibleObjectJsonHandler::readString(str);
  }
  virtual IJsonHandler* readObjectStart() override {
    return ExtensibleObjectJsonHandler::readObjectStart();
  }
  virtual IJsonHandler* readObjectEnd() override {
    return ExtensibleObjectJsonHandler::readObjectEnd();
  }
  virtual IJsonHandler* readArrayStart() override {
    return ExtensibleObjectJsonHandler::readArrayStart();
  }
  virtual IJsonHandler* readArrayEnd() override {
    return ExtensibleObjectJsonHandler::readArrayEnd();
  }

protected:
  IJsonHandler* readObjectKeyKHR_draco_mesh_compression(
      const std::string& objectType,
      const std::string_view& str,
      KHR_draco_mesh_compression& o);

private:
  KHR_draco_mesh_compression* _pObject = nullptr;
  CesiumJsonReader::IntegerJsonHandler<int32_t> _bufferView;
  CesiumJsonReader::DictionaryJsonHandler<
      int32_t,
      CesiumJsonReader::IntegerJsonHandler<int32_t>>
      _attributes;
};
} // namespace CesiumGltf
