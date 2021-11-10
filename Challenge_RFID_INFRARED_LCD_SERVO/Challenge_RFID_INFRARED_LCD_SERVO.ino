
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

String uidString;

int pinBuzzer=2;
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);     //Create MFRC522 instance.

int SensorIR=3;
String kunci="dikunci";

int outServo=4; 
Servo myservo;

void setup() {
 Serial.begin(9600); 
 pinMode(pinBuzzer,OUTPUT);
 pinMode(SensorIR,INPUT);
 SPI.begin();   //Initiate SPI bus
 mfrc522. PCD_Init();  //Initiate MFRC522
 lcd.begin();
 bunyibuzzeroke();
 lcd.clear();
 lcd.setCursor(1,0); lcd.print("SELAMAT DATANG");
 lcd.setCursor(0,1); lcd.print("TEMPELKAN KARTU!"); 
 myservo.attach(outServo); 
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
  lcd.clear();  
  lcd.setCursor(4,0); lcd.print("BERHASIL");
  bunyibuzzeroke();
  kunci="dibuka";
  delay(100);
  lcd.setCursor(1,1); lcd.print("SILAHKAN MASUK");
  myservo.write(90);
  delay(500); 
  myservo.write(0);
  delay(1000); 
  }else{
  lcd.clear();
  lcd.setCursor(5,0); lcd.print("GAGAL");
  delay(100);
  lcd.setCursor(0,1); lcd.print("BELUM TERDAFTAR");
  bunyibuzzergagal();
  myservo.write(90);
  lcd.clear();
  lcd.setCursor(1,0); lcd.print("SELAMAT DATANG");
  lcd.setCursor(0,1); lcd.print("TEMPELKAN KARTU!"); 
  }
 }
 
  if (bacaSensorIR==0 and kunci=="dibuka" ){ 
  kunci="dikunci";
  delay (200);
  myservo.write(90);
  lcd.clear();
  lcd.setCursor(1,0); lcd.print("PALANG DITUTUP");
  delay(1000);
  lcd.clear();
  lcd.setCursor(1,0); lcd.print("SELAMAT DATANG");
  lcd.setCursor(0,1); lcd.print("TEMPELKAN KARTU!");
  }
 }
