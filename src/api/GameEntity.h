//
// Created by Nikolay on 2022-04-28.
//

#ifndef GAMEENGINE_GAMEENTITY_H
    #define GAMEENGINE_GAMEENTITY_H
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
                    this->id = id;
                }

                /**
                 * Constructs a new Entity with invalid id mask.
                 */
                constexpr explicit Entity() {
                    this->id = Id::invalidIdMask;
                }

                /**
                 * Returns this Entity's id.
                 *
                 * @return an unsigned integer
                 */
                [[nodiscard]] constexpr entityId get_id() const {
                    return this->id;
                }

                /**
                * Checks if this Entity is alive
                * Returns true if it's alive, otherwise false.
                *
                * @return true if entity is alive, otherwise false
                */
                [[nodiscard]] constexpr bool is_valid() const {
                    return Id::is_valid(id);
                }

            private:
                entityId id;
        };
    }

#endif //GAMEENGINE_GAMEENTITY_H
