cmake_minimum_required(VERSION 3.8)

project(thread_mo_tst_app.bin)

set(THREAD_SRC_DIR ${CMAKE_SOURCE_DIR}/src/ThreadModule)

set(THR_MGR ${THREAD_SRC_DIR}/ThreadManager/ThreadManager.h 
            ${THREAD_SRC_DIR}/ThreadManager/IThreadManager.h 
            ${THREAD_SRC_DIR}/ThreadManager/ThreadManager.cpp)

set(THR_CLI ${THREAD_SRC_DIR}/ThreadClient/ThreadClient.h 
            ${THREAD_SRC_DIR}/ThreadClient/ThreadClient.cpp)

add_executable(${PROJECT_NAME} ${THREAD_SRC_DIR}/test_app.cpp)

target_sources(${PROJECT_NAME} PUBLIC ${THR_MGR})

target_sources(${PROJECT_NAME} PUBLIC ${THR_CLI})