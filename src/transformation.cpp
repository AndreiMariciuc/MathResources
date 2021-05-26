//
// Created by Mariciuc Andrei on 5/26/2021.
//

#include "../headers/transformation.h"

//Transformation matrices in 2D
Matrix3 translate(const Vector2D &translateVector) {

    return translate(translateVector.x, translateVector.y);
}

Matrix3 translate(float tx, float ty) {
    Matrix3 translateMatrix;
    translateMatrix.at(0, 2) = tx;
    translateMatrix.at(1, 2) = ty;
    return translateMatrix;
}

Matrix3 scale(const Vector2D &scaleVector) {
    return scale(scaleVector.x, scaleVector.y);
}

Matrix3 scale(float sx, float sy) {
    Matrix3 scaleMatrix;
    scaleMatrix.at(0, 0) = sx;
    scaleMatrix.at(1, 1) = sy;
    return scaleMatrix;
}

static double fromAngleToRad(float angle) {
    return angle * PI / 180;
}

Matrix3 rotate(float angle) {
    Matrix3 rotateMatrix;
    double teta = fromAngleToRad(angle);
    rotateMatrix.at(0, 0) = rotateMatrix.at(1, 1) = (float) cos(teta);
    rotateMatrix.at(0, 1) = (float) -sin(teta);
    rotateMatrix.at(1, 0) = -rotateMatrix.at(0, 1);
    return rotateMatrix;
}

Matrix4 translate(const Vector3D& translateVector) {
    return translate(translateVector.x, translateVector.y, translateVector.z);
}

Matrix4 translate(float tx, float ty, float tz) {
    Matrix4 translateMatrix;
    translateMatrix.at(0, 3) = tx;
    translateMatrix.at(1, 3) = ty;
    translateMatrix.at(2, 3) = tz;
    return translateMatrix;
}

Matrix4 scale(const Vector3D& scaleVector) {
    return scale(scaleVector.x, scaleVector.y, scaleVector.z);
}

Matrix4 scale(float sx, float sy, float sz) {
    Matrix4 scaleMatrix;
    scaleMatrix.at(0, 0) = sx;
    scaleMatrix.at(1, 1) = sy;
    scaleMatrix.at(2, 2) = sz;
    return scaleMatrix;
}

Matrix4 rotateX(float angle) {
    double teta = fromAngleToRad(angle);
    Matrix4 rotateMatrix;
    rotateMatrix.at(1, 1) = rotateMatrix.at(2, 2) = (float) cos(teta);
    rotateMatrix.at(2, 1) = (float) sin(teta);
    rotateMatrix.at(1, 2) = -rotateMatrix.at(2, 1);
    return rotateMatrix;
}

Matrix4 rotateY(float angle) {
    double  teta = fromAngleToRad(angle);
    Matrix4 rotateMatrix;
    rotateMatrix.at(0, 0) = rotateMatrix.at(2, 2) = (float) cos(teta);
    rotateMatrix.at(2, 0) = (float) -sin(teta);
    rotateMatrix.at(0, 2) = -rotateMatrix.at(2, 0);
    return rotateMatrix;
}

Matrix4 rotateZ(float angle) {
    double teta = fromAngleToRad(angle);
    Matrix4 rotateMatrix;
    rotateMatrix.at(0, 0) = rotateMatrix.at(1, 1) = (float) cos(teta);
    rotateMatrix.at(0, 1) = (float) -sin(teta);
    rotateMatrix.at(1, 0) = -rotateMatrix.at(0, 1);
    return rotateMatrix;
}


