cmake_minimum_required(VERSION 3.9)
project (basic_project)
add_executable(vector_O0 tarefa5.cpp experiment.cpp log.cpp pow3.cpp pow3mult.cpp sqrt.cpp sum.cpp)
target_compile_definitions(vector_O0 PUBLIC O0)
