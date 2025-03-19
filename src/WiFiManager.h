//
// Created by kevin on 18/03/2025.
//

#ifndef ROOTNITY_IOT_ML_WIFIMANAGER_H
#define ROOTNITY_IOT_ML_WIFIMANAGER_H

#include "Arduino.h"
#include <WiFi.h>
#include "LedController.h"


class WiFiManager {
public:
    WiFiManager(const char *apSSID);
    void startAP();
    void connectToWiFi(const String &ssid, const String &password);
    bool isConnected();
    IPAddress getLocalIP();

private:
    const char *ssid;
    LedController ledController;
};


#endif //ROOTNITY_IOT_ML_WIFIMANAGER_H
