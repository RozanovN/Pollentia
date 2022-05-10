//
// Created by Nikolay on 2022-04-24.
//

#ifndef GAMEENGINE_VECTOR2_H
#define GAMEENGINE_VECTOR2_H

/**
 * Represents a 2 dimensional vector.
 *
 * @author Nikolay Rozanov
 * @version 1.0
 */
class Vector2 {
    private:
        double x;
        double y;
    public:

        /**
         * Constructs a new 2 dimensional vector with 0 for x and 0 for y.
         */
        Vector2();

        /**
         * Constructs a new 2 dimensional vector with custom properties.
         *
         * @param x a double representing x value
         * @param y a double representing y value
         */
        Vector2(double x, double y);

        /**
         * Destructs this Vector2.
         */
        ~Vector2();

        /**
         * Returns the x value of this Vector2.
         *
         * @return a double representing the x value of this Vector2
         */
        [[nodiscard]] double get_x() const;

        /**
         * Returns the y value of this Vector2.
         *
         * @return a double representing the y value of this Vector2
         */
        [[nodiscard]] double get_y() const;

        /**
         * Sets this Vector2's x value to new x value.
         *
         * @param x a double representing new x value
         */
        void set_x(double x);

        /**
         * Sets this Vector2's y value to new x value.
         *
         * @param y a double representing new y value
         */
        void set_y(double y);

        /**
         * Returns the magnitude of this Vector2.
         *
         * @return the sum of x^2 and y^2
         */
        [[nodiscard]] double magnitude() const;

        /**
         * Returns a new Vector2 with the sum of two vectors
         *
         * @param other a Vector2 to add
         * @return Vector2
         */
        Vector2 operator + (const Vector2& other) const;

        /**
         * Add other Vector2 to this Vector2
         *
         * @param other Vector 2 to add
         */
        void operator += (const Vector2& other);

        /**
         * Returns a new Vector2 with the difference of two vectors
         *
         * @param other a Vector2 to subtract
         * @return Vector2
         */
        Vector2 operator - (const Vector2& other) const;

        /**
         * Subtracts other Vector2 from this Vector2
         *
         * @param other Vector 2 to subtract
         */
        void operator -= (const Vector2& other);

        /**
         * Returns a new Vector2 with the product of two vectors
         *
         * @param other a Vector2 to multiply
         * @return Vector2
         */
        Vector2 operator * (const Vector2& other) const;

        /**
         * Multiplies this Vector2 by other Vector2
         *
         * @param other Vector 2 to multiply
         */
        void operator *= (const Vector2& other);

        /**
         * Returns a new Vector2 with the quotient of two vectors
         *
         * @param other a Vector2 to divide by
         * @return Vector2
         */
        Vector2 operator / (const Vector2& other) const;

        /**
         * Divides this Vector2 by other Vector2
         *
         * @param other Vector 2 to divide by
         */
        void operator /= (const Vector2& other);

        /**
         * Multiplies this Vector2 by double other
         *
         * @param other double to multiply by
         */
        void operator *= (double other);
};


#endif //GAMEENGINE_VECTOR2_H
