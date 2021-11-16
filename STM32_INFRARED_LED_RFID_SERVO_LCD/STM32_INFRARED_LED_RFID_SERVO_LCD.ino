
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

//INISIALISASI

int pinIR=PA4;
int Merah=PA1;
int Kuning=PA2;
int Hijau=PA3;
int outServo=PA0;

#define SS_PIN PB1
#define RST_PIN PB0

MFRC522 mfrc522(SS_PIN,RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16,2);
Servo myservo;

String uidString;
int kunci=0;

void setup() {
  Serial.begin(9600);
  pinMode(pinIR,INPUT);
  pinMode(Merah,OUTPUT); 
  pinMode(Kuning,OUTPUT);
  pinMode(Hijau,OUTPUT);
  lcd.begin();
  
  lcd.setCursor(1,0); lcd.print("SELAMAT DATANG");
  lcd.setCursor(0,1); lcd.print("TEMPELKAN KARTU!");
  SPI.begin();
  mfrc522.PCD_Init();
  myservo.attach(outServo);
}

void readRFID(){
  mfrc522.PICC_ReadCardSerial();

  uidString = String(mfrc522.uid.uidByte[0],HEX) + "-" +
              String(mfrc522.uid.uidByte[1],HEX) + "-" +
              String(mfrc522.uid.uidByte[2],HEX) + "-" +
              String(mfrc522.uid.uidByte[3],HEX) ;
              uidString.toUpperCase();
}
void loop() {
  int bacaIR=digitalRead(pinIR);

  if (mfrc522.PICC_IsNewCardPresent() and kunci==0){
  readRFID();
  Serial.print("Tag UID: ");
  Serial.println(uidString);
  if(uidString=="4A-51-6E-AE"){
  lcd.clear();
  lcd.setCursor(4,0); lcd.print("BERHASIL");
  digitalWrite(Merah,LOW);
  digitalWrite(Kuning,LOW);
  digitalWrite(Hijau,HIGH);
  kunci=1;
  delay(100);
  lcd.setCursor(1,1); lcd.print("SILAHKAN MASUK");
  myservo.write(90);
  delay(500);
  myservo.write(0);
  delay(1000);
  }else{
  lcd.clear();
  lcd.setCursor(5,0); lcd.print("GAGAL");
  lcd.setCursor(0,1); lcd.print("BELUM TERDAFTAR");
  delay(1000);
  digitalWrite(Merah,HIGH);
  digitalWrite(Kuning,LOW);
  digitalWrite(Hijau,LOW);  
  myservo.write(90);
  lcd.clear();
  lcd.setCursor(1,0); lcd.print("SELAMAT DATANG");
  lcd.setCursor(0,1); lcd.print("TEMPELKAN KARTU!");
  }
}

  if (bacaIR==0 and kunci==1){
  kunci=0;
  delay(200);
  myservo.write(90);
  lcd.clear();
  lcd.setCursor(1,0); lcd.print("PALANG DITUTUP");
  delay(1000);
  lcd.clear();
  lcd.setCursor(1,0); lcd.print("SELAMAT DATANG");
  lcd.setCursor(0,1); lcd.print("TEMPELKAN KARTU!");
  digitalWrite(Kuning,HIGH);
  delay(200);
  digitalWrite(Kuning,LOW);
  digitalWrite(Merah,HIGH);
  digitalWrite(Hijau,LOW);
 }
}
