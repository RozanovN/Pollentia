//
// Created by Nikolay on 2022-04-24.
//

#ifndef GAMEENGINE_VECTOR2_H
#define GAMEENGINE_VECTOR2_H

/**
 * Represents Vector2.
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
         * Creates a Vector2 with 0 for x and 0 for y.
         */

        Vector2();

        /**
         * Creates a Vector2 with custom properties.
         *
         * @param x a double representing x value
         * @param y a double representing y value
         */
        Vector2(double x, double y);

        /**
         * Destructs this object.
         */
        ~Vector2();

        /**
         * Returns the x value of this Vector2.
         *
         * @return a double representing the x value of this Vector2
         */
        [[nodiscard]] double getX() const;

        /**
         * Returns the y value of this Vector2.
         *
         * @return a double representing the y value of this Vector2
         */
        [[nodiscard]] double getY() const;

        /**
         * Sets this Vector2's x value to new x value.
         *
         * @param x a double representing new x value
         */
        void setX(double x);

        /**
         * Sets this Vector2's y value to new x value.
         *
         * @param y a double representing new y value
         */
        void setY(double y);

        /**
         * Returns the magnitude of this Vector2.
         *
         * @return the sum of x^2 and y^2
         */
        [[nodiscard]] double magnitude() const;

        Vector2 operator + (const Vector2& other) const;
        void operator += (const Vector2& other);
        Vector2 operator - (const Vector2& other) const;
        void operator -= (const Vector2& other);
        Vector2 operator * (const Vector2& other) const;
        void operator *= (const Vector2& other);
        Vector2 operator / (const Vector2& other) const;
        void operator /= (const Vector2& other);
};


#endif //GAMEENGINE_VECTOR2_H
