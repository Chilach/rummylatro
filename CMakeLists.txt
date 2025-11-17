cmake_minimum_required(VERSION 3.16)
project(CardGame)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Generate compile_commands.json for LSP (clangd)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find SFML library on the system
find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system)

# Define source files
set(SOURCES
    src/main.cpp
    src/Card.cpp
)

# Create executable from sources
add_executable(CardGame ${SOURCES})

# Tell compiler where to find header files
target_include_directories(CardGame PRIVATE include/)

# Link SFML libraries
target_link_libraries(CardGame sfml-graphics sfml-window sfml-system)
