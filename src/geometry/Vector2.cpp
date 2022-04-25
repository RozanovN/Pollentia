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

double Vector2::getX() const {
    return this->x;
}

double Vector2::getY() const {
    return this->y;
}

void Vector2::setX(const double x) {
    this->x = x;
}

void Vector2::setY(const double y) {
    this->y = y;
}

double Vector2::magnitude() const {
    return sqrt(x*x + y*y);
}

void Vector2::operator+=(const Vector2& other) {
    this->x += other.getX();
    this->y += other.getY();
}

Vector2 Vector2::operator+(const Vector2 &other) const {
    return {Vector2(this->x + other.getX(), this->y + other.getY())};
}

void Vector2::operator-=(const Vector2& other) {
    this->x -= other.getX();
    this->y -= other.getY();
}

Vector2 Vector2::operator-(const Vector2 &other) const {
    return {Vector2(this->x - other.getX(), this->y - other.getY())};
}

void Vector2::operator*=(const Vector2& other) {
    this->x *= other.getX();
    this->y *= other.getY();
}

Vector2 Vector2::operator*(const Vector2 &other) const {
    return {Vector2(this->x * other.getX(), this->y * other.getY())};
}

void Vector2::operator/=(const Vector2& other) {
    this->x /= other.getX();
    this->y /= other.getY();
}

Vector2 Vector2::operator/(const Vector2 &other) const {
    return {Vector2(this->x / other.getX(), this->y / other.getY())};
}
