//
// Created by kevin on 12/05/2025.
//

#ifndef LEDCONTROLLER_H
#define LEDCONTROLLER_H



class LedController {
private:
    //.. Variabel
    enum {OFF, ON, BLINKING} state;
    unsigned long previousMillis;
    unsigned int onTime, offTime;
    int remainingBlinks;
    int ledPin;

public:

};



#endif //LEDCONTROLLER_H
