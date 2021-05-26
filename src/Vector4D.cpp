//
// Created by Mariciuc Andrei on 5/24/2021.
//

#include "../headers/Vector4D.h"

Vector4D &Vector4D::operator=(const Vector4D &vector4D) {
    x = vector4D.x;
    y = vector4D.y;
    z = vector4D.z;
    w = vector4D.w;
    return *this;
}

Vector4D Vector4D::operator+(const Vector4D &vector4D) const {
    return Vector4D(x + vector4D.x,
                    y + vector4D.y,
                    z + vector4D.z,
                    w + vector4D.w);
}

Vector4D &Vector4D::operator+=(const Vector4D &vector4D) {
    *this = *this + vector4D;
    return *this;
}

Vector4D Vector4D::operator*(float scalarValue) const {
    return Vector4D(x * scalarValue,
                    y * scalarValue,
                    z * scalarValue,
                    w * scalarValue);
}

Vector4D Vector4D::operator-(const Vector4D &vector4D) const {
    return Vector4D(x - vector4D.x,
                    y - vector4D.y,
                    z - vector4D.z,
                    w - vector4D.w);
}

Vector4D &Vector4D::operator-=(const Vector4D &vector4D) {
    *this = *this - vector4D;
    return *this;
}

Vector4D Vector4D::operator-() const {
    return (*this) * (-1);
}

float Vector4D::length() const {
    return std::sqrt(x * x + y * y + z * z + w * w);
}

Vector4D &Vector4D::normalize() {
    *this = *this * (1 / length());
    return *this;
}
