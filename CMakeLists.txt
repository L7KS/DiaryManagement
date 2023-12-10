cmake_minimum_required(VERSION 3.26)
project(DiaryManagement)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(DiaryManagement
        main.c
        main.h
        README.md
        cell.h
        cell.c
        list.c
        list.h
        timer.c)
