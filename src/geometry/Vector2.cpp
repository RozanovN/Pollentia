#include <cmath>
#include "Vector2.h"

Vector2::Vector2(const double x, const double y) {
    this->x_ = x;
    this->y_ = y;
}

Vector2::Vector2() {
    this->x_ = 0;
    this->y_ = 0;
}

Vector2::~Vector2() {
    delete this;
}

double Vector2::get_x() const {
    return this->x_;
}

double Vector2::get_y() const {
    return this->y_;
}

void Vector2::set_x(const double x) {
    this->x_ = x;
}

void Vector2::set_y(const double y) {
    this->y_ = y;
}

double Vector2::magnitude() const {
    return sqrt(x_ * x_ + y_ * y_);
}

void Vector2::operator+=(const Vector2& other) {
    this->x_ += other.get_x();
    this->y_ += other.get_y();
}

Vector2 Vector2::operator+(const Vector2 &other) const {
    return {Vector2(this->x_ + other.get_x(), this->y_ + other.get_y())};
}

void Vector2::operator-=(const Vector2& other) {
    this->x_ -= other.get_x();
    this->y_ -= other.get_y();
}

Vector2 Vector2::operator-(const Vector2 &other) const {
    return {Vector2(this->x_ - other.get_x(), this->y_ - other.get_y())};
}

void Vector2::operator*=(const Vector2& other) {
    this->x_ *= other.get_x();
    this->y_ *= other.get_y();
}

Vector2 Vector2::operator*(const Vector2 &other) const {
    return {Vector2(this->x_ * other.get_x(), this->y_ * other.get_y())};
}

void Vector2::operator/=(const Vector2& other) {
    this->x_ /= other.get_x();
    this->y_ /= other.get_y();
}

Vector2 Vector2::operator/(const Vector2 &other) const {
    return {Vector2(this->x_ / other.get_x(), this->y_ / other.get_y())};
}

void Vector2::operator*=(const double other) {
    this->x_ *= other;
    this->y_ *= other;
}
