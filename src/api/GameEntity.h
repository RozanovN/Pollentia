#pragma once

#include "../entities/CommonEntityHeader.h"

namespace GameEngine::GameEntity {
    DEFINE_ID_TYPE(entityId);

    /**
     * Represents Entity.
     *
     * @author Nikolay Rozanov
     * @version 1.0
     */
    class Entity {
        public:
            /**
             * Constructs a new Entity.
             *
             * @param id an unsigned integer
             */
            constexpr explicit Entity(entityId id) {
                id_ = id;
            }

            /**
             * Constructs a new Entity with invalid id_ mask.
             */
            constexpr explicit Entity() {
                id_ = Id::invalidIdMask;
            }

            /**
             * Returns this Entity's id_.
             *
             * @return an unsigned integer
             */
            [[nodiscard]] constexpr entityId get_id() const {
                return id_;
            }

            /**
            * Checks if this Entity is alive
            * Returns true if it's alive, otherwise false.
            *
            * @return true if entity is alive, otherwise false
            */
            [[nodiscard]] constexpr bool is_valid() const {
                return Id::is_valid(id_);
            }

        private:
            entityId id_;
    };
}
