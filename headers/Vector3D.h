//
// Created by Mariciuc Andrei on 5/24/2021.
//

#ifndef MATHRESOURCES_VECTOR3D_H
#define MATHRESOURCES_VECTOR3D_H

#include <limits>
#include <ostream>
#include "Vector4D.h"

class Vector3D {
public:
    union {
        float x;
        float r;
        float u;
    };

    union {
        float y;
        float g;
        float v;
    };

    union {
        float z;
        float b;
        float w;
    };

    Vector3D()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }

    //creates a vector (fX, fY, fZ)
    Vector3D(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }

    //copy constructor
    Vector3D(const Vector3D &vector3D)
    {
        x = vector3D.x;
        y = vector3D.y;
        z = vector3D.z;
    }

    Vector3D(const Vector4D &vector4D)
    {
        x = vector4D.x;
        y = vector4D.y;
        z = vector4D.z;
    }

    bool operator ==(const Vector3D& vector3D) const
    {
        float epsilon =  std::numeric_limits<float>::epsilon();
        return (std::abs(x - vector3D.x) < epsilon) && (std::abs(y - vector3D.y) < epsilon) && (std::abs(z - vector3D.z) < epsilon);
    }

    friend std::ostream& operator<< (std::ostream &out, const Vector3D& vector3D);


    Vector3D& operator =(const Vector3D &vector3D);
    Vector3D operator +(const Vector3D& vector3D) const;
    Vector3D& operator +=(const Vector3D& vector3D);
    Vector3D operator *(float scalar) const;
    Vector3D operator -(const Vector3D& vector3D) const;
    Vector3D& operator -=(const Vector3D& vector3D);
    Vector3D operator -() const;
    float length() const;
    Vector3D& normalize();
};

float dotProduct(const Vector3D& v1, const Vector3D& v2);
Vector3D crossProduct(const Vector3D& v1, const Vector3D& v2);

inline std::ostream& operator<< (std::ostream &out, const Vector3D& srcVector)
{
    out << "(" << srcVector.x << ", " << srcVector.y << ", " << srcVector.z << ")";
    return out;
}

#endif //MATHRESOURCES_VECTOR3D_H
