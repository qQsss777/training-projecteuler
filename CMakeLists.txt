cmake_minimum_required(VERSION 3.21)
project(MonProjetCatch2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Catch2 REQUIRED)

# Liste des fichiers sources de tests dans src/
set(TEST_SOURCES
    src/main.cpp
    src/007.cpp
)

add_executable(test_runner ${TEST_SOURCES})

target_link_libraries(test_runner PRIVATE Catch2::Catch2WithMain)
