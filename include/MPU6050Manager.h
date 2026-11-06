
#ifndef MPU6050_MANAGER_H
#define MPU6050_MANAGER_H

#include <Arduino.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

class MPU6050Manager {
public:
    bool begin(uint8_t sdaPin, uint8_t sclPin);

    bool readAcceleration(
        float &ax,
        float &ay,
        float &az
    );

private:
    Adafruit_MPU6050 mpu;
};

#endif
