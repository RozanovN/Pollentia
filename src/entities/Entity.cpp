//
// Created by Nikolay on 2022-04-28.
//

#include "Entity.h"
#include "../api/GameEntity.h"

namespace GameEngine::GameEntity {

    namespace {
        Utilities::vector<Id::generationType> generations;
        Utilities::deque<entityId> freeIds;
    }

    bool is_alive(Entity entity) {
        assert(entity.is_valid());
        const entityId id {entity.get_id()};
        const Id::idType index{Id::index(id)};
        assert(index < generations.size());
        assert(generations[index] == Id::generation(id));
        // checks if entity at the given index matches the generation of the given entity
        // if true, it's alive, otherwise the id_ was given to another entity and this entity no longer alive
        return (generations[index] == Id::generation(id));
    }

    void remove_entity(Entity entity) {
        const entityId id {entity.get_id()};
        const Id::idType index {Id::index(id)};
        assert(is_alive(entity));
        if (is_alive(entity)) {
            freeIds.push_back(id);
        }
    }

    Entity create_entity(EntityInfo info) {
        assert(info.transformationComponent); // entities must have a transformation component
        if (!info.transformationComponent) {
            return Entity{};
        }
        entityId id;

        // If there are free ids left, assign a free id_ to the Entity
        if (freeIds.size() > Id::minimumDeletedElements) {
            id = freeIds.front();
            assert(!is_alive(Entity{id}));
            freeIds.pop_front();
            id = entityId {Id::new_generation(id)};
            ++generations[Id::index(id)];
        } else { //
            id = entityId {(Id::idType)generations.size()};
        }

        const Entity newEntity {id};
        const Id::idType index {Id::index(id)};

        return newEntity;
    }
}