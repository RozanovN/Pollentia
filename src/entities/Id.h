//
// Created by Nikolay on 2022-04-26.
//

#ifndef GAMEENGINE_ID_H
    #define GAMEENGINE_ID_H
    #define MAX_GENERATION 255
    #include <type_traits>
    #include "../definitions/CommonHeader.h"

    /**
     * Represents Id namespace.
     *
     * @version 1.0
     * @author Nikolay Rozanov
     */
    namespace GameEngine::Id {

        /**
         * By default idType uses 32 bit unsigned integers.
         */
        using idType = unsigned32int;

        /**
         * By default 3 bits are reserved for generation.
         */
        constexpr unsigned32int generationBits{3};

        /**
         * The bits that are not assigned to generationBits are always assigned to indexBits.
         */
        constexpr unsigned32int indexBits {sizeof(idType) * 8 - generationBits};

        /**
         * Shows the indexMask as an idType.
         */
        constexpr idType indexMask { (idType{1} << indexBits) - 1};

        /**
         * Shows the generationMask as an idType
         */
        constexpr idType generationMask { (idType{1} << generationBits) - 1};

        /**
         * Shows an invalid id.
         */
        constexpr idType InvalidIdMask {idType{(idType{1} << (sizeof(idType) * 8 - 1))}};

        using generationType = std::conditional_t<generationBits <= 16,
            std::conditional_t<generationBits <= 8, unsigned8bit, unsinged16int>, unsigned32int>;

        /**
         * Check if generationType requires more bits than generationBits has.
         */
        static_assert(sizeof(generationType) * 8 >= generationBits);

        /**
         * Checks if generationType size is not bigger than idType size.
         */
        static_assert(sizeof(idType) - sizeof(generationType) > 0);

        /**
         * Returns true if id is valid, otherwise false.
         *
         * @param id idType representing an id
         * @return true if id is valid, else false.
         */
        inline bool is_valid(idType id) {
            return id != InvalidIdMask;
        }

        /**
         * Returns the index part of the given id.
         *
         * @param id idType representing an id
         * @return the masked id
         */
        inline idType index(idType id) {
            return id & indexMask;
        }

        /**
         * Returns the generation part of the given id.
         *
         * @param id idType representing an id
         * @return the masked id
         */
        inline idType generation(idType id) {
            return (id >> indexBits) & generationMask;
        }

        /**
         * Makes new id generation.
         * Changes the given id's generation to a newly created generation.
         * Checks if new generation is less than MAX_GENERATION.
         *
         * @see MAX_GENERATION
         * @param id idType representing an id
         * @return
         */
        inline idType new_generation(idType id) {
            const idType generation {Id::generation(id) + 1};
            assert(generation < MAX_GENERATION);
            return index(id) | (generation << indexBits);
        }
}

#endif //GAMEENGINE_ID_H
