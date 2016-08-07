//
//  Driver.cpp
//

#include "Arduino.h"
#include "Driver.h"

// Takes care of pin setup.
Driver::Driver(int wheelSpeed) {
    this->wheelSpeed = wheelSpeed;
    
    pinMode(leftSpeedPin, OUTPUT);
    pinMode(leftDirPin, OUTPUT);
    pinMode(rightSpeedPin, OUTPUT);
    pinMode(rightDirPin, OUTPUT);
    
    digitalWrite(leftSpeedPin, LOW);
    digitalWrite(leftDirPin, LOW);
    digitalWrite(rightSpeedPin, LOW);
    digitalWrite(rightDirPin, LOW);
}

void Driver::goForwards() {
    analogWrite(leftSpeedPin, wheelSpeed);
    digitalWrite(leftDirPin, leftForwards);
    
    analogWrite(rightSpeedPin, wheelSpeed);
    digitalWrite(rightDirPin, rightForwards);
}

void Driver::goBackwards() {
    analogWrite(leftSpeedPin, wheelSpeed);
    digitalWrite(leftDirPin, leftBackwards);
    
    analogWrite(rightSpeedPin, wheelSpeed);
    digitalWrite(rightDirPin, rightBackwards);
}

void Driver::stopMoving() {
    analogWrite(leftSpeedPin, 0);
    digitalWrite(leftDirPin, leftForwards);
    
    analogWrite(rightSpeedPin, 0);
    digitalWrite(rightDirPin, rightForwards);
}

void Driver::turnLeft() {
    analogWrite(leftSpeedPin, wheelSpeed);
    digitalWrite(leftDirPin, leftBackwards);
    
    analogWrite(rightSpeedPin, wheelSpeed);
    digitalWrite(rightDirPin, rightForwards);
    
    delay(700); // May require tweaking
    
    return;
}

void Driver::turnRight() {
    analogWrite(leftSpeedPin, wheelSpeed);
    digitalWrite(leftDirPin, leftForwards);
    
    analogWrite(rightSpeedPin, wheelSpeed);
    digitalWrite(rightDirPin, rightBackwards);
    
    delay(700); // May require tweaking.
    
    return;
}

void Driver::turnAround() {
    analogWrite(leftSpeedPin, wheelSpeed);
    digitalWrite(leftDirPin, leftForwards);
    
    analogWrite(rightSpeedPin, wheelSpeed);
    digitalWrite(rightDirPin, rightBackwards);
    
    delay(1300); // May require tweaking.
    
    return;
}