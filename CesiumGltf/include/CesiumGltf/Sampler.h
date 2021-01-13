// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "CesiumGltf/NamedObject.h"

namespace CesiumGltf {
    /**
     * @brief Texture sampler properties for filtering and wrapping modes.
     */
    struct Sampler : public NamedObject {
        enum class MagFilter {
            NEAREST = 9728,

            LINEAR = 9729
        };

        enum class MinFilter {
            NEAREST = 9728,

            LINEAR = 9729,

            NEAREST_MIPMAP_NEAREST = 9984,

            LINEAR_MIPMAP_NEAREST = 9985,

            NEAREST_MIPMAP_LINEAR = 9986,

            LINEAR_MIPMAP_LINEAR = 9987
        };

        enum class WrapS {
            CLAMP_TO_EDGE = 33071,

            MIRRORED_REPEAT = 33648,

            REPEAT = 10497
        };

        enum class WrapT {
            CLAMP_TO_EDGE = 33071,

            MIRRORED_REPEAT = 33648,

            REPEAT = 10497
        };

        /**
         * @brief Magnification filter.
         *
         * Valid values correspond to WebGL enums: `9728` (NEAREST) and `9729` (LINEAR).
         */
        MagFilter magFilter;

        /**
         * @brief Minification filter.
         *
         * All valid values correspond to WebGL enums.
         */
        MinFilter minFilter;

        /**
         * @brief s wrapping mode.
         *
         * S (U) wrapping mode.  All valid values correspond to WebGL enums.
         */
        WrapS wrapS = WrapS(10497);

        /**
         * @brief t wrapping mode.
         *
         * T (V) wrapping mode.  All valid values correspond to WebGL enums.
         */
        WrapT wrapT = WrapT(10497);

    };
}
