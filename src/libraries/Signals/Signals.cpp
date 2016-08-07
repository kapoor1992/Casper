//
//  Signals.cpp
//

#include "Arduino.h"
#include "Signals.h"

// Sets up signal pins.
Signals::Signals(int leftPin, int rightPin) {
    this->leftPin = leftPin;
    this->rightPin = rightPin;
    
    pinMode(leftPin, OUTPUT);
    pinMode(rightPin, OUTPUT);
}

// Left blinker.
void Signals::blinkLeft() {
    for (int i = 0; i < blinks; i++) {
        digitalWrite(leftPin, HIGH);
        delay(stall);
        digitalWrite(leftPin, LOW);
        delay(stall);
    }
}

// Right blinker
void Signals::blinkRight() {
    for (int i = 0; i < blinks; i++) {
        digitalWrite(rightPin, HIGH);
        delay(stall);
        digitalWrite(rightPin, LOW);
        delay(stall);
    }
}

// Both blinkers.
void Signals::blinkBoth() {
    for (int i = 0; i < blinks; i++) {
        digitalWrite(leftPin, HIGH);
        digitalWrite(rightPin, HIGH);
        delay(stall);
        digitalWrite(leftPin, LOW);
        digitalWrite(rightPin, LOW);
        delay(stall);
    }
}