
#include "LEDController.h"

void LEDController::begin() {

    pinMode(RIGHT_LED, OUTPUT);
    pinMode(LEFT_LED, OUTPUT);
    pinMode(BACK_LED, OUTPUT);
    pinMode(FRONT_LED, OUTPUT);
}

void LEDController::testLEDs() {

    digitalWrite(RIGHT_LED, HIGH);
    digitalWrite(LEFT_LED, HIGH);
    digitalWrite(BACK_LED, HIGH);
    digitalWrite(FRONT_LED, HIGH);

    delay(500);

    digitalWrite(RIGHT_LED, LOW);
    digitalWrite(LEFT_LED, LOW);
    digitalWrite(BACK_LED, LOW);
    digitalWrite(FRONT_LED, LOW);

    delay(200);
}

void LEDController::update(
    float roll,
    float pitch
) {

    // Right: Positive Roll
    digitalWrite(
        RIGHT_LED,
        roll > THRESHOLD ? HIGH : LOW
    );

    // Left: Negative Roll
    digitalWrite(
        LEFT_LED,
        roll < -THRESHOLD ? HIGH : LOW
    );

    // Back: Positive Pitch
    digitalWrite(
        BACK_LED,
        pitch > THRESHOLD ? HIGH : LOW
    );

    // Front: Negative Pitch
    digitalWrite(
        FRONT_LED,
        pitch < -THRESHOLD ? HIGH : LOW
    );
}
