cmake_minimum_required(VERSION 3.20)

project(nonlinear-class-B-report)

include_directories(./include)

add_executable(report1-Deterministic src/report1-Deterministic.cpp)
add_executable(report1-Nondeterministic src/report1-Nondeterministic.cpp)

