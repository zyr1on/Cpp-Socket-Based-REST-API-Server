cmake_minimum_required(VERSION 3.10)

project(webserver )

set(CMAKE_CXX_STANDARD 11)
include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/include)


link_directories(include_directories(${CMAKE_SOURCE_DIR}/lib))

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

file(GLOB_RECURSE SRC_FILES
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)
add_executable(webserver  ${SRC_FILES})
target_link_libraries(webserver  ws2_32 ssl crypto)


