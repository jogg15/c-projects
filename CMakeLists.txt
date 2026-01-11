cmake_minimum_required(VERSION 3.28.3)
project(calc C)

set(CMAKE_C_STANDARD 11)
set(PROGRAMS bmi calc kpn average)

foreach(p ${PROGRAMS})
    add_executable(${p} projects/${p}.c)
endforeach()

add_custom_target(build ALL DEPENDS ${PROGRAMS})