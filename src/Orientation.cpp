
#include "Orientation.h"
#include <Arduino.h>
#include <math.h>

OrientationData Orientation::calculate(
    float ax,
    float ay,
    float az
) {
    OrientationData result;

    // Calculate Roll
    result.roll = atan2(ay, az);

    // Calculate Pitch
    result.pitch = atan2(
        -ax,
        sqrt(ay * ay + az * az)
    );

    // Convert radians to degrees
    result.roll *= 180.0 / PI;
    result.pitch *= 180.0 / PI;

    return result;
}
