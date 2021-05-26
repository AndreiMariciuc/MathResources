//
// Created by Mariciuc Andrei on 5/26/2021.
//

#include "../headers/Matrix4.h"
#include "../headers/Matrix3.h"

float &Matrix4::at(int i, int j) {
    return matrixData[i + j * ORDER4];
}

const float &Matrix4::at(int i, int j) const {
    return matrixData[i + j * ORDER4];
}

Matrix4 &Matrix4::operator=(const Matrix4 &matrix4) {
    for (int i = 0; i < ORDER4; i++)
        for (int j = 0; j < ORDER4; j++)
            this->at(i, j) = matrix4.at(i, j);
    return *this;
}

Matrix4 Matrix4::operator*(float scalar) const {
    Matrix4 matrix4;
    for (int i = 0; i < ORDER4; i++)
        for (int j = 0; j < ORDER4; j++)
            matrix4.at(i, j) = at(i, j) * scalar;
    return matrix4;
}

Matrix4 Matrix4::operator*(const Matrix4 &matrix4) const {
    Matrix4 resultMatrix;
    for (int i = 0; i < ORDER4; i++)
        for (int j = 0; j < ORDER4; j++) {
            resultMatrix.at(i, j) = 0;
            for (int k = 0; k < ORDER4; k++)
                resultMatrix.at(i, j) += at(i, k) * matrix4.at(k, j);
        }
    return resultMatrix;
}

static float calculateResult(const float v[], int line, Matrix4 matrix4) {
    float result = 0;
    for (int k = 0; k < ORDER4; k++)
        result += v[k] * matrix4.at(line, k);
    return result;
}

Vector4D Matrix4::operator*(const Vector4D &vector4D) const {
    Vector4D resultVector;
    float v[] = {vector4D.x, vector4D.y, vector4D.z, vector4D.w};
    resultVector.x = calculateResult(v, 0, *this);
    resultVector.y = calculateResult(v, 1, *this);
    resultVector.z = calculateResult(v, 2, *this);
    resultVector.w = calculateResult(v, 3, *this);
    return resultVector;
}

Matrix4 Matrix4::operator+(const Matrix4 &matrix4) const {
    Matrix4 resultMatrix;
    for (int i = 0; i < ORDER4; i++)
        for (int j = 0; j < ORDER4; j++)
            resultMatrix.at(i, j) = at(i, j) + matrix4.at(i, j);
    return resultMatrix;
}

static Matrix3 getMatrix3FromMatrix4(Matrix4 matrix4, int i, int j) {
    Matrix3 matrix3;
    for (int k = 0; k < ORDER3; k++)
        for (int h = 0; h < ORDER3; h++)
            matrix3.at(k, h) = matrix4.at((i + k + 1) % ORDER4, (j + h + 1) % ORDER4);
    return matrix3;
}

static float sign(int i, int j) {
    return (i + j) % 2 == 1 ? -1.0f : 1.0f;
}

float Matrix4::determinant() const {
    float result = 0;
    for (int j = 0, i = 0; j < ORDER4; j++)
        result += at(i, j) * sign(i, j) * getMatrix3FromMatrix4(*this, i, j).determinant();
    return result;
}

Matrix4 Matrix4::transpose() const {
    Matrix4 matrix4;
    for (int i = 0; i < ORDER4; i++)
        for (int j = 0; j < ORDER4; j++)
            matrix4.at(i, j) = at(j, i);
    return matrix4;
}

static Matrix4 calculateStarMatrix(Matrix4 transposeMatrix) {
    Matrix4 starMatrix;
    for (int i = 0; i < ORDER4; i++)
        for (int j = 0; j < ORDER4; j++)
            starMatrix.at(i, j) = sign(i, j) * getMatrix3FromMatrix4(transposeMatrix, i, j).determinant();
    return starMatrix;
}

Matrix4 Matrix4::inverse() const {
    return calculateStarMatrix(transpose()) * (1.0f / determinant());
}







