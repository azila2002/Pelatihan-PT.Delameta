#include <NewPing.h>

//Variable
int r =PA1;
int y =PA2;
int g =PA3;

int Flame =PA4;
int echo =PA6;
int trigger =PA7;
int batas =400;

int key;
NewPing cm(trigger,echo,batas);

void setup(){
  Serial.begin(9600);
  pinMode(Flame,INPUT);
  pinMode(r,OUTPUT);
  pinMode(y,OUTPUT);
  pinMode(g,OUTPUT);
}

void loop(){
  int readFlame=digitalRead(Flame);
  int readDistance=cm.ping_cm(); 

  Serial.print(" | Nilai Flame :");Serial.print(readFlame);
  Serial.print(" | Data Jarak :");Serial.print(readDistance);
  Serial.print(" cm");
  Serial.print(" | KEY :");Serial.print(key);
  Serial.println();
  delay(500); 

  //Logika
  if(readFlame==0 and key==0){
    Serial.print("Flame Aktif");
    Serial.println();
    key=1;
  
  }else if(readFlame==0 and key==1){
    Serial.print("Flame Off");
    Serial.println();
    key=0;
  }
  
  if (readDistance >=100 and key==1){
    digitalWrite(r,HIGH);
    delay(500);
    digitalWrite(r,LOW);
    digitalWrite(y,HIGH);
    delay(500);
    digitalWrite(y,LOW);
    digitalWrite(g,HIGH);
    delay(500);
    digitalWrite(g,LOW);
    digitalWrite(y,HIGH);
    delay(500);
    digitalWrite(y,LOW);
    Serial.print("JAUH ");
    Serial.println();
  }
  else if(readDistance >=20 and readDistance <=100 and key==1){
    digitalWrite(r,HIGH);
    digitalWrite(y,HIGH);
    digitalWrite(g,HIGH);
    delay(500);
    digitalWrite(r,LOW);
    digitalWrite(y,LOW);
    digitalWrite(g,LOW);
    delay(500);
    Serial.print("SEDANG ");
    Serial.println();
  }
  else if(readDistance <=20 and key==1){
    digitalWrite(r,HIGH);
    digitalWrite(y,HIGH);
    digitalWrite(g,HIGH);
    delay(100);
    digitalWrite(r,LOW);
    digitalWrite(y,LOW);
    digitalWrite(g,LOW);
    delay(100);
    Serial.print("DEKAT ");
    Serial.println();
  }
  
}
