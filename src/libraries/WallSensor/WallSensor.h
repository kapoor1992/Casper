//
//  WallSensor.h
//
//  This library is used to make use of an Arduino compatible sonar sensor.
//

#ifndef WallSensor_h
#define WallSensor_h

#include "Arduino.h"

class WallSensor {
public:
    WallSensor(int trigPin, int echoPin);
    double getDistance(); // Returns wall distance in centimetres.
private:
    int trigPin;
    int echoPin;
    double getDuration(); // Called by getDistance().
};

#endif
