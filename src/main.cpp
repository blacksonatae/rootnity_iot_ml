#include "Arduino.h"
#include "WiFiManager.h"
#include "UdpHandler.h"

const char *ssid = "Sabba-12";
const int udpPort = 4210;
const int udpReceivePort = 4211;

WiFiManager wiFiManager(ssid);
UdpHandler udpHandler(udpPort, udpReceivePort);

void setup() {
    Serial.begin(115200);

    wiFiManager.startAP();
    udpHandler.sendEsp32IP(WiFi.softAPIP());

    delay(3000);
}

void loop() {
    String credentials = udpHandler.receiveWiFiCredentials();
    if (!credentials.isEmpty()) {
        Serial.println("Received WiFi credentials: " + credentials);
        // Process the credentials here
        DynamicJsonDocument document(512);
        DeserializationError error = deserializeJson(document, credentials);
        if (!error) {
            String ssid = document["ssid"].as<String>();
            String password = document["password"].isNull() ? "" : document["password"].as<String>();
            wiFiManager.connectToWiFi(ssid, password);
        }
    }
    delay(5000);
}