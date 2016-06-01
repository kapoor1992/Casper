//
//  Buzzer.h
//
//  This library makes use of an Arduino's piezo buzzer.
//

#ifndef Buzzer_h
#define Buzzer_h

#include "Arduino.h"

class Buzzer {
public:
    Buzzer(int buzzerPin);
    void countdown(); // 3-2-1 countdown.
    void scream();    // Quick beeping sound.
    void celebrate(); // Short jingle.
private:
    int buzzerPin;
};

#endif
