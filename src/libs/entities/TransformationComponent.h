#pragma once

#include "CommonEntityHeader.h"


namespace Pollentia {

    namespace API::GameEntity {
        DEFINE_ID_TYPE(entityId);
        class TransformationComponent;
        class Entity;
    }

    namespace Entity {

        /**
         * Represents the initialization information for the Transformation Components
         */
        struct InitializationInfo {
            float position[3]{};
            // a quaternion
            float rotation[4]{};
            // 1 is default scale
            float scale[3]{1.f, 1.f, 1.f};
        };

        /**
         * Creates new transformation component.
         *
         * @param info an InitializationInfo struct representing initialization information
         * @param entity an Entity object that will own the new transformation component
         * @return a TransformationComponent representing the the newly created transformation component object
         */
        API::GameEntity::TransformationComponent create_transformation_component
        (
            struct InitializationInfo info,
            API::GameEntity::Entity entity
        );

        /**
         * Removes the given transformation component.
         *
         * @param transformationComponent a TransformationComponent object to be deleted
         */
        void remove_transformation_component(API::GameEntity::TransformationComponent transformationComponent);
    }
}

