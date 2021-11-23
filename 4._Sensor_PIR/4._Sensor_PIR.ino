//Inisialisasi pembuatan variable
int sensorPIR =2;

void setup() {
  //Menentukan Fungsionalitas dari PIN pada Microcontroller
  Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
  pinMode(sensorPIR,INPUT);
}

void loop() {
  //Program yang akan dijalankan berulang-ulang
  int bacaPIR=digitalRead(sensorPIR); //Membaca Nilai Sensor PIR

  //Print ke Serial Monitor
  Serial.print("Sensor PIR:");
  Serial.print(bacaPIR);
  Serial.println();

  //Logika Program (Jika tombol membaca Nilai 1 maka led menyala, jika bukan 1 maka mati
  delay(500); //Jeda waktu perulagan seama 500 mili detik
}
