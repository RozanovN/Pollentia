#pragma once

#define USE_STD_VECTOR 1
#define USE_STD_DEQUE 1

#if USE_STD_VECTOR
    #include <vector>
    namespace Pollentia::Utilities {
        template<typename T>
        using Vector = typename std::vector<T>;
    }
#else
    namespace Pollentia::Utilities {
        /// @todo implement custom vector and Deque

    }
#endif

#if USE_STD_DEQUE
    #include <deque>
    namespace Pollentia::Utilities {
        template<typename T>
        using Deque = typename std::deque<T>;
    }
#endif



