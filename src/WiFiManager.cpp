//
// Created by kevin on 18/03/2025.
//

#include "WiFiManager.h"

WiFiManager::WiFiManager(const char *apSSID) : ssid(apSSID), ledController(2) {}

void WiFiManager::startAP() {
    WiFi.mode(WIFI_AP_STA);
    WiFi.softAP(ssid);
}

void WiFiManager::connectToWiFi(const String &ssid, const String &password) {
    ledController.blinkFast(5);
    WiFi.mode(WIFI_AP_STA);
    WiFi.begin(ssid.c_str(), password.c_str());

    int attempts = 0;

    while (WiFi.status() != WL_CONNECTED && attempts < 15) {
        delay(1000);
        attempts++;
    }

    if (WiFi.status() == WL_CONNECTED) {
        ledController.blinkSlow(3);
    } else {
        ledController.turnOff();
    }
}

bool WiFiManager::isConnected() {
    return WiFi.status() == WL_CONNECTED;
}

IPAddress WiFiManager::getLocalIP() {
    return WiFi.localIP();
}
