# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.5)

# Set the project name
project (Psycho)

# Set the C++ standard version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    src/models/TetrisBoard.cpp
    src/models/Tetromino.cpp
    src/models/MoveableTetromino.cpp
    src/simulation/InputSequence.cpp
    src/constants/Tetrominos.cpp
    src/main.cpp
)

# Add an executable with the above sources
add_executable(Psycho ${SOURCES})

# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
target_include_directories(Psycho
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)