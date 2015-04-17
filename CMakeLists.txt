cmake_minimum_required(VERSION 2.8.4)
project(cs261-DataStructures)

set(CMAKE_C_FLAGS "-std=c99")

add_executable(assignment0-0 "assignment0/simple.c")

add_executable(assignment1-0 "assignment1/Q0.c")
add_executable(assignment1-1 "assignment1/Q1.c")
add_executable(assignment1-2 "assignment1/Q2.c")
add_executable(assignment1-3 "assignment1/Q3.c")
add_executable(assignment1-4 "assignment1/Q4.c")
add_executable(assignment1-5 "assignment1/Q5.c")

set(assignment_2_test_FILES
    "assignment2/dynamicArray.h"
    "assignment2/dynamicArray.c"
    "assignment2/testDynArray.c"
)

set(assignment_2_calc_FILES
    "assignment2/dynamicArray.h"
    "assignment2/dynamicArray.c"
    "assignment2/calc.c"
)

add_executable(assignment2_test ${assignment_2_test_FILES})
add_executable(assignment2_calc ${assignment_2_calc_FILES})