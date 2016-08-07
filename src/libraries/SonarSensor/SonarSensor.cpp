//
//  SonarSensor.cpp
//

#include "Arduino.h"
#include "SonarSensor.h"

// Sets up pins and threshold.
SonarSensor::SonarSensor(int trigPin, int echoPin, int threshold) {
    this->trigPin = trigPin;
    this->echoPin = echoPin;
    this->threshold = threshold;

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

// Assumes that the speed of sound is 344m/s.
bool SonarSensor::isWall() {
    double duration = getDuration();
    int distance = (duration / 2) * 0.0344;
    
    return distance < threshold;
}

// Sends and captures sound signal.
double SonarSensor::getDuration() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    
    digitalWrite(trigPin, LOW);
    
    return pulseIn(echoPin, HIGH);
}