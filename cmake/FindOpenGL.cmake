include(CmakeVars)

set(FIND_OPENGL_PATH ${PACKAGES_PATH}/opengl)

find_path(OPENGL_INCLUDE_DIR glfw3.h
        PATH_SUFFIXES include
        PATHS ${FIND_OPENGL_PATH})

find_library(OPENGL_LIBRARY
        NAMES glfw3
        PATH_SUFFIXES lib
        PATHS ${FIND_OPENGL_PATH})