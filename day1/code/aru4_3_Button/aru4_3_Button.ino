// File : Button.ino
#define BTN 14
#define LED 13

void setup(){
    pinMode(LED, OUTPUT);
    pinMode(BTN, INPUT);
    Serial.begin(9600);
    digitalWrite(LED, LOW);
}

void loop(){
    int state = digitalWrite(BTN);
    if(state==LOW){
        Serial.println("Turn on LED");
        digitalWrite(LED, HIGH);
    } else {
        digitalWrite(LED, LOW);
    }
    delay(100);
}
