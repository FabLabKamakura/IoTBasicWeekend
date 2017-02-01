#define BTN 14
#define LED_A 12
#define LED_B 13

void setup() {
  pinMode(LED_A, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(BTN, INPUT);
  Serial.begin(9600);
  digitalWrite(LED_A, LOW);
  digitalWrite(LED_B, LOW);
}

void loop() {
  int state = digitalRead(BTN);
  if(state==LOW){
    digitalWrite(LED_A, HIGH);
    digitalWrite(LED_B, LOW);
    Serial.println("A ON, B OFF");
  } else {
    digitalWrite(LED_A, LOW);
    digitalWrite(LED_B, HIGH);
    Serial.println("B ON, A OFF");
  }
  delay(100);
}
