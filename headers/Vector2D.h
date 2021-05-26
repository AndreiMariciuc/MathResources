//
// Created by Mariciuc Andrei on 5/24/2021.
//

#ifndef MATHRESOURCES_VECTOR2D_H
#define MATHRESOURCES_VECTOR2D_H

#include <complex>
#include "Vector3D.h"
#include "Vector4D.h"

class Vector2D {
public:
    union {
        float x;
        float u;
    };

    union {
        float y;
        float v;
    };

    Vector2D() {
        x = y = 0;
    }

    Vector2D(Vector2D const &vector2D) {
        x = vector2D.x;
        y = vector2D.y;
    }

    Vector2D(float fx, float fy) {
        x = fx;
        y = fy;
    }

    Vector2D(Vector3D vector3D) {
        x = vector3D.x;
        y = vector3D.y;
    }

    Vector2D(Vector4D vector4D) {
        x = vector4D.x;
        y = vector4D.y;
    }

    bool operator ==(const Vector2D &vector2D) const {
        float epsilon = std::numeric_limits<float>::epsilon();
        return std::abs(x - vector2D.x) < epsilon  && std::abs(y - vector2D.y) < epsilon;
    }

    friend std::ostream& operator<< (std::ostream &out, const Vector2D& vector2D);

    Vector2D& operator =(const Vector2D &vector2D);
    Vector2D operator +(const Vector2D &vector2D) const;
    Vector2D& operator +=(const Vector2D &vector2D);
    Vector2D& operator -=(const Vector2D &vector2D);
    Vector2D operator *(float scalar) const;
    Vector2D operator -(const Vector2D &vector2D) const;
    Vector2D operator -() const;
    float length() const;
    Vector2D& normalize();
};

float dotProduct(const Vector2D& vector2D1, const Vector2D& vector2D2);

#endif //MATHRESOURCES_VECTOR2D_H
