//INISIALISASI  
#include <NewPing.h>

int Merah=PA2;
int Kuning=PA3;
int Hijau=PA4;

int pinPIR=PA1;
int pinFlame=PA0;
int Triger=PA5;
int Echo=PA6;
int Batas=400;

NewPing cm(Triger,Echo,Batas);

void setup() {
  Serial.begin(9600);
  pinMode(pinPIR,INPUT);
  pinMode(pinFlame,INPUT);
  pinMode(Merah,OUTPUT);
  pinMode(Kuning,OUTPUT);
  pinMode(Hijau,OUTPUT);
}

void loop() {
  //BACA DATA
  int bacaFlame=analogRead(pinFlame);
      bacaFlame=map(bacaFlame,200,4095,100,0);
  int bacaPIR=digitalRead(pinPIR);
  int bacaJarak=cm.ping_cm();

  //PRINT SERIAL
  Serial.print("FLAME :");
  Serial.print(bacaFlame);
  Serial.print(" | PIR :");
  Serial.print(bacaPIR);
  Serial.print(" | Data Jarak :");
  Serial.print(bacaJarak);
  Serial.print(" cm");
  Serial.println();

  //LOGIKA
  
}
