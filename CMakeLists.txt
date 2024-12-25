cmake_minimum_required(VERSION 3.10)

project(SAPR VERSION 1.0 LANGUAGES CXX)

set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(MESH_DIR ${SRC_DIR}/mesh)
set(METHODS_DIR ${SRC_DIR}/methods)
set(TASKS_DIR ${SRC_DIR}/tasks)


include_directories(${SRC_DIR}/include)
include_directories(${MESH_DIR}/include)
include_directories(${METHODS_DIR}/include)
include_directories(${TASKS_DIR}/include)



add_executable(SAPR ${SRC_DIR}/main.cpp )


target_sources(SAPR PUBLIC
    ${MESH_DIR}/Mesh2D.cpp
    ${MESH_DIR}/RectangleMesh2D.cpp
    ${METHODS_DIR}/Method2D.cpp
    ${METHODS_DIR}/ImplicitMethod2D.cpp
    ${TASKS_DIR}/HeatTask2D.cpp
)
