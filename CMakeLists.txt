cmake_minimum_required(VERSION 3.16)# 版本要求 没有强制要求，一般差不多就行了

project(demo) # 工程名字

set(this_project_direction ${CMAKE_CURRENT_SOURCE_DIR})# 这是一句废话，本来可以直接用这个内置变量，这里为了展示设置变量的方式 这里把this_project_direction设置为当前工程的路径

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${this_project_direction}/static)# 设置内置变量，表明静态库存放的地址
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${this_project_direction}/dynamic)# 设置内置变量，表明动态库存放的地址
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${this_project_direction}/bin)# 设置内置变量，表明可执行文件的地址

message("this_project_direction is ${this_project_direction}")# 信息打印
# 头文件的地址 相当于gcc编译时的-I
include_directories(
    ${this_project_direction}/base
    ${this_project_direction}/includes1
    ${this_project_direction}/includes2
)
#信息打印
message("include dirs is : ${this_project_direction}/base, ${this_project_direction}/includes1 and ${this_project_direction}/includes2.")
#信息打印
message("enter ${this_project_direction}/files1 dir...")
#进入层demo/files1
add_subdirectory(${this_project_direction}/files1)

message("enter ${this_project_direction}/files2 dir...")
#进入层demo/files2
add_subdirectory(${this_project_direction}/files2)

#添加源文件
aux_source_directory(${this_project_direction} main_src)
message("src dirs is ${main_src}.")

add_executable(main ${main_src}) #添加可执行文件，最终会生成main这个可执行文件
#target_link_directories(main PUBLIC ${this_project_direction}/static)
target_link_libraries(main max_score mean)# main依赖的库，这两个库是files1和files2目录下的CMakeLists.txt生成的，这里相当于gcc编译时候的-L -l(库路径 库名字)
#link_directories(${this_project_direction}/static)
