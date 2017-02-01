int spd = 100;

void setup() {
    pinMode(13, OUTPUT);
}

void loop() {
    digitalWrite(13, HIGH);
    delay(spd);			  
    digitalWrite(13, LOW); 
    delay(spd);			 
}

