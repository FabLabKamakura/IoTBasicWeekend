#include <Servo.h> 
 
Servo myservo;  

void setup() 
{ 
  Serial.begin(9600);
  myservo.attach(13);  // attaches the servo on GIO2 to the servo object 
  myservo.write(90);
} 
 
void loop() 
{ 
  char s = Serial.read();
  if(s=='a'){
    myservo.write(20);
  } else if(s=='s'){
    myservo.write(90);
  } else if(s=='d'){
    myservo.write(160);
  }
  
} 

