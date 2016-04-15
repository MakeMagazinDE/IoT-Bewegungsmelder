// Bewegungsmelder im IoT mit ESP-8266

#include <ESP8266WiFi.h>

const char* ssid = "f...e";
const char* password = "p...e";
const char* server = "62.108.44.182";
char httpreq[100];
WiFiClient client;
const int led_pin = 1;

void setup() {
  uint8_t mac[6];
  pinMode(led_pin, OUTPUT);
  digitalWrite(led_pin, 0);
  WiFi.macAddress(mac);
  sprintf(httpreq, "GET /iotllb?mac=%02X-%02X-%02X-%02X-%02X-%02X HTTP/1.0\r\n\r\n",
    mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
}

void loop() {
  uint8_t mac[6], i;
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(led_pin, !digitalRead(led_pin));
    delay(500);
  }
  digitalWrite(led_pin, 0);
  if (client.connect(server, 80))
    client.print(httpreq), client.stop(), WiFi.disconnect(), digitalWrite(led_pin, 1);
  delay(30000);
}


