//INISIALISASI

int Merah=PA1;
int Kuning=PA2;
int Hijau=PA3;

int pinIR=PA4;
int pinLDR=PA5;

int Kunci=0;

 void setup() {
 Serial.begin(9600);
 pinMode(pinIR,INPUT);
 pinMode(pinLDR,INPUT);
 pinMode(Merah,OUTPUT); 
 pinMode(Kuning,OUTPUT);
 pinMode(Hijau,OUTPUT); 
}

void loop() {
  //BACA DATA  
  int bacaIR=digitalRead(pinIR);
  int bacaLDR=analogRead(pinLDR);
      bacaLDR=map(bacaLDR ,0,4095,0,255);

  //PRINT SERIAL
  Serial.print("NILAI IR :") ; Serial.print(bacaIR);
  Serial.println();
  Serial.print("NILAI LDR :"); Serial.print(bacaLDR);
  Serial.println();

  //LOGIKA
  if(bacaIR==0 and Kunci==0){
  Kunci=1;
  delay(500);
  }
  else if(Kunci==1 and bacaIR==1){
  if(bacaLDR <=30){
  digitalWrite(Merah,LOW);
  digitalWrite(Kuning,LOW);
  digitalWrite(Hijau,HIGH);
  }else if(bacaLDR >=31 and bacaLDR <=100){
  digitalWrite(Merah,LOW);
  digitalWrite(Kuning,HIGH);
  digitalWrite(Hijau,LOW);
  }else if(bacaLDR >=101){
  digitalWrite(Merah,HIGH);
  digitalWrite(Kuning,LOW);
  digitalWrite(Hijau,LOW);
  }
}
  else if(bacaIR==0 and Kunci==1){
  Kunci=0;
  digitalWrite(Merah,LOW);
  digitalWrite(Kuning,LOW);
  digitalWrite(Hijau,LOW);
  delay(500);
  }
  else{
  }
}
