//INISIALISASI

int Merah=PA1;
int Kuning=PA2;
int Hijau=PA3;

int LDR=PA4;

void setup() {
  Serial.begin(9600);
  pinMode(LDR,INPUT);
  pinMode(Merah,OUTPUT);
  pinMode(Kuning,OUTPUT);
  pinMode(Hijau,OUTPUT);
}

void loop() {
  //BACA DATA
    int bacaLDR=analogRead(LDR);
        bacaLDR=map(bacaLDR,0,4095,0,255);

  //PRINT SERIAL
    Serial.print("NILAI :");
    Serial.print(bacaLDR);
    Serial.println();

 //LOGIKA
    analogWrite(Merah,bacaLDR);
}
