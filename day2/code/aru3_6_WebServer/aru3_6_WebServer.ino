#include <ESP8266WebServer.h>

#define LED 13
#define SSID "FABLABKAMAKURA2_guest"
#define PASS "kamakura_1192"

ESP8266WebServer server(80);

void setup(){
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  connectWiFi();
  server.on("/", handleRoot);
  server.on("/on", switchOnLed);
  server.on("/off", switchOffLed);
  server.begin();
  Serial.println("HTTP server started");
}
void loop() {
  server.handleClient();
}
void connectWiFi(){
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
void handleRoot(){
  server.send(200, "text/plain", "LED");
}

void switchOnLed(){
  digitalWrite(LED, HIGH);
  server.send(200, "text/plain", "ON");
  Serial.println("switch on led");
}
void switchOffLed(){
  digitalWrite(LED, LOW);
  server.send(200, "text/plain", "OFF");
  Serial.println("switch off led");
}

