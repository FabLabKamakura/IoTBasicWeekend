#include <Servo.h>
#include <ESP8266WebServer.h>
#define SSID "FABLABKAMAKURA2_guest"
#define PASS "kamakura_1192"

ESP8266WebServer server(80);
Servo myservo;

void setup(){
  Serial.begin(9600);
  myservo.attach(13);
  myservo.write(20);
  connectWifi();
  server.on("/", handleRoot);
  server.on("/twenty", turn20);
  server.on("/onesixty", turn160);
  server.begin();
}

void loop() {
  server.handleClient();
}

void connectWifi(){
  WiFi.begin(SSID, PASS);
  Serial.println();
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  Serial.println(WiFi.localIP());
}

void handleRoot(){
  myservo.write(90);
  server.send(200, "text/html", "90");
}

void turn20(){
  myservo.write(20);
  server.send(200, "text/plain", "20");
  Serial.println("Turn on 20");
}

void turn160(){
  myservo.write(160);
  server.send(200, "text/plain", "160");
  Serial.println("Turn on 160");
}




