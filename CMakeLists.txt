cmake_minimum_required(VERSION 3.2)
set(PROJECT_NAME "Paleyev_Daniel_ASearch")
project(${PROJECT_NAME})


if (${MINGW})
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O0 -Wall -Wextra -static -static-libgcc -static-libstdc++")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O0 -Wall -Wextra")
endif()

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

enable_testing()

add_subdirectory(Src)