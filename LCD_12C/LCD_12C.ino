
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
 Serial.begin(115200); 
 lcd.begin();
}

void loop() {

float suhu=random(21.1,35.10);
  
 lcd.clear(); //Untuk Menghapus karakter pada LCD
 lcd.setCursor(0,0); lcd.print("SUHU");
 lcd.setCursor(4,0); lcd.print(":");
 lcd.setCursor(5,0); lcd.print(suhu);
 lcd.setCursor(8,0); lcd.print("C");
 delay(1000);
 
}
