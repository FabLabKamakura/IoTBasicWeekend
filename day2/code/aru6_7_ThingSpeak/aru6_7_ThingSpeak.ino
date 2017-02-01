#include <ESP8266WiFi.h>
#include <FaBoProximity_VCNL4010.h>

FaBoProximity fabo;

#define SSID "FABLABKAMAKURA2_guest"
#define PASS "kamakura_1192"
#define HOST "api.thingspeak.com"
#define THINGSPEAK_KEY "xxxxxxxx"
#define CHANNEL "xxxxxxxx"

void connectWiFi(){
  WiFi.begin(SSID, PASS); 
  while (WiFi.status() != WL_CONNECTED) { 
    delay(500);Serial.print(".");
  }
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(9600);
  connectWiFi();
  fabo.begin();
}

void loop() {
  WiFiClient client;     
  const int httpPort = 80;
  if (!client.connect(HOST,httpPort)){
    Serial.println("connection failed");
    return;
  }
  delay(10); 

  int value = 0;
  if(fabo.checkAmbiReady()){
    value = fabo.readAmbi();
  }
  String ambi = String(value);
  Serial.println(ambi);

  String url = "/update?key=";
  url += THINGSPEAK_KEY;
  url += "&field1=";
  url += ambi;

  client.print(String("GET ")
    + url 
    + " HTTP/1.1\r\n"
    + "Host: " 
    + HOST 
    + "\r\n" 
    + "Connection: close\r\n\r\n");
  delay(10);

  while(client.available()){                     
    String line = client.readStringUntil('\r'); 
    Serial.print(line);
  }
  delay(3000);
}





