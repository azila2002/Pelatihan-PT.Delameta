#include <SPI.h>
#include <MFRC522.h>

String uidString;

int buzzer   =3;

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup(){
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Tempelkan Kartu!");
}

void loop(){
  if(mfrc522.PICC_IsNewCardPresent()){
    readRFID();
    Serial.print("Tag UID: ");
    Serial.println(uidString);
    if(uidString=="4A-51-6E-AE"){
      bunyibuzzeroke();
      Serial.println("Berhasil");
      delay(1000);
      Serial.println("Silahkan Masuk!");
    }else{
      Serial.println("GAGAL");
      bunyibuzzergagal();
    }
  }
}

void readRFID(){
  mfrc522.PICC_ReadCardSerial();
  //Pembatas bisa dirubah sesuai keinginan, disini yang digunakan "-"
  uidString = String(mfrc522.uid.uidByte[0],HEX) + "-" +
              String(mfrc522.uid.uidByte[1],HEX) + "-" +
              String(mfrc522.uid.uidByte[2],HEX) + "-" +
              String(mfrc522.uid.uidByte[3],HEX);
              uidString.toUpperCase(); 
}

void bunyibuzzeroke(){
  digitalWrite(buzzer,HIGH);
  delay(500);
  digitalWrite(buzzer,LOW);
  delay(500);
}

void bunyibuzzergagal(){
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(100);
}
