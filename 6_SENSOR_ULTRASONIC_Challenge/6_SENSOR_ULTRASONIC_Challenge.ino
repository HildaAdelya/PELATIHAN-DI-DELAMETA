 //INISIALISASI
 #include <NewPing.h>

 int pinBuzzer=5;
 int triger=4;
 int echo=3;
 int batas=400;
 int R=9;
 int Y=10;
 int G=11;

 NewPing cm(triger,echo,batas);
 
 
void setup() {
  Serial.begin(9600);
  pinMode(pinBuzzer,OUTPUT);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
}

void loop() {
  
//BACA SENSOR
int bacaJarak=cm.ping_cm();
if(bacaJarak <=20 and bacaJarak !=0){
  Serial.println("BERHENTI");
  digitalWrite(R,HIGH);
  digitalWrite(Y,LOW);
  digitalWrite(G,LOW);
  digitalWrite(pinBuzzer,HIGH);
  delay (50);
  digitalWrite(pinBuzzer,LOW);
  delay(50);
}if(bacaJarak >=21 && bacaJarak <=70){
  Serial.println("BAHAYA");
  digitalWrite(Y,HIGH);
  digitalWrite(R,LOW);
  digitalWrite(G,LOW);
  digitalWrite(pinBuzzer,HIGH);
  delay (500);
  digitalWrite(pinBuzzer,LOW);
  delay(500);
}else if(bacaJarak >=71){
  Serial.println("AMAN");
  digitalWrite(G,HIGH);
  digitalWrite(R,LOW);
  digitalWrite(Y,LOW);
}

//PRINT TO SERIAL
Serial.print("Data Jarak :");
Serial.print(bacaJarak);
Serial.print(" cm");
Serial.println();
}
