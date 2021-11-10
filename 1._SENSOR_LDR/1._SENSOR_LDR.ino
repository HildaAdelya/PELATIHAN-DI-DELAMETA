int pinLDR =A0;
int pinR =3;

void setup() {
Serial.begin(9600); 
pinMode(pinR,OUTPUT);
}

void loop() {
  //BACA DATA
  int bacaLDR=analogRead(pinLDR);
      bacaLDR=map(bacaLDR,36,649,0,255);
    
  //PRINT SERIAL
  Serial.print("NILAI :");
  Serial.print(bacaLDR);
  Serial.println();

  //LOGIKA
  analogWrite(pinR,bacaLDR);
  }
