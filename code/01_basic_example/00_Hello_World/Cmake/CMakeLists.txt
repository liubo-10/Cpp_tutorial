cmake_minimum_required (VERSION 3.5)

project(demo)


message("------project:${PROJECT_NAME} complie begain------\n")

# 定义变量
set(PROJECT_MAIN_PATH   ${PROJECT_SOURCE_DIR}/..)

# include
include_directories(
    ${PROJECT_MAIN_PATH}/include
)

# src 源文件
aux_source_directory(${PROJECT_MAIN_PATH}/src  SRC_LIST)

# output 路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_MAIN_PATH}/bin)

# 生成可执行文件 myname可执行文件名字与源文件名无关
add_executable(myname  ${SRC_LIST})

