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

# ============================================================================
# COPY ASSETS FOLDER TO BUILD DIRECTORY
# ============================================================================
# This tells CMake to copy the entire assets/ folder into the build directory
add_custom_command(TARGET CardGame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets
    ${CMAKE_BINARY_DIR}/assets
    COMMENT "Copying assets folder to build directory"
)

# ============================================================================
# OPTIONAL: Print the working directory (for debugging)
# ============================================================================
# Uncomment this line if you want to see where files are being looked for
# add_compile_definitions(DEBUG_ASSET_PATH="${CMAKE_BINARY_DIR}/assets")
