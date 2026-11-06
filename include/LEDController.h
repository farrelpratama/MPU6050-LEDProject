
#ifndef LED_CONTROLLER_H
#define LED_CONTROLLER_H

#include <Arduino.h>

class LEDController {
public:
    void begin();

    void testLEDs();

    void update(
        float roll,
        float pitch
    );

private:
    const int RIGHT_LED = 15;
    const int LEFT_LED  = 2;
    const int BACK_LED  = 4;
    const int FRONT_LED = 5;

    const float THRESHOLD = 15.0;
};

#endif
