cmake_minimum_required(VERSION 3.19)
project(MathResources)

set(CMAKE_CXX_STANDARD 20)
# src/Vector3D.cpp headers/Vector3D.h src/Vector4D.cpp headers/Vector4D.h
add_executable(MathResources main.cpp src/Vector2D.cpp headers/Vector2D.h src/Vector3D.cpp headers/Vector3D.h src/Vector4D.cpp headers/Vector4D.h Tester.cpp headers/Tester.h src/Matrix3.cpp headers/Matrix3.h src/Matrix4.cpp headers/Matrix4.h headers/transformation.h src/transformation.cpp)