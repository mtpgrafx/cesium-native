// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "AccessorSparseIndices.h"
#include "AccessorSparseValues.h"
#include "Library.h"

#include <CesiumUtility/ExtensibleObject.h>

#include <cstdint>

namespace CesiumGltf {
/**
 * @brief Sparse storage of accessor values that deviate from their
 * initialization value.
 */
struct CESIUMGLTF_API AccessorSparse final
    : public CesiumUtility::ExtensibleObject {
  static inline constexpr const char* TypeName = "AccessorSparse";

  /**
   * @brief Number of deviating accessor values stored in the sparse array.
   */
  int64_t count = int64_t();

  /**
   * @brief An object pointing to a buffer view containing the indices of
   * deviating accessor values. The number of indices is equal to `count`.
   * Indices **MUST** strictly increase.
   */
  AccessorSparseIndices indices;

  /**
   * @brief An object pointing to a buffer view containing the deviating
   * accessor values.
   */
  AccessorSparseValues values;
};
} // namespace CesiumGltf
