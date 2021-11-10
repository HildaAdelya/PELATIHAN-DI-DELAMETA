//Inisialisasi pembuatan variable

#include <SPI.h>
#include <MFRC522.h>

String uidString;

int pinBuzzer=2;
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);     //Create MFRC522 instance.

int SensorIR=3;
String kunci="dikunci";

void setup() {
 Serial.begin(9600); 
 pinMode(pinBuzzer,OUTPUT);
 pinMode(SensorIR,INPUT);
 SPI.begin();   //Initiate SPI bus
 mfrc522. PCD_Init();  //Initiate MFRC522
 bunyibuzzeroke();
}
void bunyibuzzeroke(){
  digitalWrite(pinBuzzer,HIGH);
  delay(100);
  digitalWrite(pinBuzzer,LOW);
  delay(100);
  digitalWrite(pinBuzzer,HIGH);
  delay(100);
  digitalWrite(pinBuzzer,LOW);
  delay(100);
}

void readRFID(){
  mfrc522.PICC_ReadCardSerial();
  // Sound the buzzer when a card is read
  
  //Pembatas bisa dirubah sesuai keinginan,disini yang digunakan "-"
  uidString = String(mfrc522.uid.uidByte[0],HEX) + "-" +
              String(mfrc522.uid.uidByte[1],HEX) + "-" +
              String(mfrc522.uid.uidByte[2],HEX) + "-" +
              String(mfrc522.uid.uidByte[3],HEX);
              uidString.toUpperCase();
}

void bunyibuzzergagal(){
  digitalWrite(pinBuzzer,HIGH);
  delay(1000);
  digitalWrite(pinBuzzer,LOW);
  delay(1000);
}
void loop() {
  int bacaSensorIR=digitalRead(SensorIR);
  
  if (mfrc522.PICC_IsNewCardPresent()&& kunci=="dikunci") {
  readRFID();
  Serial.print("Tag UID: ");
  Serial.println(uidString);
  if(uidString=="6A-A7-D5-80"){
  Serial.println("BERHASIL");
  bunyibuzzeroke();
  kunci="dibuka";
  }else{
  Serial.println("GAGAL");
  bunyibuzzergagal();
  }
 }
 
  if (bacaSensorIR==0 and kunci=="dibuka" ){ 
  kunci="dikunci";
  Serial.println("PALANG DITUTUP");
  delay(500);
  Serial.println("Tempelkan Kartu!");
  delay(500); //Jeda waktu perulagan seama 500 mili detik
  }
 }
