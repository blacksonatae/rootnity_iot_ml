//
// Created by kevin on 19/03/2025.
//

#include "LedController.h"

LedController::LedController(int pin) : ledPin(pin) {
    pinMode(ledPin, OUTPUT);
}

//.. Fungsi untuk menghidupkan lampu led
void LedController::turnOn() {
    digitalWrite(ledPin, HIGH);
}

//.. Fungsi untuk mematikan lampu led
void LedController::turnOff() {
    digitalWrite(ledPin, LOW);
}

//.. Fungsi kedipan lampu yang cepat
void LedController::blinkFast(int times) {
    for (int i = 0; i < times; ++i) {
        digitalWrite(ledPin, HIGH);
        delay(200);
        digitalWrite(ledPin, LOW);
        delay(200);
    }
}

//.. Fungsi kedipan lampu yang lambat
void LedController::blinkSlow(int times) {
    for (int i = 0; i < times; ++i) {
        digitalWrite(ledPin, HIGH);
        delay(750);
        digitalWrite(ledPin, LOW);
        delay(750);
    }
}