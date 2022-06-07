#pragma once

#define USE_STD_VECTOR 1
#define USE_STD_DEQUE 1

#if USE_STD_VECTOR
    #include <vector>
    namespace GameEngine::Utilities {
        template<typename T>
        using vector = typename std::vector<T>;
    }
#endif

#if USE_STD_DEQUE
    #include <deque>
    namespace GameEngine::Utilities {
        template<typename T>
        using deque = typename std::deque<T>;
    }
#endif

namespace GameEngine::Utilities {
    /// @todo implement custom vector and deque
}

