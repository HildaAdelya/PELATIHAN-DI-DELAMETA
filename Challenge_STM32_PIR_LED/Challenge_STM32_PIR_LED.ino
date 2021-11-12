//INISIALISASI
#include <NewPing.h>

int Merah=PA2;
int Kuning=PA3;
int Hijau=PA4;

int pinFlame=PA0;
int Triger=PA5;
int Echo=PA6;
int Batas=200;

int Kunci=0;

NewPing cm(Triger,Echo,Batas);

void setup() {
Serial.begin(9600);
pinMode(pinFlame,INPUT);
pinMode(Merah,OUTPUT);
pinMode(Kuning,OUTPUT);
pinMode(Hijau,OUTPUT);
}

void loop() {
  //BACA DATA
  int bacaFlame=analogRead(pinFlame);
  int bacaJarak=cm.ping_cm();

 //PRINT SERIAL
 Serial.print("NILAI FLAME :");
 Serial.print(bacaFlame);
 Serial.print("| DATA JARAK :");
 Serial.print(bacaJarak);
 Serial.print(" cm");
 Serial.println();

 //LOGIKA
 if(bacaFlame<4000 and Kunci==0){
 Kunci=1;
 delay(1000);
 }
 else if(bacaFlame>=4000 and Kunci==1){
 if(bacaJarak <=20 and bacaJarak!=0 and Kunci==1){ 
 Serial.print("DEKAT");
 digitalWrite(Merah,HIGH);
 digitalWrite(Kuning,HIGH);
 digitalWrite(Hijau,HIGH);
 delay(100);
 digitalWrite(Merah,LOW);
 digitalWrite(Kuning,LOW);
 digitalWrite(Hijau,LOW);
 delay(100);
 }else if(bacaJarak >=21 and bacaJarak <=110){
 Serial.print("SEDANG");
 digitalWrite(Merah,HIGH);
 digitalWrite(Kuning,HIGH);
 digitalWrite(Hijau,HIGH);
 delay(1000);
 digitalWrite(Merah,LOW);
 digitalWrite(Kuning,LOW);
 digitalWrite(Hijau,LOW);
 delay(1000);
 }else if(bacaJarak >=111 or bacaJarak==0){
 Serial.print("JAUH");
 digitalWrite(Merah,HIGH);
 digitalWrite(Kuning,LOW);
 digitalWrite(Hijau,LOW);
 delay(500);
 digitalWrite(Merah,LOW);
 digitalWrite(Kuning,HIGH);
 digitalWrite(Hijau,LOW);
 delay(500);
 digitalWrite(Merah,LOW);
 digitalWrite(Kuning,LOW);
 digitalWrite(Hijau,HIGH);
 delay(500);
 digitalWrite(Merah,LOW);
 digitalWrite(Kuning,HIGH);
 digitalWrite(Hijau,LOW);
 delay(500);
 }
}else if(bacaFlame<4000 and Kunci==1){
  digitalWrite(Merah,LOW);
  digitalWrite(Kuning,LOW);
  digitalWrite(Hijau,LOW);
  Kunci=0;
  delay(500);
}
}
