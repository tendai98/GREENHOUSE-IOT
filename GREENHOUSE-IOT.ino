#include "wifi.h"
#include "dht.h"
#include "http.h"

void setup() {
   WiFi.softAP(AP_SSID, AP_PASS);
   startupServer();
}

void loop() {
   handleClientRequest();
}
