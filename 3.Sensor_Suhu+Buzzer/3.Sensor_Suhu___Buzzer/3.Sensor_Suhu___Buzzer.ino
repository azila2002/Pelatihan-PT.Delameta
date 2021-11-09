//Download dan masukkan Library Onewire dan DallasTemperature
#include <OneWire.h>
#include <DallasTemperature.h>

//inisialisasi pembuatan variable
int sensorSuhu =12;
OneWire oneWire(sensorSuhu);
DallasTemperature sensors(&oneWire);

void setup(){
  Serial.begin(9600);
  sensors.begin();
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
 }
  
