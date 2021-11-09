#include <LiquidCrystal_I2C.h>

//Download Library LiquidCrystal_I2C
#include <LiquidCrystal_I2C.h>
//Inisialisasi pembuatan variable
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(9600); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 lcd.begin();
}
23
void loop() {
 //Program yang akan dijalankan berulang-ulang
 lcd.clear(); //Untuk Menghapus karakter pada LCD
 lcd.setCursor(0,0); lcd.print(" TUTORIAL BY");
 lcd.setCursor(0,1); lcd.print("Interactive Robotics");
 delay(1000); //Jeda waktu perulagan seama 1000 mili detik
}
