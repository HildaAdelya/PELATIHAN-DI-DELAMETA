//Inisialisasi pembuatan variable

#define B1 5 
#define B2 6


int incomingByte = 0; // for incoming serial data
int input = 0;

void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 pinMode(B1, OUTPUT);
 pinMode(B2, OUTPUT);
 digitalWrite(B1, LOW);
 digitalWrite(B2, LOW);
 
 Serial.println("Silahkan Pilih salah satu:");
 Serial.println("1.forward");
 Serial.println("2.backward");
 Serial.println("3.stop"); 
}

void loop() {


 analogWrite(B1, 200);
 analogWrite(B2, 0);
 delay(1000);

 analogWrite(B1, 0);
 analogWrite(B2, 190);
 delay(1000);

 digitalWrite(B1, LOW);
 digitalWrite(B2, LOW);
 delay(1000);
}
