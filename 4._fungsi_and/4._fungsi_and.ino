
int tomboll=2;
int tombolll=3;
int R=5;


void setup() {
Serial.begin(9600);
  pinMode(tomboll,INPUT);
  pinMode(tombolll,INPUT);
  pinMode(R,OUTPUT);
  

}

void loop() {
 int bacaTomboll=digitalRead(tomboll);
 Serial.println("kondisi tombol:" +String(bacaTomboll));
  int bacaTombolll=digitalRead(tombolll);
 Serial.println("kondisi tombol:" +String(bacaTombolll));

  if(bacaTomboll==1 and bacaTombolll==1){
  digitalWrite(R,HIGH);
 }else{
  digitalWrite(R,LOW);
 }
}
