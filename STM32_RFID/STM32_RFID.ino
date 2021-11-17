#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN PB1
#define RST_PIN PB0
MFRC522 mfrc522(SS_PIN, RST_PIN);

int ledM =PA1;
int ledH =PA3;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Tempelkan Kartu!!!");
  pinMode(ledM,OUTPUT);
  pinMode(ledH,OUTPUT);
  

}

void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
  if ( ! mfrc522.PICC_ReadCardSerial()) {return;}
  Serial.print("UID tag :");
  String content="";
  byte letter;
  for (byte i = 0; i <mfrc522.uid.size; i++){
   Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
   Serial.print(mfrc522.uid.uidByte[i], HEX);
   content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : ""));
   content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
    Serial.println();
    Serial.print("Massage : ");
    content.toUpperCase();

    if (content=="058656BF90D100"){
    Serial.println("KARTU ATAS NAMA TAZILA");
    digitalWrite(ledM,LOW);
    digitalWrite(ledH,HIGH);
    delay(500);
    
    }else if(content=="8AB0C115"){
    Serial.println("Selamat Datang di Delameta Bilano");
    digitalWrite(ledM,LOW);
    digitalWrite(ledH,HIGH);
    delay(500);

    }else if(content==0){
    Serial.println("Kartu Belum Terdaftar!");
    digitalWrite(ledM,HIGH);
    digitalWrite(ledH,LOW);
    delay(500);

    }else{
      Serial.println("Tidak ada Kartu yang ditempelkan");
       digitalWrite(ledM,LOW);
       digitalWrite(ledH,LOW);
       delay(500);

    }
    Serial.println("Tempelkan Kartu!");
    delay(500);
}
