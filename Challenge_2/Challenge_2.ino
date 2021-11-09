int sensorPIR     =A2;
int sensorLDR     =A1;
int sensorFLAME   =0;

int sensorBuzzer  =5;
int R             =3;
int Y             =4;
int G             =6;

void setup(){
  Serial.begin(9600);
  pinMode(sensorBuzzer,OUTPUT);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
  
}

void loop(){
  int readFLAME=analogRead(sensorFLAME);
      readFLAME=map(readFLAME,1023,19,0,100);
  int readPIR=digitalRead(sensorPIR);
  int readLDR=analogRead(sensorLDR);


  //Print serial
  Serial.print("Nilai Sensor FLAME :");
  Serial.print(readFLAME);

  Serial.print(" | Nilai Sensor PIR :");
  Serial.print(readPIR);

  Serial.print(" | Nilai Sensor LDR :");
  Serial.print(readLDR);
  Serial.println();

  //Logika
  analogWrite(R,readLDR);

  if(readFLAME >0 and readFLAME <50){
    digitalWrite(G,LOW);
    delay(500);
    digitalWrite(Y,HIGH);
    digitalWrite(sensorBuzzer,HIGH);
    delay(1000);
    digitalWrite(sensorBuzzer,LOW);
    delay(1000);
    Serial.println("Warning Silahkan Periksa");
  }else{
    digitalWrite(Y,LOW);
    delay(500);
    digitalWrite(G,HIGH);
    digitalWrite(sensorBuzzer,LOW);
    Serial.println("Aman");
  }
}
