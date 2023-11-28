file(GLOB_RECURSE SOURCES "*.cpp")     # Recursively find all .cpp files in src

add_executable(Psycho ${SOURCES})   # Create an executable with all source files

# If you have specific libraries to link against:
# target_link_libraries(MyProject PRIVATE someLibrary)
