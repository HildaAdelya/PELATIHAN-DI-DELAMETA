int pinFlame =A1;
int pinBuzzer=5;

void setup() {
Serial.begin(9600); 
pinMode(pinBuzzer,OUTPUT);
}

void loop() {
  //BACA DATA
  int bacaFlame=analogRead(pinFlame);
      bacaFlame=map(bacaFlame,24,1016,100,0);
    
  //PRINT SERIAL
  Serial.print("NILAI :");
  Serial.print(bacaFlame);
  Serial.println();

  //LOGIKA
if(bacaFlame==0){
  Serial.println("AMAN");
  digitalWrite(pinBuzzer,LOW);
}else if(bacaFlame >=20 && bacaFlame <=50){
  Serial.println("WARNING SILAHKAN PERIKSA");
  digitalWrite(pinBuzzer,HIGH);
  delay(1000);
  digitalWrite(pinBuzzer,LOW);
  delay(1000);
}else if(bacaFlame >=50){
  Serial.println("WASPADA HARAP MENGUNGSI");
  digitalWrite(pinBuzzer,HIGH);
  delay(50);
  digitalWrite(pinBuzzer,LOW);
  delay(50);
}
  }
