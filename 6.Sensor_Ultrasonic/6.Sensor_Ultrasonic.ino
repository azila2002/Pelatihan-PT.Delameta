//Download dan masukan Library NewPing
#include <NewPing.h>

//Inisialisasi pembuatan variable
int triger  =2;
int echo    =3;
int batas   =200; //Maksimal 400 cm

NewPing cm(triger,echo,batas);

void setup() {
  //Menentukan Fungsionalitas dari PIN pada Microcontroller
  Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
}

void loop() {
  //Program yang akan dijalankan berulang-ulang
  int bacaJarak=cm.ping_cm();

   //Print ke Serial Monitor
  Serial.print("Data jarak:");
  Serial.print(bacaJarak);
  Serial.print(" cm");
  Serial.println();
  delay(500); //Jeda waktu perulagan seama 500 mili detik
}
