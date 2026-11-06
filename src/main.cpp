
#include <Arduino.h>

#include "MPU6050Manager.h"
#include "Orientation.h"
#include "LEDController.h"

// Hardware objects
MPU6050Manager imu;
Orientation orientation;
LEDController ledController;

// ESP32 I2C configuration
const int SDA_PIN = 21;
const int SCL_PIN = 22;

// Non-blocking timer
unsigned long previousMillis = 0;
const unsigned long interval = 500;

void setup() {

    Serial.begin(115200);

    // Initialize LEDs
    ledController.begin();
    ledController.testLEDs();

    // Initialize MPU6050
    if (!imu.begin(SDA_PIN, SCL_PIN)) {

        Serial.println("MPU6050 not found!");

        while (true) {
            delay(1000);
        }
    }

    Serial.println("MPU6050 initialized successfully!");
    Serial.println("ESP32 Orientation Indicator Started");
    Serial.println("--------------------------------");
}

void loop() {

    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {

        previousMillis = currentMillis;

        // Read acceleration
        float ax, ay, az;

        imu.readAcceleration(ax, ay, az);

        // Calculate orientation
        OrientationData angle = orientation.calculate(
            ax, ay, az
        );

        // Update LED indicators
        ledController.update(
            angle.roll,
            angle.pitch
        );

        // Display acceleration
        Serial.println("--------------------------------");

        Serial.print("AX: ");
        Serial.print(ax, 2);

        Serial.print(" | AY: ");
        Serial.print(ay, 2);

        Serial.print(" | AZ: ");
        Serial.println(az, 2);

        // Display orientation
        Serial.print("Roll: ");
        Serial.print(angle.roll, 2);

        Serial.print(" deg | Pitch: ");
        Serial.print(angle.pitch, 2);

        Serial.println(" deg");
    }
}
