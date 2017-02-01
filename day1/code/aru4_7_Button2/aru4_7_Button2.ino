#define BTN 14
#define LED 13
int oldState = HIGH;

void setup(){
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT);
  Serial.begin(9600);
  digitalWrite(LED, LOW);
}
void loop(){
  int state = digitalRead(BTN);
  if(state==LOW && oldState==HIGH){
    Serial.println("Turn on LED");
     digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
  oldState = state;
  delay(100);
}
