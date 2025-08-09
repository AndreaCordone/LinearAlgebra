cmake_minimum_required(VERSION 3.10)
project(LinAlgebra)

# Set C++ standard
set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable debug symbols and warnings
set(CMAKE_BUILD_TYPE Debug)
add_compile_options(-Wall -Wextra -g)

add_executable(LinAlgebra main.cpp Matrix.cpp MatrixArithmetic.cpp SpecialMatrix.cpp MatrixOperation.cpp LUPQ.cpp LUP.cpp CH.cpp)

# Require C++17 for this target
target_compile_features(LinAlgebra PRIVATE cxx_std_17)