#include <Wire.h>
#include <FaBoProximity_VCNL4010.h>

FaBoProximity fabo;

void setup() {
  Serial.begin(9600);

  fabo.begin();
}
void loop() {
  // 環境光を測定
  if(fabo.checkAmbiReady()){
    int value = fabo.readAmbi();
    Serial.print("ambi:");
    Serial.println(value);
  }
  delay(1000);
}

