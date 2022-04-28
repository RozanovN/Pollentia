//
// Created by Nikolay on 2022-04-24.
//

#include <cmath>
#include "Vector2.h"

Vector2::Vector2(const double x, const double y) {
    this->x = x;
    this->y = y;
}

Vector2::Vector2() {
    this->x = 0;
    this->y = 0;
}

Vector2::~Vector2() {
    delete this;
}

double Vector2::get_x() const {
    return this->x;
}

double Vector2::get_y() const {
    return this->y;
}

void Vector2::set_x(const double x) {
    this->x = x;
}

void Vector2::set_y(const double y) {
    this->y = y;
}

double Vector2::magnitude() const {
    return sqrt(x*x + y*y);
}

void Vector2::operator+=(const Vector2& other) {
    this->x += other.get_x();
    this->y += other.get_y();
}

Vector2 Vector2::operator+(const Vector2 &other) const {
    return {Vector2(this->x + other.get_x(), this->y + other.get_y())};
}

void Vector2::operator-=(const Vector2& other) {
    this->x -= other.get_x();
    this->y -= other.get_y();
}

Vector2 Vector2::operator-(const Vector2 &other) const {
    return {Vector2(this->x - other.get_x(), this->y - other.get_y())};
}

void Vector2::operator*=(const Vector2& other) {
    this->x *= other.get_x();
    this->y *= other.get_y();
}

Vector2 Vector2::operator*(const Vector2 &other) const {
    return {Vector2(this->x * other.get_x(), this->y * other.get_y())};
}

void Vector2::operator/=(const Vector2& other) {
    this->x /= other.get_x();
    this->y /= other.get_y();
}

Vector2 Vector2::operator/(const Vector2 &other) const {
    return {Vector2(this->x / other.get_x(), this->y / other.get_y())};
}

void Vector2::operator*=(const double other) {
    this->x *= other;
    this->y *= other;
}
