//
// Created by Nikolay on 2022-04-28.
//

#ifndef GAMEENGINE_ENTITY_H
    #define GAMEENGINE_ENTITY_H
    #include "CommonEntityHeader.h"

    namespace GameEngine {

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
             * Returns the id of the newly created entity.
             *
             * @param info a struct EntityInfo representing the information about entity to be created
             * @return the id of the newly created entity
             */
            Entity create_entity(EntityInfo &info);

            /**
             * Removes the entity with the given id.
             *
             * @param entity an Entity to be removed.
             */
            void remove_entity(Entity entity);

            /**
             * Checks if the entity with the given id is alive.
             * Returns true if it's alive, otherwise false.
             *
             * @param entity a GameEntity
             * @return true if entity is alive, otherwise false
             */
            bool is_alive(Entity entity);
        }
    }
#endif //GAMEENGINE_ENTITY_H
