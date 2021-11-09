//Download dan masukkan Library Onewire dan DallasTemperature
#include <OneWire.h>
#include <DallasTemperature.h>

//inisialisasi pembuatan variable
int sensorSuhu =12;
int sensorBuzzer =3;
int R   =5;
int Y   =6;
int G   =7;
OneWire oneWire(sensorSuhu);
DallasTemperature sensors(&oneWire);

void setup(){
  Serial.begin(9600);
  sensors.begin();
  pinMode(sensorBuzzer,OUTPUT);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
}

void loop(){
  sensors.requestTemperatures();
  float bacaSuhu=sensors.getTempCByIndex(0);


  if(bacaSuhu !=DEVICE_DISCONNECTED_C)
  {
  Serial.print("Data suhu yang terbaca pada bus 1(index0): ");
  Serial.println(bacaSuhu);
  }
  else
  {
  Serial.print("Error: sensor pada index 0 tidak ditemukan!");
  }

  if(bacaSuhu >=31){
    digitalWrite(R,HIGH);
    digitalWrite(Y,LOW);
    digitalWrite(G,LOW);
    digitalWrite(sensorBuzzer,HIGH);
    delay(500);
    digitalWrite(sensorBuzzer,LOW);
    delay(10);
    Serial.println("Agak Panas");

  }else{
    digitalWrite(R,LOW);
    digitalWrite(Y,LOW);
    digitalWrite(G,HIGH);
    digitalWrite(sensorBuzzer,HIGH);
    delay(100);
    digitalWrite(sensorBuzzer,LOW);
    delay(400);
    Serial.println("Aman");
 }

}
  
