cmake_minimum_required(VERSION 3.28)
project(TaskMenager)

set(CMAKE_CXX_STANDARD 20)

add_executable(TaskMenager main.cpp
        process.h
        process.cpp
        main.cpp
        manager.cpp
        manager.h
        utils.h
        anomaly_detector.cpp
        anomaly_detector.h)
