//
// Created by Mariciuc Andrei on 5/26/2021.
//

#ifndef MATHRESOURCES_MATRIX3_H
#define MATHRESOURCES_MATRIX3_H

#include <cstring>
#include "Vector3D.h"

#define ORDER3 3

class Matrix3 {
public:
    float matrixData[ORDER3 * ORDER3];

    /*
     __      __
     |m0 m3 m6|
     |m1 m4 m7|
     |m2 m5 m8|
     |__    __|
     */

    Matrix3() {
        for (int i = 0; i < ORDER3 * ORDER3; i++)
            matrixData[i] = (i % 4) ? 0 : 1;
    }

    Matrix3(float *matrix) {
        memmove(matrixData, matrix, sizeof(float) * ORDER3 * ORDER3);
    }

    float &at(int i, int j);

    const float &at(int i, int j) const;

    Matrix3 &operator=(const Matrix3 &matrix3);

    Matrix3 operator*(float scalar) const;

    Matrix3 operator*(const Matrix3 &matrix3) const;

    Vector3D operator*(const Vector3D &vector3D) const;

    Matrix3 operator+(const Matrix3 &matrix3) const;

    float determinant() const;

    Matrix3 transpose() const;

    Matrix3 inverse() const;

    friend std::ostream& operator<< (std::ostream &out, const Matrix3& matrix3);

    bool operator ==(const Matrix3& matrix3) const
    {
        for (int i = 0; i < 9; i++)
            if (std::abs(matrixData[i] - matrix3.matrixData[i]) >= std::numeric_limits<float>::epsilon()) {
                return false;
            }
        return true;
    }
};

inline std::ostream& operator<< (std::ostream &out, const Matrix3& matrix3)
{
    for(int i = 0; i < 3; i++)
        out << matrix3.matrixData[i] << "\t" << matrix3.matrixData[i + 3] << "\t" << matrix3.matrixData[i + 6] << "\n";
    return out;
};

#endif //MATHRESOURCES_MATRIX3_H
