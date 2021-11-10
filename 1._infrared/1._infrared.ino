
int tomboll=3;
int SensorIR=2;

int R=5;
int Y=6;
int G=7;


void setup() {
Serial.begin(9600);
  pinMode(tomboll,INPUT);
  pinMode(SensorIR,INPUT);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);

}

void loop() {
  //BACA DATA
 int bacaTomboll=digitalRead(tomboll);
 int bacaIR=digitalRead(SensorIR);

 //PRINT SERIAL
 Serial.print("tombol 1:");
 Serial.print(bacaTomboll);
 Serial.print(" | sensor IR:");
 Serial.print(bacaIR);
 Serial.println(); //Untuk Enter

 //LOGIKA
 if (bacaIR==0){
  digitalWrite (R,HIGH);
 }else{
  digitalWrite(R,LOW);
 }
}
