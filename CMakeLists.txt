cmake_minimum_required(VERSION 3.5)

set(APP_NAME SCPlayer)
project(${APP_NAME} LANGUAGES CXX VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(INC_DIR ${PROJECT_SOURCE_DIR}/3rd_libs/SDL2/include)

if(${CMAKE_SIZEOF_VOID_P} EQUAL 4)
    set(LINK_DIR ${PROJECT_SOURCE_DIR}/3rd_libs/SDL2/lib/x86)
else()
    set(LINK_DIR ${PROJECT_SOURCE_DIR}/3rd_libs/SDL2/lib/x64)
endif()

set(SRC_FILE_LIST
    main.cpp scapplication.cpp scwindow.cpp
    )
configure_file(SCPlayerConfig.h.in SCPlayerConfig.h)
include_directories(${INC_DIR})
link_directories(${LINK_DIR})

#add_subdirectory(3rd_libs/SDL2)

add_executable(${APP_NAME} ${SRC_FILE_LIST})

target_include_directories(${APP_NAME} PUBLIC "{PROJECT_BINARY_DIR}")
target_link_libraries(${APP_NAME} SDL2 SDL2main)
