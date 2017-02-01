#include <ESP8266WiFi.h>

#define SSID "FABLABKAMAKURA2_guest"
#define PASS "kamakura_1192"

void setup() {
  Serial.begin(9600);
  WiFi.begin(SSID, PASS);
  Serial.println();
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi connected");
  Serial.println(WiFi.localIP());
 }

void loop() {
}
