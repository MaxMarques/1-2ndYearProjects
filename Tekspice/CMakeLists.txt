cmake_minimum_required(VERSION 3.16)

project (Nanotekspice CXX)

set(BIN_NAME nanotekspice)

add_executable(${BIN_NAME}
  main.cpp
  src/system.cpp
  src/error/error.cpp
  src/factory/factory.cpp
  src/parsing/parsing.cpp
  src/component/gates/AComponent.cpp
  src/component/gates/true.cpp
  src/component/gates/false.cpp
  src/component/gates/output.cpp
  src/component/gates/input.cpp
  )

include_directories(
  src/	
  src/error/	
  src/component/
  src/component/gates/
  src/parsing/
  src/factory/
  )

target_compile_options(${BIN_NAME} PRIVATE
  -W
  -Wall
  -Wextra
  -std=c++17
  -g
  )
