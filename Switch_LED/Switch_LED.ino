#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int ledM =2;
int ledK =3;
int ledH =4;
int buttonKiri =5; 
int buttonKanan=6;
int i =0;
int hasilbuttonKiri;
int hasilbuttonKanan;

void setup() {
  Serial.begin(9600);
  pinMode(ledM,OUTPUT);
  pinMode(ledK,OUTPUT);
  pinMode(ledH,OUTPUT);
  pinMode(buttonKiri,INPUT);
  pinMode(buttonKanan,INPUT);

}

void loop() {
  hasilbuttonKiri=digitalRead(buttonKiri);
  if (hasilbuttonKiri==1){
    i++;
    delay(300);
  }
   hasilbuttonKanan=digitalRead(buttonKanan);
  if (hasilbuttonKanan==1){
    i--;
    delay(300);
  }
  switch(i){
    case 1:
    digitalWrite(ledM,HIGH);
    digitalWrite(ledK,LOW);
    digitalWrite(ledH,LOW);
    lcd.clear(); //Untuk Menghapus karakter pada LCD
    lcd.setCursor(3,0); lcd.print("Warna");
    lcd.setCursor(3,1); lcd.print("MERAH");
    break;
    case 2:
    digitalWrite(ledM,LOW);
    digitalWrite(ledK,HIGH);
    digitalWrite(ledH,LOW);
    lcd.clear(); //Untuk Menghapus karakter pada LCD
    lcd.setCursor(3,0); lcd.print("Warna");
    lcd.setCursor(3,0); lcd.print("KUNING");
    break;
    case 3:
    digitalWrite(ledM,LOW);
    digitalWrite(ledK,LOW);
    digitalWrite(ledH,HIGH);
    lcd.clear(); //Untuk Menghapus karakter pada LCD
    lcd.setCursor(3,0); lcd.print("WARNA");
    lcd.setCursor(3,0); lcd.print("HIJAU");
    break;
    default:
    digitalWrite(ledM,LOW);
    digitalWrite(ledK,LOW);
    digitalWrite(ledH,LOW);
    break;
  }
  Serial.println(i);

}
