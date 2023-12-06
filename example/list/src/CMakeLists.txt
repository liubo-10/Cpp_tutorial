include_directories (../include)

aux_source_directory (. SRC_LIST)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_compile_options(-std=c++11 -Wall) 
add_executable (main ${SRC_LIST})