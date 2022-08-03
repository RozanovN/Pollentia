list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
include(FindPkgConfig)

cmake_minimum_required(VERSION 3.21)
project(Pollentia)
set(CMAKE_CXX_STANDARD 20)


set(SOURCE_FILES src/libs/entities/Entity.cpp src/libs/entities/TransformationComponent.cpp)
add_library(${PROJECT_NAME} ${SOURCE_FILES})

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

find_package(Eigen3 3.4 REQUIRED NO_MODULE)


target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARY} Eigen3::Eigen)