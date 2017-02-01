#include <ESP8266WebServer.h>

#define SSID "FABLABKAMAKURA2_guest"
#define PASS "kamakura_1192"

#define LED_A 12
#define LED_B 13

ESP8266WebServer server(80);

char* html = "<!DOCTYPE html>\
<head>\
  <meta charset='UTF-8'>\
  <meta name='viewport' content='width=device-width'>\
</head>\
<body>\
  <h1><a href='/both'>BOTH</a></h1>\
  <h1><a href='/a'>LED_A</a></h1>\
  <h1><a href='/b'>LED_B</a></h1>\
  <h1><a href='/off'>OFF</a></h1>\
</body>\
</html>";

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
  server.send(200, "text/html", html);
}

void turnOnBoth(){  
  digitalWrite(LED_A, HIGH);
  digitalWrite(LED_B, HIGH);
  server.send(200, "text/html", html);
  Serial.println("turn on both");
}

void turnOnA(){  
  digitalWrite(LED_A, HIGH);
  digitalWrite(LED_B, LOW);
  server.send(200, "text/html", html);
  Serial.println("turn on a");
}

void turnOnB(){  // LED ON
  digitalWrite(LED_A, LOW);
  digitalWrite(LED_B, HIGH);
  server.send(200, "text/html", html);
  Serial.println("turn on b");
}

void turnOff(){  // LED OFF
  digitalWrite(LED_A, LOW);
  digitalWrite(LED_B, LOW);
  server.send(200, "text/html", html);
  Serial.println("turn off");
}

void setup(){
  Serial.begin(9600);
  pinMode(LED_A, OUTPUT);
  pinMode(LED_B, OUTPUT);
  digitalWrite(LED_A, LOW);
  digitalWrite(LED_B, LOW);

  connectWiFi();
  server.on("/", handleRoot);
  server.on("/both", turnOnBoth);
  server.on("/a", turnOnA);
  server.on("/b", turnOnB);
  server.on("/off", turnOff);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}

