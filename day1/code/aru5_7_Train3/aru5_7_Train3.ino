#include <Wire.h>
#include <FaBoProximity_VCNL4010.h>

FaBoProximity fabo;

// 閾値を超えたら処理を実行
int threshold = 100;

void setup() {
  Serial.begin(9600);

  fabo.begin();
}

void loop() {
  // 環境光を測定
  if(fabo.checkAmbiReady()){
    int value = fabo.readAmbi();
    if (value < threshold){
        Serial.print("value is ");
        Serial.print(value);
        Serial.println(" it's dark.");
    }
  }
  delay(1000);
}
