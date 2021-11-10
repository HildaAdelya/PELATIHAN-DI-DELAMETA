
#include <Servo.h

int outServo=10; 
Servo myservo;

void setup() {
 Serial.begin(115200); 
 myservo.attach(outServo); 
}

void loop() {

 myservo.write(0); //0-180
 delay(1000); 
 myservo.write(180); //0-180
 delay(1000); 
}
