//
// Created by Mariciuc Andrei on 5/24/2021.
//

#include <valarray>
#include "../headers/Vector3D.h"

Vector3D &Vector3D::operator=(const Vector3D &vector3D) {
    x = vector3D.x;
    y = vector3D.y;
    z = vector3D.z;
    return *this;
}

Vector3D Vector3D::operator+(const Vector3D &vector3D) const {
    return Vector3D(x + vector3D.x,
                    y + vector3D.y,
                    z + vector3D.z);
}

Vector3D &Vector3D::operator+=(const Vector3D &vector3D) {
    *this = *this + vector3D;
    return *this;
}

Vector3D Vector3D::operator*(float scalar) const {
    return Vector3D(x * scalar,
                    y * scalar,
                    z * scalar);
}

Vector3D Vector3D::operator-(const Vector3D &vector3D) const {
    return Vector3D(x - vector3D.x,
                    y - vector3D.y,
                    z - vector3D.z);
}

Vector3D &Vector3D::operator-=(const Vector3D &vector3D) {
    *this = *this - vector3D;
    return *this;
}

Vector3D Vector3D::operator-() const {
    return (*this) * -1;
}

float Vector3D::length() const {
    return std::sqrt(x * x + y * y + z * z);
}

Vector3D &Vector3D::normalize() {
    *this = (*this) * (1 / length());
    return *this;
}

float dotProduct(const Vector3D& v1, const Vector3D& v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Vector3D crossProduct(const Vector3D& v1, const Vector3D& v2) {
    return Vector3D(v1.y * v2.z - v2.y * v1.z,
                    v2.x * v1.z - v1.x * v2.z,
                    v1.x * v2.y - v1.y * v2.x);
}
