//
//  Driver.h
//
//  This library controls two motors connected to the SparkFun Ardumoto motor shield.
//  Optimal results are for a wheel speed of 75 and when the ground is covered in a thin carpet.
//

#ifndef Driver_h
#define Driver_h

#include "Arduino.h"

class Driver {
public:
    // These are not to be changed.
    const int leftSpeedPin = 11;
    const int leftDirPin = 13;
    const int rightSpeedPin = 3;
    const int rightDirPin = 12;
    // Forwards/backwards values may need to be reversed depending on the wiring.
    const int leftForwards = 0;
    const int leftBackwards = 1;
    const int rightForwards = 1;
    const int rightBackwards = 0;
    
    Driver(int wheelSpeed);
    void goForwards();
    void goBackwards();
    void stopMoving();
    void turnLeft();
    void turnRight();
    void turnAround();
private:
    int wheelSpeed;
};

#endif
