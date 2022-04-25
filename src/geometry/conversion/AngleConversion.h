//
// Created by Nikolay on 2022-04-24.
//

#ifndef GAMEENGINE_ANGLECONVERSION_H
    #define GAMEENGINE_ANGLECONVERSION_H
    #ifndef PI
        #define PI 3.14159265358979323846
    #endif
/**
 * Converts radians to degrees.
 *
 * @param radians a double representing radians value
 * @return a double representing the given value in degrees
 */
double convert_to_degrees(double radians);

/**
 * Converts degrees to radians.
 *
 * @param degrees a double representing degrees value
 * @return a double representing the given value in radians
 */
double convert_to_radians(double degrees);

#endif //GAMEENGINE_ANGLECONVERSION_H
