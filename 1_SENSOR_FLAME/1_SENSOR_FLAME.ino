int pinFlame =A1;
int pinBuzzer=5;

void setup() {
Serial.begin(9600); 
pinMode(pinBuzzer,OUTPUT);
}

void loop() {
  //BACA DATA
  int bacaFlame=analogRead(pinFlame);
      bacaFlame=map(bacaFlame,1016,24,0,100);
    
  //PRINT SERIAL
  Serial.print("NILAI :");
  Serial.print(bacaFlame);
  Serial.println();

  //LOGIKA
  analogWrite(pinBuzzer,bacaFlame);
  }
