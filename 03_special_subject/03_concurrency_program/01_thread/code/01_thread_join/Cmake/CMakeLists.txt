cmake_minimum_required (VERSION 3.5)

project (demo)

message("------project:${PROJECT_NAME} complie begain------\n")

# 定义变量
# PROJECT_SOURCE_DIR 为Cmake所在目录
set(PROJECT_MAIN_PATH   ${PROJECT_SOURCE_DIR}/..)

# include 路径
include_directories(
    ${PROJECT_MAIN_PATH}/src
)

# src 源文件
# set (SRC_LIST ${PROJECT_SOURCE_DIR}/src/main.c)
aux_source_directory(${PROJECT_MAIN_PATH}/src  SRC_LIST1)
aux_source_directory (${PROJECT_MAIN_PATH}/src/CRC32 SRC_LIST2)

# output 路径
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_MAIN_PATH}/bin)

# pthread 库不是 Linux 系统默认的库
set(CMAKE_CXX_FLAGS -pthread)
message(STATUS "CMAKE_CXX_FLAGS = ${CMAKE_CXX_FLAGS}")

#find_package(Threads) # 引入外部依赖包
#add_executable(ProjectName main.cpp)
 
#target_link_libraries (${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT}) # 链接Thread库
# 或者下面这种方式
# target_link_libraries (${PROJECT_NAME} pthread)
# 注：使用 target_link_libraries 链接库时，需要在 add_executable 之后


# 生成可执行文件 myname可执行文件名字与源文件名无关
add_executable(myname  ${SRC_LIST1} ${SRC_LIST2})
