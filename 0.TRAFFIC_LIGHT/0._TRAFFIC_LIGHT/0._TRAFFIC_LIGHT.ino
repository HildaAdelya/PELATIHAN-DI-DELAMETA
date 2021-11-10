int R=5;
int Y=6;
int G=7;

void setup() {
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
}

void loop() {
 digitalWrite(5,HIGH);
 delay(5000);
 digitalWrite(5,LOW);
 delay(2000);
 digitalWrite(6,HIGH);
 delay(1000);
 digitalWrite(6,LOW);
 delay(1000);
 digitalWrite(7,HIGH);
 delay(6000);
 digitalWrite(7,LOW);
 delay(3000);
 digitalWrite(6,HIGH);
 delay(1000);
 digitalWrite(6,LOW);
 delay(1000);
}
