cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME yamlcpp-check) 


set(CMAKE_CXX_STANDARD 20)

project(${PROJECT_NAME})

# set(Boost_USE_STATIC_LIBS      ON)
set(Boost_USE_MULTITHREADED    ON)
set(Boost_USE_STATIC_RUNTIME   OFF)

find_package(Boost COMPONENTS system REQUIRED)
find_package(OpenMP)
if (OPENMP_FOUND)
    message(STATUS ${OpenMP_VERSION} "OpenMP found version ( ${OPENMP_VERSION}) ")
    # list(APPEND CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    # list(APPEND CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

link_directories(${Boost_LIBRARY_DIRS})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/out)

set(SOURCE main.cpp)


# add_executable(${PROJECT_NAME} ${SOURCE})
# target_link_libraries(${PROJECT_NAME} Boost::boost boost_system boost_filesystem)

# add_executable(${PROJECT_NAME}_1 main_future.cpp)
# add_executable(algo_test lomuto_partition.cpp)
# add_executable(algo_test selection_sort.cpp)
add_executable(algo_test bad_quick_sort.cpp)