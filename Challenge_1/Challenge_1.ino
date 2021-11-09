int tombol1 =2;
int sensor1 =3;

int R =5;
int Y =6;
int G =7;

void setup(){
  Serial.begin(9600);
  pinMode(tombol1,INPUT);
  pinMode(sensor1,INPUT);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
  digitalWrite(R,HIGH);
  Serial.print("System START");
}

  void loop(){
    int bacaTombol1=digitalRead(tombol1);
    int bacaSensor1=digitalRead(sensor1);


    if(bacaTombol1==1){
      delay(500);
      Serial.println("Selamat Datang Silahkan Ambil Tiket");
      Serial.println("Palang Dibuka");
      digitalWrite(R,LOW);
      digitalWrite(Y,HIGH);
      delay(1000);
      digitalWrite(Y,LOW);
      delay(100);
      digitalWrite(G,HIGH);
      }

     if(bacaSensor1==0){
      delay(500);
      Serial.println("Palang Ditutup");
      digitalWrite(G,LOW);
      digitalWrite(R,HIGH);
     }
    
  }
