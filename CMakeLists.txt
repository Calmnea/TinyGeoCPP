# TinyGeo CMakeList
cmake_minimum_required(VERSION 2.8)
project(TinyGeo)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11 -O2 -g")

aux_source_directory(. PROGRAM_SOURCE)
add_library(tinygeo STATIC ${PROGRAM_SOURCE} geo_base.h)