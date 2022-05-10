//
// Created by Nikolay on 2022-04-26.
//

#ifndef GAMEENGINE_ID_H
    #define GAMEENGINE_ID_H
    #include <type_traits>
    #include "../definitions/CommonHeader.h"
    #define MAX_GENERATION (((unsinged64int)1 << internal::indexBits) - 1)

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

        // must not be accessed by other files
        namespace internal {
            /**
             * By default 3 bits are reserved for generation.
             */
            constexpr unsigned32int generationBits {3};

            /**
             * The bits that are not assigned to generationBits are always assigned to indexBits.
             */
            constexpr unsigned32int indexBits {sizeof(idType) * 8 - generationBits};

            /**
             * Shows the indexMask as an idType.
             */
            constexpr idType indexMask {(idType{1} << indexBits) - 1};

            /**
             * Shows the generationMask as an idType
             */
            constexpr idType generationMask {(idType{1} << generationBits) - 1};
        }

        /**
         * Shows an invalid id.
         */
        constexpr idType invalidIdMask {idType(-1)};

        /**
         * Represents the required minimum of id removals to allows reassigning available slots in the array.
         */
        constexpr unsigned32int minimumDeletedElements {1024};

        /// @todo add documentation for generation bits
        using generationType = std::conditional_t<internal::generationBits <= 16,
            std::conditional_t<internal::generationBits <= 8, unsigned8bit, unsinged16int>, unsigned32int>;

        /**
         * Check if generationType requires more bits than generationBits has.
         */
        static_assert(sizeof(generationType) * 8 >= internal::generationBits);

        /**
         * Checks if generationType size is not bigger than idType size.
         */
        static_assert(sizeof(idType) - sizeof(generationType) > 0);

        /**
         * Returns true if id is valid, otherwise false.
         *
         * @param id an unsigned integer representing an id
         * @return true if id is valid, else false.
         */
        constexpr bool is_valid(idType id) {
            return id != invalidIdMask;
        }

        /**
         * Returns the index part of the given id.
         *
         * @param id an unsigned integer representing an id
         * @return an unsigned integer representing the masked id
         */
        constexpr idType index(idType id) {
            // check if index part is valid
            assert((id & internal::indexMask)  != internal::indexMask);
            return id & internal::indexMask;
        }

        /**
         * Returns the generation part of the given id.
         *
         * @param id an unsigned integer representing an id
         * @return an unsigned integer representing the masked id
         */
        constexpr idType generation(idType id) {
            return (id >> internal::indexBits) & internal::generationMask;
        }

        /**
         * Makes new id generation.
         * Changes the given id's generation to a newly created generation.
         * Checks if new generation is less than MAX_GENERATION.
         *
         * @see MAX_GENERATION
         * @param id an unsigned integer representing an id
         * @return an unsigned integer representing the masked id with the new generation
         */
        constexpr idType new_generation(idType id) {
            const idType generation {Id::generation(id) + 1};
            assert(generation < MAX_GENERATION);
            return index(id) | (generation << internal::indexBits);
        }

    }

    #if _DEBUG
        namespace internal {
            struct BaseId {
                constexpr explicit baseId(idType) : _id{id} {}
                constexpr operator idType() const {return _id;}
                private:
                    idType _id;
            };
        }
        #define DEFINE_ID_TYPE(name) using name struct name final : id:internal::BaseId { \
                constexpr explicit name(Id::idType id) : BaseId {id} {};                  \
                constexpr name() : BaseId{0} {}                                           \
           };
    #else
        #define DEFINE_ID_TYPE(name) using name = Id::idType;
    #endif

#endif //GAMEENGINE_ID_H
