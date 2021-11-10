//Inisialisasi pembuatan variable

#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
int pinBuzzer=2;

MFRC522 mfrc522(SS_PIN, RST_PIN); 

void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 SPI.begin(); // Initiate SPI bus
 mfrc522.PCD_Init(); // Initiate MFRC522
 pinMode(pinBuzzer,OUTPUT);
}

void loop() {
 //Program yang akan dijalankan berulang-ulang
 if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
 // Select one of the cards
 if ( ! mfrc522.PICC_ReadCardSerial()) {return;}
 
 //Show UID on serial monitor
 Serial.print("UID tag :");
 String content= "";
 byte letter;
 for (byte i = 0; i < mfrc522.uid.size; i++) 
 {
 Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
 Serial.print(mfrc522.uid.uidByte[i], HEX);
 content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : ""));
 content.concat(String(mfrc522.uid.uidByte[i], HEX));
 }
 
 Serial.println();
 Serial.print("Message : ");
 content.toUpperCase();
 if (content== "047A461A015D80") //Sesuaikan dengan ID kartu anda
 {
 Serial.println("Selamat datang HILDA!!!");
  buzzeroke();
 }else if(content== "0AA89015"){
  Serial.println("Selamat datang HILDA ADELYA!!!");
 buzzeroke();
 }
 else{
 Serial.println("Kartu Belum Terdaftar!");
 digitalWrite(pinBuzzer,HIGH);
 delay(1000);
 digitalWrite(pinBuzzer,LOW);
 delay(1000);
 }
 Serial.println("Tempelkan Kartu!");
 delay(500); //Jeda waktu perulagan seama 500 mili detik
}

void buzzeroke(){
 digitalWrite(pinBuzzer,HIGH);
 delay(50);
 digitalWrite(pinBuzzer,LOW);
 delay(50);
 digitalWrite(pinBuzzer,HIGH);
 delay(50);
 digitalWrite(pinBuzzer,LOW);
 delay(50);
}
