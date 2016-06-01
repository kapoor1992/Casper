//
//  Car.cpp
//

#include "Arduino.h"
#include "Car.h"

// Takes care of pin setup.
Car::Car(int wheelSpeed) {
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

void Car::goForwards() {
    analogWrite(leftSpeedPin, wheelSpeed);
    digitalWrite(leftDirPin, leftForwards);
    
    analogWrite(rightSpeedPin, wheelSpeed);
    digitalWrite(rightDirPin, rightForwards);
}

void Car::goBackwards() {
    analogWrite(leftSpeedPin, wheelSpeed);
    digitalWrite(leftDirPin, leftBackwards);
    
    analogWrite(rightSpeedPin, wheelSpeed);
    digitalWrite(rightDirPin, rightBackwards);
}

void Car::stopMoving() {
    analogWrite(leftSpeedPin, 0);
    digitalWrite(leftDirPin, leftForwards);
    
    analogWrite(rightSpeedPin, 0);
    digitalWrite(rightDirPin, rightForwards);
}

void Car::turnLeft() {
    analogWrite(leftSpeedPin, wheelSpeed);
    digitalWrite(leftDirPin, leftBackwards);
    
    analogWrite(rightSpeedPin, wheelSpeed);
    digitalWrite(rightDirPin, rightForwards);
    
    delay(1000); // May require tweaking
    
    return;
}

void Car::turnRight() {
    analogWrite(leftSpeedPin, wheelSpeed);
    digitalWrite(leftDirPin, leftForwards);
    
    analogWrite(rightSpeedPin, wheelSpeed);
    digitalWrite(rightDirPin, rightBackwards);
    
    delay(1000); // May require tweaking.
    
    return;
}

void Car::turnAround() {
    analogWrite(leftSpeedPin, wheelSpeed);
    digitalWrite(leftDirPin, leftForwards);
    
    analogWrite(rightSpeedPin, wheelSpeed);
    digitalWrite(rightDirPin, rightBackwards);
    
    delay(1800); // May require tweaking.
    
    return;
}