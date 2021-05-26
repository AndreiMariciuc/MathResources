//
// Created by Mariciuc Andrei on 5/26/2021.
//

#include "../headers/Matrix3.h"

float &Matrix3::at(int i, int j) {
    return matrixData[i + j * ORDER3];
}

const float &Matrix3::at(int i, int j) const {
    return matrixData[i + j * ORDER3];
}

Matrix3 &Matrix3::operator=(const Matrix3 &matrix3) {
    for (int i = 0; i < ORDER3; i++)
        for (int j = 0; j < ORDER3; j++)
            at(i, j) = matrix3.at(i, j);
    return *this;
}

Matrix3 Matrix3::operator*(float scalar) const {
    Matrix3 matrix3;
    for (int i = 0; i < ORDER3; i++)
        for (int j = 0; j < ORDER3; j++)
            matrix3.at(i, j) = at(i, j) * scalar;
    return matrix3;
}

Matrix3 Matrix3::operator*(const Matrix3 &matrix3) const {
    Matrix3 resultMatrix;
    for (int i = 0; i < ORDER3; i++)
        for (int j = 0; j < ORDER3; j++) {
            resultMatrix.at(i, j) = 0;
            for (int k = 0; k < ORDER3; k++)
                resultMatrix.at(i, j) += at(i, k) * matrix3.at(k, j);
        }
    return resultMatrix;
}

static float calculateResult(const float v[], int line, Matrix3 matrix3) {
    float result = 0;
    for (int k = 0; k < ORDER3; k++)
        result += v[k] * matrix3.at(line, k);
    return result;
}

Vector3D Matrix3::operator*(const Vector3D &vector3D) const {
    Vector3D resultVector;
    float v[] = {vector3D.x, vector3D.y, vector3D.z};
    resultVector.x = calculateResult(v, 0, *this);
    resultVector.y = calculateResult(v, 1, *this);
    resultVector.z = calculateResult(v, 2, *this);
    return resultVector;
}

Matrix3 Matrix3::operator+(const Matrix3 &matrix3) const {
    Matrix3 resultMatrix;
    for (int i = 0; i < ORDER3; i++)
        for (int j = 0; j < ORDER3; j++)
            resultMatrix.at(i, j) = at(i, j) + matrix3.at(i, j);
    return resultMatrix;
}

static float determinantOrder2(float a00, float a01, float a10, float a11) {
    return a00 * a11 - a10 * a01;
}

float Matrix3::determinant() const {
    float result = 0;
    for (int j = 0, i = 0; j < ORDER3; j++)
        result += at(i, j) * determinantOrder2(at((i + 1) % ORDER3, (j + 1) % ORDER3),
                                               at((i + 1) % ORDER3, (j + 2) % ORDER3),
                                               at((i + 2) % ORDER3, (j + 1) % ORDER3),
                                               at((i + 2) % ORDER3, (j + 2) % ORDER3));
    return result;
}

Matrix3 Matrix3::transpose() const {
    Matrix3 transposeMatrix;
    for (int i = 0; i < ORDER3; i++)
        for (int j = 0; j < ORDER3; j++)
            transposeMatrix.at(i, j) = at(j, i);
    return transposeMatrix;
}

static Matrix3 calculateStarMatrix(Matrix3 transposeMatrix) {
    Matrix3 starMatrix;
    for (int i = 0; i < ORDER3; i++)
        for (int j = 0; j < ORDER3; j++)
            starMatrix.at(i, j) = determinantOrder2(transposeMatrix.at((i + 1) % ORDER3, (j + 1) % ORDER3),
                                                    transposeMatrix.at((i + 1) % ORDER3, (j + 2) % ORDER3),
                                                    transposeMatrix.at((i + 2) % ORDER3, (j + 1) % ORDER3),
                                                    transposeMatrix.at((i + 2) % ORDER3, (j + 2) % ORDER3));
    return starMatrix;
}

Matrix3 Matrix3::inverse() const {
    return calculateStarMatrix(transpose()) * (1.0f / determinant());
}