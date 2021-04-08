#pragma once

#include "ExtensibleObjectJsonHandler.h"
#include "StringJsonHandler.h"
#include <CesiumGltf/Reader.h>

namespace CesiumGltf {
struct NamedObject;

class NamedObjectJsonHandler : public ExtensibleObjectJsonHandler {
protected:
  NamedObjectJsonHandler(const JsonReaderContext& context) noexcept;
  void reset(IJsonHandler* pParent, NamedObject* pObject);
  IJsonHandler* readObjectKeyNamedObject(
      const std::string& objectType,
      const std::string_view& str,
      NamedObject& o);

private:
  StringJsonHandler _name;
};
} // namespace CesiumGltf
