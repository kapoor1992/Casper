//
//  FlexSensor.cpp
//

#include "Arduino.h"
#include "FlexSensor.h"

// Sets up pin and threshold.
FlexSensor::FlexSensor(int flexPin, int threshold) {
    this->flexPin = flexPin;
    this->threshold = threshold;
}

// Returns the current flex value.
bool FlexSensor::isFlexed() {
    return analogRead(flexPin) > threshold;
}