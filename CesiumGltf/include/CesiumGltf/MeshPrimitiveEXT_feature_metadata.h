// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "FeatureIDAttribute.h"
#include "FeatureIDTexture.h"
#include "Library.h"

#include <CesiumUtility/ExtensibleObject.h>

#include <string>
#include <vector>

namespace CesiumGltf {
/**
 * @brief `EXT_feature_metadata extension` for a primitive in a glTF model, to
 * associate it with the root `EXT_feature_metadata` object.
 */
struct CESIUMGLTF_API MeshPrimitiveEXT_feature_metadata final
    : public CesiumUtility::ExtensibleObject {
  static inline constexpr const char* TypeName =
      "MeshPrimitiveEXT_feature_metadata";
  static inline constexpr const char* ExtensionName = "EXT_feature_metadata";

  /**
   * @brief An array of objects mapping per-vertex feature IDs to a feature
   * table.
   */
  std::vector<FeatureIDAttribute> featureIdAttributes;

  /**
   * @brief An array of objects mapping per-texel feature IDs to a feature
   * table.
   */
  std::vector<FeatureIDTexture> featureIdTextures;

  /**
   * @brief An array of IDs of feature textures from the root
   * `EXT_feature_metadata` object.
   */
  std::vector<std::string> featureTextures;
};
} // namespace CesiumGltf
