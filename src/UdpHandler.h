//
// Created by kevin on 19/03/2025.
//

#ifndef ROOTNITY_IOT_ML_UDPHANDLER_H
#define ROOTNITY_IOT_ML_UDPHANDLER_H

#include "Arduino.h"
#include "WiFiUdp.h"
#include "WiFi.h"
#include "ArduinoJson.h"

class UdpHandler {
public:
    UdpHandler(int sendPort, int receivePort);
    void sendEsp32IP(IPAddress ip);
    void scanAndSendWiFi();
    String receiveWiFiCredentials();

private:
    WiFiUDP udp;
    int udpSendPort;
    int udpReceivePort;
    char incomingPacket[255];
};


#endif //ROOTNITY_IOT_ML_UDPHANDLER_H
