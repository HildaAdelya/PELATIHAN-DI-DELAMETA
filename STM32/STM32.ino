
void setup() {
  pinMode(PC13,OUTPUT);
  pinMode(PA1,OUTPUT);
  pinMode(PA2,OUTPUT);
  pinMode(PA3,OUTPUT); 


}

void loop() {
  digitalWrite(PC13,HIGH);
  delay(1000);
  digitalWrite(PC13,LOW);
  delay(1000);

  digitalWrite(PA1,HIGH);
  delay(1000);
  digitalWrite(PA1,LOW);
  delay(1000);
  digitalWrite(PA2,HIGH);
  delay(1000);
  digitalWrite(PA2,LOW);
  delay(1000);
  digitalWrite(PA3,HIGH);
  delay(1000);
  digitalWrite(PA3,LOW);
  delay(1000);
}
