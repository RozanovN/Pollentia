list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
include(FindPkgConfig)
include(FetchContent)

cmake_minimum_required(VERSION 3.21)
project(Pollentia)
set(CMAKE_CXX_STANDARD 20)


set(SOURCE_FILES src/libs/entities/Entity.cpp src/libs/entities/TransformationComponent.cpp)
add_library(${PROJECT_NAME} ${SOURCE_FILES})

#Find all external packages
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
find_package(Eigen3 3.4 REQUIRED NO_MODULE)

#GTest
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARY} Eigen3::Eigen gtest gmock)