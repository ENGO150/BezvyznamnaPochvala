project(Test)
cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)

add_executable(Test
    src/main.cpp
)

find_package(GLEW REQUIRED)

target_link_libraries(Test GLEW::GLEW)
target_link_libraries(Test -lglfw)
target_link_libraries(Test -lGL)