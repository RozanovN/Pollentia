#pragma once

#include "CommonEntityHeader.h"

namespace GameEngine {
    DEFINE_ID_TYPE(entityId);

    namespace GameEntity {
        class Entity;
    }

    #define INITIALIZATION_INFO(component) namespace component {struct InitializationInfo;}
    INITIALIZATION_INFO(TransformationComponent);
    #undef InitializationInfo

    namespace GameEntity {

        /**
         * Represents Entity information.
         */
        typedef struct EntityInfo {
            TransformationComponent::InitializationInfo* transformationComponent {nullptr};
        } EntityInfo;

        /**
         * Creates new Entity.
         * Returns the id_ of the newly created entity.
         *
         * @param info a struct EntityInfo representing the information about entity to be created
         * @return the id_ of the newly created entity
         */
        Entity create_entity(EntityInfo &info);

        /**
         * Removes the entity with the given id_.
         *
         * @param entity an Entity to be removed.
         */
        void remove_entity(Entity entity);

        /**
         * Checks if the entity with the given id_ is alive.
         * Returns true if it's alive, otherwise false.
         *
         * @param entity a GameEntity
         * @return true if entity is alive, otherwise false
         */
        bool is_alive(Entity entity);
    }
}

