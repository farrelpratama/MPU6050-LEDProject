
#include "MPU6050Manager.h"
#include <Wire.h>

bool MPU6050Manager::begin(uint8_t sdaPin, uint8_t sclPin) {

    Wire.begin(sdaPin, sclPin);

    if (!mpu.begin(0x68, &Wire)) {
        return false;
    }

    mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
    mpu.setGyroRange(MPU6050_RANGE_500_DEG);
    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

    return true;
}

bool MPU6050Manager::readAcceleration(
    float &ax,
    float &ay,
    float &az
) {
    sensors_event_t a, g, temp;

    mpu.getEvent(&a, &g, &temp);

    ax = a.acceleration.x;
    ay = a.acceleration.y;
    az = a.acceleration.z;

    return true;
}
