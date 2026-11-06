
#ifndef ORIENTATION_H
#define ORIENTATION_H

struct OrientationData {
    float roll;
    float pitch;
};

class Orientation {
public:
    OrientationData calculate(
        float ax,
        float ay,
        float az
    );
};

#endif
