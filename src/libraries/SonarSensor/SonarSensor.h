//
//  SonarSensor.h
//
//  This library is used to make use of an Arduino compatible sonar sensor.
//

#ifndef SonarSensor_h
#define SonarSensor_h

#include "Arduino.h"

class SonarSensor {
public:
    SonarSensor(int trigPin, int echoPin, int threshold);
    bool isWall(); // Returns true if a wall is within the threshold distance.
private:
    int trigPin;
    int echoPin;
    int threshold;        // In centimetres.
    double getDuration(); // Called by isWall().
};

#endif
