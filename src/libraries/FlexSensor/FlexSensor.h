//
//  FlexSensor.h
//
//  This library is used to make use of an Arduino compatible flex sensor.
//

#ifndef FlexSensor_h
#define FlexSensor_h

#include "Arduino.h"

class FlexSensor {
public:
    FlexSensor(int flexPin, int threshold);
    bool isFlexed(); // Returns true if the sensor is flexed passed the threshold.
private:
    int flexPin;
    int threshold;
};

#endif
