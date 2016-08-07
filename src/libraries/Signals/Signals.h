//
//  Signals.h
//
//  This library is used to simulate turn signals for an Arduino powered vehicle.
//

#ifndef Signals_h
#define Signals_h

#include "Arduino.h"

class Signals {
public:
    const int stall = 100; // The milliseconds between blinks.
    const int blinks = 5;
    
    Signals(int leftPin, int rightPin);
    void blinkLeft();
    void blinkRight();
    void blinkBoth();
private:
    int leftPin;
    int rightPin;
};

#endif
