//INISIALISASI

int Merah=PA1;
int Kuning=PA2;
int Hijau=PA3;

int pinIR=PA4;

int Kunci=0;

void setup() {
  Serial.begin(9600);
  pinMode(pinIR,INPUT);
  pinMode(Merah,OUTPUT);
  pinMode(Kuning,OUTPUT);
  pinMode(Hijau,OUTPUT);
}

void loop() {
  //BACA DATA
    int bacaIR=digitalRead(pinIR);

 //PRINT SERIAL
    Serial.print("Sensor IR :");
    Serial.print(bacaIR); 
    Serial.println();

 //BACA LOGIKA
    if(bacaIR==0 and Kunci==0){
    digitalWrite(Merah,HIGH);
    Kunci=1;
    delay(500);
    }else if(bacaIR==0 and Kunci==1){
    digitalWrite(Merah,LOW);
    Kunci=0;
    delay(500);
    }
}
