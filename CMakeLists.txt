cmake_minimum_required(VERSION 3.21)
project(URLConvertToNew C)

set(CMAKE_C_STANDARD 99)

add_executable(URLConvertToNew main.c URLEnDecode.h URLEnDecode.c utils.h utils.c)
