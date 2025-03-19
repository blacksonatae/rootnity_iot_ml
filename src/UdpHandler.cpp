//
// Created by kevin on 19/03/2025.
//

#include "UdpHandler.h"

UdpHandler::UdpHandler(int sendPort, int receivePort) : udpSendPort(sendPort), udpReceivePort(receivePort) {
    udp.begin(udpReceivePort);
}

void UdpHandler::sendEsp32IP(IPAddress ip) {
    String ipInfo = "{\"ip\":\"" + ip.toString() + "\"}";
    udp.beginPacket(IPAddress(255, 255, 255, 255), udpSendPort);
    udp.print(ipInfo);
    udp.endPacket();
    Serial.println("");
}

void UdpHandler::scanAndSendWiFi() {
    DynamicJsonDocument document(1024);
    JsonArray wifiList = document.createNestedArray("wifi");

    Serial.println("");
    int networks = WiFi.scanNetworks();

    for (int i = 0; i < networks; i++) {
        JsonObject wifi = wifiList.createNestedObject();
        wifi["ssid"] = WiFi.SSID(i);
        wifi["rssi"] = WiFi.RSSI(i);
        wifi["secured"] = WiFi.encryptionType(i) != WIFI_AUTH_OPEN;
    }

    String json;
    serializeJson(document, json);

    udp.beginPacket(IPAddress(255, 255, 255, 255), udpSendPort);
    udp.print(json);
    udp.endPacket();
}

String UdpHandler::receiveWiFiCredentials() {
    int packetSize = udp.parsePacket();
    if (packetSize > 0) {
        int len = udp.read(incomingPacket, 255);
        if (len > 0) {
            incomingPacket[len] = '\0';
        }
        return String(incomingPacket);
    }
    return "";
}