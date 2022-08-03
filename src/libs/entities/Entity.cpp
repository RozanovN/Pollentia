#include "Entity.h"
#include "TransformationComponent.h"
#include "../api/game_entities/GameEntity.h"
#include "../api/game_entities/GameTransformComponent.h"

namespace Pollentia {
    namespace Entity {

        namespace {
            Utilities::Vector<Id::generationType> generations;
            Utilities::Deque<API::GameEntity::entityId> freeIds;
            Utilities::Vector<API::GameEntity::TransformationComponent> transformationComponents;
        }

        bool is_alive(API::GameEntity::Entity entity) {
            assert(entity.is_valid());
            const API::GameEntity::entityId id{entity.get_id()};
            const Id::idType index{Id::index(id)};
            assert(index < generations.size());
            assert(generations[index] == Id::generation(id));
            // checks if entity at the given index matches the generation of the given entity
            // if true, it's alive, otherwise the id_ was given to another entity and this entity no longer alive
            return (generations[index] == Id::generation(id) && transformationComponents[index].is_valid());
        }

        void remove_entity(API::GameEntity::Entity entity) {
            const API::GameEntity::entityId id{entity.get_id()};
            const Id::idType index{Id::index(id)};
            assert(is_alive(entity));
            if (is_alive(entity)) {
                remove_transformation_component(transformationComponents[index]);
                // populate with an invalid transformation component
                transformationComponents[index] = API::GameEntity::TransformationComponent{};
                freeIds.push_back(id);
            }
        }

        API::GameEntity::Entity create_entity(struct EntityInfo info) {
            assert(info.transformationComponent); // entities must have a transformation component
            if (!info.transformationComponent) {
                return API::GameEntity::Entity{};
            }
            API::GameEntity::entityId id;

            // If there are free ids left, assign a free id_ to the Entity
            if (freeIds.size() > Id::minimumDeletedElements) {
                id = freeIds.front();
                assert(!is_alive(API::GameEntity::Entity{id}));
                freeIds.pop_front();
                id = API::GameEntity::entityId{Id::new_generation(id)};
                ++generations[Id::index(id)];
            } else { //
                id = API::GameEntity::entityId{(Id::idType) generations.size()};
                generations.push_back(0);
                // every time a new entity is added to the end of the generations vector, a new default transformation
                // component is added to the end of transformationComponents vector.
                transformationComponents.emplace_back();// preferable to minimize the num of mem allocations with resize()
            }

            const API::GameEntity::Entity newEntity{id};
            const Id::idType index{Id::index(id)};

            // Add a transformation component
            assert(!transformationComponents[index].is_valid());
            transformationComponents[index] = create_transformation_component(*info.transformationComponent, newEntity);
            if (!transformationComponents[index].is_valid()) {
                return API::GameEntity::Entity{};
            }

            return newEntity;
        }
    }

    namespace API::GameEntity {

        TransformationComponent Entity::get_transformation_component() const {
            assert(Pollentia::Entity::is_alive(*this));
            const Id::idType index {Id::index(get_id())};
            return Pollentia::Entity::transformationComponents[index];
        }
    }
}