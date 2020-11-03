cmake_minimum_required(VERSION 3.4)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(lab03)

add_library(annealing STATIC
  ${CMAKE_CURRENT_SOURCE_DIR}/sources/annealing.cpp
)
add_executable(demo
  ${CMAKE_CURRENT_SOURCE_DIR}/sources/demo.cpp
)

target_include_directories(annealing
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_include_directories(demo
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(demo PUBLIC annealing)
