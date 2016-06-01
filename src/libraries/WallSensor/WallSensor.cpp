//
//  WallSensor.cpp
//

#include "Arduino.h"
#include "WallSensor.h"

// Sets up pins.
WallSensor::WallSensor(int trigPin, int echoPin) {
    this->trigPin = trigPin;
    this->echoPin = echoPin;

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

// Assumes that the speed of sound is 344m/s.
double WallSensor::getDistance() {
    double duration = getDuration();
    
    return (duration / 2) * 0.0344;
}

// Sends and captures sound signal.
double WallSensor::getDuration() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    
    digitalWrite(trigPin, LOW);
    
    return pulseIn(echoPin, HIGH);
}