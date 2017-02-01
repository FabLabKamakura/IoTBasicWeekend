// LedBlink.ino

int spd = 1000;

void setup() {
    // ESPrの13番ピンを出力に設定
    pinMode(12, OUTPUT);
}

void loop() {
    digitalWrite(12, HIGH);  //光る
    delay(spd);     //1秒待つ
    digitalWrite(12, LOW);  //消える
    delay(spd);     //1秒待つ
}
