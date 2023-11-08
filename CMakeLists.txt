cmake_minimum_required(VERSION 3.26)
project(DiaryManagement)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(DiaryManagement
        fichier.c
        fichier.h
        README.md)
