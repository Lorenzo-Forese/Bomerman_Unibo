cmake_minimum_required(VERSION 3.20)
project(Bomberman)

set(CMAKE_CXX_STANDARD 17)

# 1. Add the static flag to prevent the __imp_ error
add_definitions(-DPDC_STATIC_BUILD)

# 2. Tell CMake where to find the headers and libraries
include_directories(C:/msys64/mingw64/include)
link_directories(C:/msys64/mingw64/lib)

# 3. Add all your source files
add_executable(Bomberman
        main.cpp
        Ai.cpp
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
target_include_directories(Bomberman PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        C:/msys64/mingw64/include
)
# 4. Link the library directly
target_link_libraries(Bomberman pdcurses)