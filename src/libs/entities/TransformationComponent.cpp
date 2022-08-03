#include "TransformationComponent.h"
#include "../math/vectors/Vectors.h"
#include "../api/game_entities/GameTransformComponent.h"
#include "../api/game_entities/GameEntity.h"

// Since every entity must have a transformation component
// There's no need to keep track of generations etc. in here
namespace Pollentia::Entity { // Entities

    namespace {
        Utilities::Vector<Math::f32Vector3> positions;
        Utilities::Vector<Math::f32Vector4> rotations;
        Utilities::Vector<Math::f32Vector3> scales;
    }

    API::GameEntity::TransformationComponent create_transformation_component
    (
        const InitializationInfo& info,
        API::GameEntity::Entity entity
    )
    {
        assert(entity.is_valid());
        const Id::idType entity_index{Id::index(entity.get_id())};

        if (positions.size() > entity_index) {
            rotations[entity_index] = Math::f32Vector4(info.rotation);
            positions[entity_index] = Math::f32Vector3(info.position);
            scales[entity_index] = Math::f32Vector3(info.scale);
        } else {
            assert(positions.size() == entity_index);
            rotations.emplace_back(info.rotation);
            positions.emplace_back(info.position);
            scales.emplace_back(info.scale);
        }

        return API::GameEntity::TransformationComponent
        (
            API::GameEntity::tranformationId
                {
                    (Id::idType)positions.size() - 1
                }
        );
    }

    void remove_transformation_component(API::GameEntity::TransformationComponent component)
    {
        assert(component.is_valid());
    }
}