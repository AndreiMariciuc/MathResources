//
// Created by Mariciuc Andrei on 5/26/2021.
//

#ifndef MATHRESOURCES_MATRIX4_H
#define MATHRESOURCES_MATRIX4_H

#include <cstring>
#include "Vector4D.h"

#define ORDER4 4

class Matrix4 {
public:
    //  m00  m04   m08  m12
    //  m01  m05   m09  m13
    //  m02  m06   m10  m14
    //  m03  m07   m11  m15
    float matrixData[ORDER4 * ORDER4];

    Matrix4() {
        for (int i = 0; i < ORDER4 * ORDER4; i++)
            matrixData[i] = (i % 5) ? 0 : 1;
    }

    Matrix4(const float *matrix4) {
        memmove(matrixData, matrix4, sizeof(float) * ORDER4 * ORDER4);
    }

    float &at(int i, int j);

    const float &at(int i, int j) const;

    Matrix4 &operator=(const Matrix4 &matrix4);

    Matrix4 operator*(float scalar) const;

    Matrix4 operator*(const Matrix4 &matrix4) const;

    Vector4D operator*(const Vector4D &vector4D) const;

    Matrix4 operator+(const Matrix4 &matrix4) const;

    float determinant() const;

    Matrix4 transpose() const;

    Matrix4 inverse() const;

    friend std::ostream &operator<<(std::ostream &out, const Matrix4 &srcMatrix);

    bool operator==(const Matrix4 &matrix4) const {
        for (int i = 0; i < 16; i++)
            if (std::abs(matrixData[i] - matrix4.matrixData[i]) >= std::numeric_limits<float>::epsilon()) {
                return false;
            }
        return true;
    }
};

inline std::ostream &operator<<(std::ostream &out, const Matrix4 &matrix4) {
    for (int i = 0; i < 4; i++)
        out << matrix4.matrixData[i] << "\t" << matrix4.matrixData[i + 4] << "\t" << matrix4.matrixData[i + 8] << "\t"
            << matrix4.matrixData[i + 12] << "\n";
    return out;
};

#endif //MATHRESOURCES_MATRIX4_H
