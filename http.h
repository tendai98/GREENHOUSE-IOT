#include <ESP8266WebServer.h>
#include "ph.h"
#include "dht.h"

#define HTTP_PORT       80
#define DEFAULT_MIME    "text/plain"
#define HTTP_OK_CODE    200
#define HTTP_NOT_FOUND  404
#define SENSOR_ID       "SENSOR-ID:00112233"

ESP8266WebServer server(HTTP_PORT);
String data;

float tempValue = 20;
float humidityValue = 65;

void getData(){
   tempValue = getTemperature();
   humidityValue = getHumidity();
   data = String(readPhValue(SENSOR_GPIO))+":"+String(tempValue)+":"+String(humidityValue);
   server.send(HTTP_OK_CODE, DEFAULT_MIME, data);  
}

void getId(){
  server.send(HTTP_OK_CODE, DEFAULT_MIME, SENSOR_ID);
}

void resetSystem(){
  ESP.reset();
}

void sendEmptyResponse(){
  server.send(HTTP_NOT_FOUND, DEFAULT_MIME, "");
}

void startupServer(){
  initSensor();
  server.on("/id", getId);
  server.on("/data", getData);
  server.on("/reset", resetSystem);
  server.onNotFound(sendEmptyResponse);
  server.begin();
}

void handleClientRequest(){
  server.handleClient();
}
