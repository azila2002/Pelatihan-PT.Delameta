/*/
 * A9  to RX USBTTL
 * A10 to TX USBTTL
 * Tekan Reset sebelum Upload
 * Pilih Board    :fake STM32F10 
 * Upload methode :Serial
 */
int tombol1 =PA4;
int led1    =PC13;

void setup() {
  //Menentukan Fungsionalitas dari PIN pada Microcontroller
  Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
  pinMode(tombol1,INPUT);
  pinMode(led1,OUTPUT);
}

void loop() {
  //Program yang akan dijalankan berulang-ulang
  int bacaTombol1=digitalRead(tombol1); //Membaca keadaan Tombol

  //Print ke Serial Monitor
  Serial.print("Kondisi tombol:");
  Serial.print(bacaTombol1);
  Serial.println();

  //Logika Program (Jika tombol membaca Nilai 1 maka led menyala, jika bukan 1 maka mati
  if(bacaTombol1==1){
    digitalWrite(led1,HIGH);
  }else{
    digitalWrite(led1,LOW);
  }
  delay(500); //Jeda waktu perulagan seama 500 mili detik
}
