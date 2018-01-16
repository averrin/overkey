
# This file is used to add all the subprojects to the build tree. The order
# in which the projects are added matters. Place all dependencies before
# parent projects.

# Include the src/ folder so that the projects can include each other's files.
include_directories(.)

add_subdirectory(hotkeys)
add_subdirectory(app)
