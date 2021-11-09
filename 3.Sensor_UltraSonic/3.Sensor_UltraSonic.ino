//Download dan masukan Library NewPing
#include <NewPing.h>

//Inisialisasi pembuatan variable
int R =5;
int G =7;
int Y =6;
int sensorBuzzer =3;

int triger =10;
int echo =9;
int batas =200; //Maksimal 400 cm
NewPing cm(triger,echo,batas);

void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(9600); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 pinMode(R,OUTPUT);
 pinMode(Y,OUTPUT);
 pinMode(G,OUTPUT);
 pinMode(sensorBuzzer,OUTPUT);
}

void loop() {
 //Program yang akan dijalankan berulang-ulang
 int bacaJarak=cm.ping_cm();
 //Print ke Serial Monitor
 Serial.print("Data jarak:");
 Serial.print(bacaJarak);
 Serial.print(" cm");
 Serial.println();
 delay(500); //Jeda waktu perulagan seama 500 mili deti


  //Logika
  if(bacaJarak <=20 and bacaJarak !=0){
    digitalWrite(R,HIGH);
    digitalWrite(Y,LOW);
    digitalWrite(G,LOW);
    digitalWrite(sensorBuzzer,HIGH);
    digitalWrite(sensorBuzzer,LOW);
    delay(500);
    Serial.print("Berhenti     ");
  }else if (bacaJarak >=21 and bacaJarak<=70){
    digitalWrite(R,LOW);
    digitalWrite(Y,HIGH);
    digitalWrite(G,LOW);
    digitalWrite(sensorBuzzer,HIGH);
    delay(100);
    digitalWrite(sensorBuzzer,LOW);
    delay(200);
    Serial.print("Bahaya       ");
  }else if (bacaJarak >=71){
    digitalWrite(R,LOW);
    digitalWrite(Y,LOW);
    digitalWrite(G,HIGH);
    Serial.print("Aman       ");
  }
 }
