#pragma once

#include "../../entities/CommonEntityHeader.h"

namespace Pollentia::API::GameEntity {
    DEFINE_ID_TYPE(tranformationId);

    class TransformationComponent {
        public:
            /**
             * Constructs a new Transformation Component.
             *
             * @param id an unsigned integer
             */
            constexpr explicit TransformationComponent(tranformationId id) {
                id_ = id;
            }

            /**
             * Constructs a new Transformation Component with invalid id_ mask.
             */
            constexpr TransformationComponent() {
                id_ = Id::invalidIdMask;
            }

            /**
             * Returns this Transformation Component's id_.
             *
             * @return an unsigned integer
             */
            [[nodiscard]] constexpr tranformationId get_id() const {
                return id_;
            }

            /**
            * Checks if this Transformation Component is valid
            * Returns true if it's valid, otherwise false.
            *
            * @return true if this Component is valid, otherwise false
            */
            [[nodiscard]] constexpr bool is_valid() const {
                return Id::is_valid(id_);
            }
        private:
            tranformationId id_;
    };

}