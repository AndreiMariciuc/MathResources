//
// Created by Mariciuc Andrei on 5/24/2021.
//

#ifndef MATHRESOURCES_VECTOR4D_H
#define MATHRESOURCES_VECTOR4D_H

#include <limits>
#include <complex>

class Vector4D {
public:
    union {
        float x;
        float r;
    };

    union {
        float y;
        float g;
    };

    union {
        float z;
        float b;
    };

    union {
        float w;
        float a;
    };

    Vector4D()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
        w = 0.0f;
    }

    Vector4D(float fX, float fY, float fZ, float fW)
    {
        x = fX;
        y = fY;
        z = fZ;
        w = fW;
    }

    Vector4D(const Vector4D &vector4D)
    {
        x = vector4D.x;
        y = vector4D.y;
        z = vector4D.z;
        w = vector4D.w;
    }

    bool operator ==(const Vector4D& vector4D) const
    {
        float epsilon = std::numeric_limits<float>::epsilon();
        return (std::abs(x - vector4D.x) < epsilon) && (std::abs(y - vector4D.y) < epsilon) && (std::abs(z - vector4D.z) < epsilon) && (std::abs(w - vector4D.w) < epsilon);
    }

    friend std::ostream& operator<< (std::ostream &out, const Vector4D& srcVector);

    Vector4D& operator =(const Vector4D &vector4D);
    Vector4D operator +(const Vector4D& vector4D) const;
    Vector4D& operator +=(const Vector4D& vector4D);
    Vector4D operator *(float scalarValue) const;
    Vector4D operator -(const Vector4D& vector4D) const;
    Vector4D& operator -=(const Vector4D& vector4D);
    Vector4D operator -() const;
    float length() const;
    Vector4D& normalize();
};

inline std::ostream& operator<< (std::ostream &out, const Vector4D& vector4D)
{
    out << "(" << vector4D.x << ", " << vector4D.y << ", " << vector4D.z << ", " << vector4D.w << ")";
    return out;
}

#endif //MATHRESOURCES_VECTOR4D_H
