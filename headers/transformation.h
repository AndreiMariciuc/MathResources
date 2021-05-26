//
// Created by Mariciuc Andrei on 5/26/2021.
//

#ifndef MATHRESOURCES_TRANSFORMATION_H
#define MATHRESOURCES_TRANSFORMATION_H

#include "Matrix3.h"
#include "Vector2D.h"
#include "Matrix4.h"

const double PI = atan(1) * 4;
//Transformation matrices in 2D
Matrix3 translate(const Vector2D& translateVector);
Matrix3 translate(float tx, float ty);

Matrix3 scale(const Vector2D& scaleVector);
Matrix3 scale(float sx, float sy);

Matrix3 rotate(float angle);

//Transformation matrices in 3D

Matrix4 translate(const Vector3D& translateVector);
Matrix4 translate(float tx, float ty, float tz);

Matrix4 scale(const Vector3D& scaleVector);
Matrix4 scale(float sx, float sy, float sz);

Matrix4 rotateX(float angle);
Matrix4 rotateY(float angle);
Matrix4 rotateZ(float angle);

#endif //MATHRESOURCES_TRANSFORMATION_H
