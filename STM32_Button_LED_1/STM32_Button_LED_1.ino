//Variable LED
int merah  =PA0;
int kuning =PA1;
int hijau  =PA2;

//Variable Tombol
int tombol1 =PA5;
int tombol2 =PA6;
int tombol3 =PA7;

//Variable Kunci/hold
int kunci1;
int kunci2;
int kunci3;

void setup(){
  Serial.begin(9600);//Baudrate
  pinMode(tombol1,INPUT);
  pinMode(tombol2,INPUT);
  pinMode(tombol3,INPUT);
  pinMode(merah,OUTPUT);
  pinMode(kuning,OUTPUT);
  pinMode(hijau,OUTPUT);
}

void loop(){
  //Baca Tombol
  int readTombol1=digitalRead(tombol1);
  int readTombol2=digitalRead(tombol2);
  int readTombol3=digitalRead(tombol3);
  
  //Hasil Data
  Serial.print("Tombol1:");Serial.print(readTombol1);
  Serial.print(" | Tombol2:");Serial.print(readTombol2);
  Serial.print(" | Tombol3:");Serial.print(readTombol3);
  Serial.println();

//Logika

//TOMBOL LED 1
  if (readTombol1==1 && kunci1==0){
    delay(500);
    Serial.println("LED ON");
    digitalWrite(merah,HIGH);
    kunci1=1;
  }else if (readTombol1==1 && kunci1==1){
    delay(100);
    Serial.println("LED OFF");
    digitalWrite(merah,LOW);
    kunci1=0;
  }

//TOMBOL LED 2
  if (readTombol2==1 && kunci2==0){
    delay(500);
    Serial.println("LED ON");
    digitalWrite(kuning,HIGH);
    kunci2=1;
  }else if (readTombol2==1 && kunci2==1){
    delay(100);
    Serial.println("LED OFF");
    digitalWrite(kuning,LOW);
    kunci2=0;
  }

//TOMBOL LED 3
  if (readTombol3==1 && kunci3==0){
    delay(500);
    Serial.println("LED ON");
    digitalWrite(hijau,HIGH);
    kunci3=1;
  }else if (readTombol3==1 && kunci3==1){
    delay(100);
    Serial.println("LED OFF");
    digitalWrite(hijau,LOW);
    kunci3=0;
  }

}
