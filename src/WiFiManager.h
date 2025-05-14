//
// Created by kevin on 12/05/2025.
//

#ifndef WIFIMANAGER_H
#define WIFIMANAGER_H

#include "Arduino.h"
#include "WiFi.h"
#include "ArduinoJson.h"
#include "LedController.h"

class WiFiManager {
private:
    const char *ssid;
    const char *password;

public:
    //.. Constructor
    explicit WiFiManager(const char *ssid);
    //.. Setup
    void setup();
    //.. Search WiFi or Modem For ESP32
    void searchModemForESP32();
    //.. Connect ESP32 to WiFi
    void connectESP32ToWiFi(const String &ssid, const String &password);
    //.. Periksa apakah wifi sudah terhubung
    void isConnected();
};

#endif //WIFIMANAGER_H
