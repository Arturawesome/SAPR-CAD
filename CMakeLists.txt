cmake_minimum_required(VERSION 3.10)

project(SAPR VERSION 1.0 LANGUAGES CXX)

set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(MESH_DIR ${SRC_DIR}/mesh)
set(METHODS_DIR ${SRC_DIR}/methods)
set(TASKS_DIR ${SRC_DIR}/tasks)


include_directories(${SRC_DIR}/include)

find_package(Python3 REQUIRED COMPONENTS Development)
include_directories(${Python3_INCLUDE_DIRS})
include_directories(/usr/lib/python3.12/site-packages/numpy/_core/include)

add_executable(SAPR ${SRC_DIR}/main.cpp )
target_link_libraries(SAPR PRIVATE ${Python3_LIBRARIES})

target_sources(SAPR PUBLIC
    ${MESH_DIR}/Mesh1D.cpp
    ${MESH_DIR}/LinearMesh1D.cpp

    # ${MESH_DIR}/Mesh2D.cpp
    # ${MESH_DIR}/RectangleMesh2D.cpp

    ${METHODS_DIR}/Method1D.cpp
    ${METHODS_DIR}/FiniteDifferenceMethod1D.cpp

    ${TASKS_DIR}/HeatTask1D.cpp
    ${TASKS_DIR}/TransportTask1D.cpp
)
