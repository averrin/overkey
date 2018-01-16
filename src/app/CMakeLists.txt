
cmake_minimum_required(VERSION 2.8.11)

# This variable is used to make it easy to copy-paste this entire file for
# use in another project.
set(TARGET overkey)

# All header files should go here.
set(HEADERS
    
)

# All source files should go here.
set(SOURCES
    ${overkey_LIB_DIR}/format.cc
    main.cpp
)
# Add the executable to the build using the headers and sources.
add_executable(${TARGET} ${HEADERS} ${SOURCES})

# Add include directories here.
target_include_directories(${TARGET} PUBLIC

)

# Add depenency libraries or CMake targets here.
target_link_libraries(${TARGET}
    hotkeys
)

# Add project-specific compiler preprocessor variables here.
target_compile_definitions(${TARGET} PUBLIC )

# Add compiler flags to the following COMPILE_FLAGS variable.
set(COMPILE_FLAGS "")
if(COMPILE_FLAGS)
    set_target_properties(${TARGET} PROPERTIES COMPILE_FLAGS ${COMPILE_FLAGS})
endif()

# When using an MSVC compiler (used by Visual Studio), you can link the
# C Runtime Library as a static library.
#if(MSVC)
#    set_target_properties(${TARGET} PROPERTIES COMPILE_FLAGS "${COMPILE_FLAGS} /MT")
#endif()

# Add linker flags here.
set_target_properties(${TARGET} PROPERTIES LINK_FLAGS "")

# Place this target into a solution folder.
set_target_properties(${TARGET} PROPERTIES FOLDER "overkey")

# Add this project to the list of installed targets. When the install command
# is invoked, this project will be placed in the installation directory. The
# EXPORT part of this commands will cause CMake to allow this target to
# be used by outside projects.
install(TARGETS ${TARGET}
    EXPORT overkey
    COMPONENT bin
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib/static
)
