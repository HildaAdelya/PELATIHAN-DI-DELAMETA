
int tomboll=2;
int tombolll=3;
int tombollll=4;
int R=5;
int Y=6;
int G=7:


void setup() {
Serial.begin(9600);
  pinMode(tomboll,INPUT);
  pinMode(tombolll,INPUT);
  pinMode(tombollll,INPUT);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);

}

void loop() {
 int bacaTomboll=digitalRead(tomboll);
 Serial.println("kondisi tombol:" +String(bacaTomboll));
  int bacaTombolll=digitalRead(tombolll);
 Serial.println("kondisi tombol:" +String(bacaTombolll));
int bacaTombolll=digitalRead(tombollll);
 Serial.println("kondisi tombol:" +String(bacaTombollll));
 
  if(bacaTomboll==1){
  digitalWrite(R,HIGH);
 }else{
  digitalWrite(R,LOW);
 }
}
