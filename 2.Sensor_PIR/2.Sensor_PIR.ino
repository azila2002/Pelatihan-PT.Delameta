//Inisialisasi pembuatan variable
int sensorPIR    =2;
int sensorBuzzer =5;

void setup(){
  //Menentukan fungsionalitas dari PIN pada mikrokontroller
  Serial.begin(9600);//baudrate yang digunakan untuk komunikasi mikrokontroller dengan komputer
  pinMode(sensorPIR,INPUT);
  pinMode(sensorBuzzer,OUTPUT);
}

void loop(){
  //Baca Data
  int bacaPIR=digitalRead(sensorPIR);//Membaca sensor PIR

  //Print ke serial Monitor
  Serial.print("Nilai PIR:");
  Serial.print(bacaPIR);
  Serial.println();//Untuk enter

  //Logika
  if (bacaPIR==1){
    digitalWrite(sensorBuzzer,HIGH);
    delay(100);
    Serial.println("Ada Mahluk");
  }else{
    digitalWrite(sensorBuzzer,LOW);
    delay(100);
    Serial.println("NOLEP");
  }
}
