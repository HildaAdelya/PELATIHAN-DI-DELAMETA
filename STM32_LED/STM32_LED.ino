//INISIALISASI
int Tombol1=PA11;
int Tombol2=PA12;
int Tombol3=PA15;

int Merah=PA1;
int Kuning=PA2;
int Hijau=PA3;

void setup() {
  Serial.begin(9600);
  
  pinMode(Merah,OUTPUT);
  pinMode(Kuning,OUTPUT);
  pinMode(Hijau,OUTPUT);
  
  pinMode(Tombol1,INPUT);
  pinMode(Tombol2,INPUT);
  pinMode(Tombol3,INPUT); 
}

void loop() {

 //BACA DATA
  int bacaT1=digitalRead(Tombol1);
  int bacaT2=digitalRead(Tombol2);
  int bacaT3=digitalRead(Tombol3);
  
 //PRINT SERIAL
   Serial.print("T1 :")   ; Serial.print(bacaT1);
   Serial.print(" | T2 :"); Serial.print(bacaT2);
   Serial.print(" | T3 :"); Serial.print(bacaT3);
   Serial.println(); //UNTUK ENTER
   
 //LOGIKA
  if(bacaT1==1){
  digitalWrite(Merah,HIGH);
  }else{
  digitalWrite(Merah,LOW);
  }

  if(bacaT2==1){
  digitalWrite(Kuning,HIGH);
  }else{
  digitalWrite(Kuning,LOW);
  }

  if(bacaT3==1){
  digitalWrite(Hijau,HIGH);
  }else{
  digitalWrite(Hijau,LOW);
  }
}
