
# This CMake file is used to download and build the third party dependencies
# needed by this project. It is possible to obtain depencies from an archive
# file, a git, mercurial, or even an svn repository, and these dependent
# projects can either have CMake-based or script-based builds.
#
# To support all of that, this file uses CMake's ExternalProject module. This
# provides a highly configurable way to obtain third party dependencies.
#
# For more advanced configuration options see
# https://cmake.org/cmake/help/latest/module/ExternalProject.html
#
# The one shortcoming from this method is that it expects to the third
# party dependency library to be in a specific location and have a specific
# name. You will know this is the case because you will get a linker error
# when buildng the project.
#
# Fortunately, the fix is easy: just change the path that comes after
# IMPORTED_LOCATION for the library that produced the linker error.

include(ExternalProject)

# Set the installation prefix of all third party dependencies. After a build,
# the libraries, include directories, and executables of all third party
# projects will be placed in this directory.
set(THIRD_PARTY_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/lib
    CACHE PATH "Directory to install 3rd party dependencies"
)

# Add the include/ subdirectory of the third party installation directory
# to the list of directories to search for header files. This directory will
# exist after the third party dependencies are built.
include_directories(${overkey_LIB_DIR}/include)

# Third party dependencies start after this line. They are ordered so that
# dependencies of parent projects appear first in the file.


