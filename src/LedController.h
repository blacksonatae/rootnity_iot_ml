//
// Created by kevin on 19/03/2025.
//

#ifndef ROOTNITY_IOT_ML_LEDCONTROLLER_H
#define ROOTNITY_IOT_ML_LEDCONTROLLER_H

#include "Arduino.h"

class LedController {
public:
    LedController(int pin);
    void turnOn();
    void turnOff();
    void blinkFast(int times);
    void blinkSlow(int times);

private:
    int ledPin;
};


#endif //ROOTNITY_IOT_ML_LEDCONTROLLER_H
