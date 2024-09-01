cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 17)

# Add the include directory
include_directories(include)

add_executable(MyProject src/main.cpp src/Database.cpp)

# Optionally, if you prefer a more modern approach, you can use target_include_directories
# target_include_directories(MyProject PRIVATE include)