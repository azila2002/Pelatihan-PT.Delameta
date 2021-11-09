//Inisialisasi pembuatan variable
int sensorApi    =A1;
int sensorBuzzer =5;
int R = 9;
int Y = 10;
int G = 11;

void setup(){
  //Menentukan fungsionalitas dari PIN pada mikrokontroller
  Serial.begin(9600);//baudrate yang digunakan untuk komunikasi mikrokontroller dengan komputer
  pinMode(sensorBuzzer,OUTPUT);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
}

void loop(){
  //Baca Data
  int bacaApi=analogRead(sensorApi);//Membaca sensor Api
      bacaApi=map(bacaApi,1023,19,0,100);

  //Print ke serial Monitor
  Serial.print("Nilai PIR :");
  Serial.print(bacaApi);
  Serial.println();//Untuk enter

  //Logika
  if (bacaApi <20){
    digitalWrite(G,HIGH);
    digitalWrite(R,LOW);
    digitalWrite(Y,LOW);
    Serial.println("Aman");
    digitalWrite(sensorBuzzer,LOW);
    delay(100);
  }else if(bacaApi > 51 and bacaApi < 80){
    digitalWrite(Y,HIGH);
    digitalWrite(G,LOW);
    digitalWrite(R,LOW);
    delay(500);
    digitalWrite(sensorBuzzer,HIGH);
    Serial.println("Warning Harap Mengungsi");
  }else{
    digitalWrite(R,HIGH);
    digitalWrite(Y,LOW);
    digitalWrite(G,LOW);
    delay(1000);
    digitalWrite(sensorBuzzer,HIGH);
    Serial.println("Bahaya Api Besar");
  }
 }
