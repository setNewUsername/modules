cmake_minimum_required(VERSION 3.8)

project(thread_mo_tst_app.bin)

set(THREAD_SRC_DIR ${CMAKE_SOURCE_DIR}/src)

add_executable(${PROJECT_NAME} ${THREAD_SRC_DIR}/ThreadModule/test_app.cpp)