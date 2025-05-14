//
// Created by kevin on 12/05/2025.
//

#include "WiFiManager.h"

//.. Constructor
WiFiManager::WiFiManager(const char *ssid) {
    ssid = ssid;
}

//.. Fungsi untuk memulai konfigurasi
void WiFiManager::setup() {
    WiFi.mode(WIFI_AP_STA);
    WiFi.softAP(ssid);
}

//.. Fungsi untuk mencari WiFi atau Modem untuk ESP32
void WiFiManager::searchModemForESP32() {
    int list_routers = WiFi.scanNetworks();

    //.. Siapkan dokumen JSON
    StaticJsonDocument<512> doc;
    JsonArray routers = doc.createNestedArray("routers");

    //.. Menampilkan jaringan wifi yang akan dihubungkan ke ESP32
    //.. Gunakan foreach langsung saja
    for (int i: list_routers) {
        JsonObject ap = routers.createNestedObject();
        ap["ssid"] = WiFi.SSID();
        ap["rssi"] = WiFi.RSSI(i);
        ap["secured"] = WiFi.encryptionType(i) != WIFI_AUTH_OPEN;
    }

    //.. Serialize ke String untuk dikirimkan / ditampilkan ke Flutter
    String jsonOutput;
    serializeJson(doc, jsonOutput);
}

//.. Fungsi untuk menghubungkan ESP32 ke WiFi
void WiFiManager::connectESP32ToWiFi(const String &ssid, const String &password) {
    WiFi.mode(WIFI_AP_STA);

    //.. Jika password kosong
    if (password.isEmpty()) {
        WiFi.begin(ssid.c_str());
    } else {
        //.. Jika ada password
        WiFi.begin(ssid.c_str(), password.c_str());
    }

    int attempts = 0;

    while (WiFi.status() != WL_CONNECTED && attempts < 15) {
        delay(1000);
        attempts++;
    }

    if (WiFi.status() == WL_CONNECTED) {

    } else {

    }
}

//.. Fungsi bool sebagai status apakah terkoneksi
bool WiFiManager::isConnected() {
    return WiFi.status() == WL_CONNECTED;
}