//
// Created by Nikolay on 2022-04-24.
//

#include "AngleConversion.h"

double convert_to_degrees(double radians) {
    return radians * 180 / PI;
}

double convert_to_radians(double degrees) {
    return degrees * PI / 180;
}