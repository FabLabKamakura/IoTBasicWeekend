#include <ESP8266WebServer.h>
#include <FaBoProximity_VCNL4010.h>

ESP8266WebServer server(80);
FaBoProximity fabo;

#define SSID "FABLABKAMAKURA2_guest"
#define PASS "kamakura_1192"

char* html = "<!DOCTYPE html>\
<html>\
<head>\
  <meta http-equiv='refresh' content='1' charset='UTF-8'>\
  <meta name='viewport' content='width=device-width'>\
</head>\
<body>\
  <h1> Value: %d</h1>\
</body>\
</html>";

void setup(){
  Serial.begin(9600);
  initWiFi();
  server.on("/", handleRoot);
  server.begin();
  fabo.begin();
}

void loop(){
  server.handleClient();
}  

void initWiFi(){
  WiFi.begin(SSID, PASS);
  if(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi connected");
  Serial.println(WiFi.localIP());
}

void handleRoot(){
  int value;
  char temp[400];

  if(fabo.checkAmbiReady()){
    value = fabo.readAmbi();
  }
  snprintf(temp, 400, html, value); 
  server.send(200, "text/html", temp);
}


