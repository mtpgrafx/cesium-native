// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "CesiumGltf/BufferView.h"
#include "IntegerJsonHandler.h"
#include "NamedObjectJsonHandler.h"
#include <CesiumGltf/Reader.h>

namespace CesiumGltf {
struct BufferView;

class BufferViewJsonHandler : public NamedObjectJsonHandler {
public:
  BufferViewJsonHandler(const JsonReaderContext& context) noexcept;
  void reset(IJsonHandler* pHandler, BufferView* pObject);
  BufferView* getObject();
  virtual void reportWarning(
      const std::string& warning,
      std::vector<std::string>&& context = std::vector<std::string>()) override;

  virtual IJsonHandler* readObjectKey(const std::string_view& str) override;

protected:
  IJsonHandler* readObjectKeyBufferView(
      const std::string& objectType,
      const std::string_view& str,
      BufferView& o);

private:
  BufferView* _pObject = nullptr;
  IntegerJsonHandler<int32_t> _buffer;
  IntegerJsonHandler<int64_t> _byteOffset;
  IntegerJsonHandler<int64_t> _byteLength;
  IntegerJsonHandler<int64_t> _byteStride;
  IntegerJsonHandler<BufferView::Target> _target;
};
} // namespace CesiumGltf
