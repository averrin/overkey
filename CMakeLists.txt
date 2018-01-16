
# Sets the minimum required version of CMake needed to process this file.
cmake_minimum_required(VERSION 2.8.11)

# This command sets the name for the entire project.
project(overkey)

# These commands define variables that are used throughout other CMake files in this project.
set(overkey_ROOT ${CMAKE_CURRENT_LIST_DIR})
set(overkey_BIN_DIR ${overkey_ROOT}/bin)
set(overkey_LIB_DIR ${overkey_ROOT}/lib)
set(overkey_CMAKE_DIR ${overkey_ROOT}/cmake)
set(overkey_SUBMODULES_DIR ${overkey_ROOT}/submodules)

# Change where CMake should output compiled libraries and executables.
# This is based on preference, so these set() commands should be changed
# or removed.
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${overkey_LIB_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${overkey_BIN_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${overkey_BIN_DIR})

# Set the C++ standard version to C++11. On older versions of CMake the
# CMAKE_CXX_FLAGS must be changed instead.
set(CMAKE_CXX_STANDARD 11)
if(${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION} LESS 3.1)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

# This option allows the users of the project to define if libraries should be
# built as shared libraries. If a library is explicitly set to be built as
# static, then it won't be built as a shared library.
option(BUILD_SHARED_LIBS "Build libraries as shared unless explicitly static" ON)
if(BUILD_SHARED_LIBS)
    add_definitions(-DBUILD_SHARED_LIBS)
endif()

# Use solution folders. In Visual Studio this will place a solution within a folder.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
# Auto-generated files are placed in a "Generated" folder.
set_property(GLOBAL PROPERTY AUTOGEN_TARGETS_FOLDER "Generated")

# Export the commands CMake used to compile the project. This is useful for tools
# like Vim's YouCompleteMe.
set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")

# CMake FindPackage projects. These are libraries that CMake knows how
# to find automatically.
# More info: https://cmake.org/cmake/help/latest/command/find_package.html


# Search for CMake files in the cmake/ directory as well
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${overkey_CMAKE_DIR})

# This command will load and run CMake code in the 3rdParty.cmake file within
# the cmake/ folder. CMake is able to find this file because the
# CMAKE_MODULE_PATH variable was changed to include the cmake/ folder.
include(3rdParty)

# Specify to include the lib/ folder in the paths the linker should look for
# libraries. This command is usually not necessary.
link_directories(lib/)

# Adds the src/ directory to the build. This command expects that the src/
# subdirectory contains a CMakeLists.txt file. CMake processes that file
# before continuing processing this file.
add_subdirectory(src/)

# When installing, this command will place a .cmake file within the cmake/
# directory where the project will be installed. This .cmake file can be
# used by an outside project to reference the targets within this project.
#
# The outside project just has to include the .cmake file using the include()
# command, and then it can reference the targets defined in this project
# with a concatenation of the namespace and target name.
#
# For example, if this project builds a library foo, and the namespace is
# myproj, then the outside project can reference the library using myproj_foo
# in its CMake code, like so:
#
# include(myproj)
# target_link_libraries(otherProjectTarget myproj_foo)
#
install(EXPORT overkey NAMESPACE overkey_ DESTINATION cmake)
