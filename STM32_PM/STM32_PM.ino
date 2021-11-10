//INISIALISASI

int HILDA_Tombol1=PA11;
int HILDA_Tombol2=PA12;
int HILDA_Tombol3=PA15;

int HILDA_Merah=PA1;
int HILDA_Kuning=PA2;
int HILDA_Hijau=PA3;

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
 if(bacaHILDA_Tombol1==1){
 digitalWrite(HILDA_Merah,HIGH);
 }else{
 digitalWrite(HILDA_Merah,LOW);
 }

 if(bacaHILDA_Tombol2==1){
 digitalWrite(HILDA_Kuning,HIGH);
 }else{
 digitalWrite(HILDA_Kuning,LOW);
 }

 if(bacaHILDA_Tombol3==1){
 digitalWrite(HILDA_Hijau,HIGH);
 }else{
 digitalWrite(HILDA_Hijau,LOW);
 }
}
