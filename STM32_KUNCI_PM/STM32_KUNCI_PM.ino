 //INISIALISASI

int HILDA_Tombol1=PA11;
int HILDA_Tombol2=PA12;
int HILDA_Tombol3=PA15;

int HILDA_Merah=PA1;
int HILDA_Kuning=PA2;
int HILDA_Hijau=PA3;

int Kunci1=0;
int Kunci2=0;
int Kunci3=0;

void setup() {
  Serial.begin(9600);

  pinMode(HILDA_Tombol1,INPUT);
  pinMode(HILDA_Tombol2,INPUT);
  pinMode(HILDA_Tombol3,INPUT);

  pinMode(HILDA_Merah,OUTPUT);
  pinMode(HILDA_Kuning,OUTPUT);
  pinMode(HILDA_Hijau,OUTPUT);
}

void loop() {

 //BACA DATA
  int bacaHILDA_Tombol1=digitalRead(HILDA_Tombol1);
  int bacaHILDA_Tombol2=digitalRead(HILDA_Tombol2);
  int bacaHILDA_Tombol3=digitalRead(HILDA_Tombol3);

 //PRINT SERIAL
  Serial.print("HILDA_Tombol1 :")  ; Serial.print(bacaHILDA_Tombol1);
  Serial.print("| HILDA_Tombol2 :"); Serial.print(bacaHILDA_Tombol2);
  Serial.print("| HILDA_Tombol3 :"); Serial.print(bacaHILDA_Tombol3);
  Serial.println();

 //LOGIKA

 //LOGIKA HILDA_TOMBOL1
 if(bacaHILDA_Tombol1==1 and Kunci1==0){
 digitalWrite(HILDA_Merah,HIGH);
 Kunci1=1;
 delay(100);
 }else if(bacaHILDA_Tombol1==1 and Kunci1==1){
 digitalWrite(HILDA_Merah,LOW);
 Kunci1=0;
 delay(100);
 }

 //LOGIKA HILDA_TOMBOL2
 if(bacaHILDA_Tombol2==1 and Kunci2==0){
 digitalWrite(HILDA_Kuning,HIGH);
 Kunci2=1;
 delay(100);
 }else if(bacaHILDA_Tombol2==1 and Kunci2==1){
 digitalWrite(HILDA_Kuning,LOW);
 Kunci2=0;
 delay(100);
 }

 //LOGIKA HILDA_TOMBOL3
 if(bacaHILDA_Tombol3==1 and Kunci3==0){
 digitalWrite(HILDA_Hijau,HIGH);
 Kunci3=1;
 delay(100);
 }else if(bacaHILDA_Tombol3==1 and Kunci3==1){
 digitalWrite(HILDA_Hijau,LOW);
 Kunci3=0;
 delay(100);
 }
}
