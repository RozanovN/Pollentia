#pragma once

#include "CommonEntityHeader.h"

namespace Pollentia {

//    #define INITIALIZATION_INFO(component) namespace component {struct InitializationInfo;}
//        INITIALIZATION_INFO(TransformationComponent);
//    #undef InitializationInfo

    namespace API::GameEntity {
        class Entity;
    }

    namespace Entity {
        struct InitializationInfo;
        /**
         * Represents Entity information.
         */
        struct EntityInfo {
            InitializationInfo* transformationComponent {nullptr};
        } EntityInfo;

        /**
         * Creates new Entity.
         * Returns the newly created entity.
         *
         * @param info a struct EntityInfo representing the information about entity to be created
         * @return an Entity object
         */
        API::GameEntity::Entity create_entity(struct EntityInfo &info);

        /**
         * Removes the given entity.
         *
         * @param entity an Entity to be removed.
         */
        void remove_entity(API::GameEntity::Entity entity);

        /**
         * Checks if the entity with the given id_ is alive.
         * Returns true if it's alive, otherwise false.
         *
         * @param entity a GameEntity
         * @return true if entity is alive, otherwise false
         */
        bool is_alive(API::GameEntity::Entity entity);
    }
}

