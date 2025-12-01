# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Define the project name and specify the programming language (C++)
project(Bomberman CXX)

# Set the C++ standard (ensure C++11 or newer for <random>)
set(CMAKE_CXX_STANDARD 17)

# Find the ncurses package (this will locate the library)
find_package(Curses REQUIRED)

# Add the executable target (list all your source files here)
add_executable(Bomberman
    main.cpp                # Main source file
    Ai.cpp                  # Other source files
    finestre.cpp
    inGame.cpp
    impostazioni.cpp
    leaderboard.cpp
    mapparandom.cpp
    movimento.cpp
    rappresentazione.cpp
    selezioni.cpp
    lang.cpp
)

# Include directories where the header files are located (adjust if needed)
target_include_directories(Bomberman PUBLIC
    ${PROJECT_SOURCE_DIR}/include  # Assuming headers are in the "include" directory
)

# Link the ncurses library to the executable
target_link_libraries(Bomberman PRIVATE
    ${CURSES_LIBRARIES}  # This will link the ncurses library
)

# Optionally, if you want to enable Debug/Release builds, add this:
# set(CMAKE_BUILD_TYPE Release)  # Uncomment for release builds
