cmake_minimum_required(VERSION 3.8)

project(name_cntrl_tst_app.bin)

set(NAME_CONTROLLER_SRC ${CMAKE_SOURCE_DIR}/src/NameController)

set(NAME_CLI ${NAME_CONTROLLER_SRC}/NameClient/NameCli.h 
             ${NAME_CONTROLLER_SRC}/NameClient/INameCli.h  
             ${NAME_CONTROLLER_SRC}/NameClient/NameCli.cpp)

set(NAME_CNTRL ${NAME_CONTROLLER_SRC}/NameController/NameCntrl.h 
               ${NAME_CONTROLLER_SRC}/NameController/INameCntrl.h 
               ${NAME_CONTROLLER_SRC}/NameController/NameCntrl.cpp)

add_executable(${PROJECT_NAME} ${NAME_CONTROLLER_SRC}/test_app.cpp)

target_sources(${PROJECT_NAME} PUBLIC ${NAME_CLI})

target_sources(${PROJECT_NAME} PUBLIC ${NAME_CNTRL})