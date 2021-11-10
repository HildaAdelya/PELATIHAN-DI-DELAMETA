 //INISIALISASI
 #include <OneWire.h>
 #include <DallasTemperature.h>

 int sensorSuhu=2;
 OneWire oneWire(sensorSuhu);
 DallasTemperature sensors(&oneWire);
 int pinBuzzer=5;
 
void setup() {
  Serial.begin(9600);
  sensors.begin();
  pinMode(pinBuzzer,OUTPUT);
}

void loop() {
//BACA SENSOR
sensors.requestTemperatures();
float bacaSuhu=sensors.getTempCByIndex(0);
if(bacaSuhu >=30){
  digitalWrite(pinBuzzer,HIGH);
  delay(500);
  digitalWrite(pinBuzzer,LOW);
  delay(500);
}

//PRINT TO SERIAL
Serial.print("SUHU :");
Serial.print(bacaSuhu);
Serial.print(" c");
Serial.println();
}
