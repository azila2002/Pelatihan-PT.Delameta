/*/
 * A9  to RX USBTTL
 * A10 to TX USBTTL
 * Tekan Reset sebelum Upload
 * Pilih Board    :fake STM32F10 
 * Upload methode :Serial
 */
//Inisialisasi pembuatan variable
int sensorFlame =PA5;

void setup() {
  //Menentukan Fungsionalitas dari PIN pada Microcontroller
  Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
  pinMode(sensorFlame,INPUT);
}

void loop() {
  //Program yang akan dijalankan berulang-ulang
  int bacaFlame=analogRead(sensorFlame); //Membaca Nilai Flame

  //Print ke Serial Monitor
  Serial.print("Nilai Flame:");
  Serial.print(bacaFlame);
  Serial.println();
  delay(500); //Jeda waktu perulagan seama 500 mili detik
}
