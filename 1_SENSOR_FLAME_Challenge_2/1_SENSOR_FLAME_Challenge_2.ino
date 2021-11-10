int pinFlame =A1;
int pinLDR=A0;
int pinPIR=2;
int pinBuzzer=5;
int R=9;
int Y=10;
int G=11;

void setup() {
Serial.begin(9600); 
pinMode(pinBuzzer,OUTPUT);
pinMode(pinPIR,INPUT);
pinMode(R,OUTPUT);
pinMode(Y,OUTPUT);
pinMode(G,OUTPUT);

}

void loop() {
  //BACA DATA
  int bacaFlame=analogRead(pinFlame);
  int bacaLDR=analogRead(pinLDR);
  int bacaPIR=digitalRead(pinPIR);
      bacaFlame=map(bacaFlame,24,1016,100,0);
      bacaLDR=map(bacaLDR,30,1010,0,255);
      
  //PRINT SERIAL
  Serial.print("NILAI :");
  Serial.print(bacaFlame);
  Serial.print(" | LDR :");
  Serial.print(bacaLDR);
  Serial.print("| PIR :");
  Serial.print(bacaPIR);
  Serial.println();
  
 //LOGIKA LDR
analogWrite(R,bacaLDR);

  //LOGIKA FLAME
if(bacaFlame==0){
  Serial.println("AMAN BANGET");
  digitalWrite(pinBuzzer,LOW);
  digitalWrite(G,HIGH);
  digitalWrite(Y,LOW);
}else if(bacaFlame >=20 && bacaFlame <=50){
  digitalWrite(Y,HIGH);
  digitalWrite(R,LOW);
  digitalWrite(G,LOW);
  Serial.println("WARNING SILAHKAN PERIKSA");
  digitalWrite(pinBuzzer,HIGH);
  delay(1000);
  digitalWrite(pinBuzzer,LOW);
  delay(1000);
}else if(bacaFlame >=50){
  digitalWrite(Y,HIGH);
  digitalWrite(G,HIGH);
  digitalWrite(R,LOW);
  Serial.println("WASPADA HARAP MENGUNGSI");
  digitalWrite(pinBuzzer,HIGH);
  delay(50);
  digitalWrite(pinBuzzer,LOW);
  delay(50);
}
  }
