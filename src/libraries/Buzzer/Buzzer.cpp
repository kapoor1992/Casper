//
//  Buzzer.cpp
//

#include "Arduino.h"
#include "Buzzer.h"

// Sets up buzzer pin.
Buzzer::Buzzer(int buzzerPin) {
    this->buzzerPin = buzzerPin;
    pinMode(buzzerPin, OUTPUT);
}

void Buzzer::countdown() {
    tone(buzzerPin, 800, 500);
    delay(1000);
    tone(buzzerPin, 800, 500);
    delay(1000);
    tone(buzzerPin, 800, 500);
    delay(1000);
    tone(buzzerPin, 1200, 1000);
    delay(2000);
}

void Buzzer::scream() {
    tone(buzzerPin, 400, 250);
}

void Buzzer::celebrate() {
    for (int i = 200; i <= 500; i += 50) {
        tone(buzzerPin, i, 250);
        delay(250);
    }
    
    delay(250);
    tone(buzzerPin, 600, 250);
    delay(250);
    tone(buzzerPin, 600, 250);
    delay(250);
    tone(buzzerPin, 600, 250);
    delay(250);
}