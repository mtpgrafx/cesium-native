// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "CesiumGltf/ExtensibleObject.h"
#include <cstdint>

namespace CesiumGltf {
    /**
     * @brief Combines input and output accessors with an interpolation algorithm to define a keyframe graph (but not its target).
     */
    struct AnimationSampler : public ExtensibleObject {
        enum class Interpolation {
            LINEAR,

            STEP,

            CUBICSPLINE
        };

        /**
         * @brief The index of an accessor containing keyframe input values, e.g., time.
         *
         * That accessor must have componentType `FLOAT`. The values represent time in seconds with `time[0] >= 0.0`, and strictly increasing values, i.e., `time[n + 1] > time[n]`.
         */
        int32_t input = -1;

        /**
         * @brief Interpolation algorithm.
         */
        Interpolation interpolation = Interpolation::LINEAR;

        /**
         * @brief The index of an accessor, containing keyframe output values.
         *
         * The index of an accessor containing keyframe output values. When targeting translation or scale paths, the `accessor.componentType` of the output values must be `FLOAT`. When targeting rotation or morph weights, the `accessor.componentType` of the output values must be `FLOAT` or normalized integer. For weights, each output element stores `SCALAR` values with a count equal to the number of morph targets.
         */
        int32_t output = -1;

    };
}
