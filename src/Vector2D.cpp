//
// Created by Mariciuc Andrei on 5/24/2021.
//

#include "../headers/Vector2D.h"

inline std::ostream &operator<<(std::ostream &out, const Vector2D &vector2D) {
    out << "(" << vector2D.x << ", " << vector2D.y << ")";
    return out;
}

Vector2D Vector2D::operator-(const Vector2D &vector2D) const {
    return Vector2D(x - vector2D.x,
                    y - vector2D.y);
}


Vector2D &Vector2D::operator=(const Vector2D &vector2D) {
    this->x = vector2D.x;
    this->y = vector2D.y;
    return *this;
}

Vector2D Vector2D::operator+(const Vector2D &vector2D) const {
    Vector2D vec;
    vec.x = vector2D.x + x;
    vec.y = vector2D.y + y;
    return vec;
}

Vector2D &Vector2D::operator+=(const Vector2D &vector2D) {
    *this = *this + vector2D;
    return *this;
}

Vector2D &Vector2D::operator-=(const Vector2D &vector2D) {
    *this = *this - vector2D;
    return *this;
}

Vector2D Vector2D::operator*(float scalar) const {
    Vector2D vec;
    vec.x = x * scalar;
    vec.y = y * scalar;
    return vec;
}

Vector2D Vector2D::operator-() const {
    Vector2D vec = (*this) * -1;
    return vec;
}

float Vector2D::length() const {
    return std::sqrt(x * x + y * y);
}

Vector2D &Vector2D::normalize() {
    *this =  (*this) * (1 / this->length());
    return *this;
}

float dotProduct(const Vector2D& vector2D1, const Vector2D& vector2D2) {
return vector2D1.x * vector2D2.x + vector2D1.y * vector2D2.y;
}