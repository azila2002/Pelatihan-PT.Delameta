
//Inisialisasi pembuatan variable
//untuk tombol
int tombol1 =2;
int tombol2 =3;
int tombol3 =4;
//untuk led
int LED1    =5;
int LED2    =6;
int LED3    =7;

void setup() {
  //Menentukan Fungsionalitas dari PIN pada Microcontroller
  Serial.begin(96000);
  pinMode(tombol1,INPUT);
  pinMode(LED1,OUTPUT);
  pinMode(tombol2,INPUT);
  pinMode(LED2,OUTPUT);
  pinMode(tombol3,INPUT);
  pinMode(LED3,OUTPUT);

}

void loop() {
  //Program yang akan dijalankan berulang ulang
  int bacaTombol1=digitalRead(tombol1);//Membaca keadaan tombol 1
  int bacaTombol2=digitalRead(tombol2);//Membaca keadaan tombol 2
  int bacaTombol3=digitalRead(tombol3);//Membaca keadaan tombol 3

  //Print Serial
  Serial.print(" | Kondisi Tombol 1:"); Serial.print(bacaTombol1);
  Serial.print(" | Kondisi Tombol 2:"); Serial.print(bacaTombol2);
  Serial.print(" | Kondisi Tombol 3:"); Serial.print(bacaTombol3);
  Serial.println();
  

  //Logika program (Jika tombol membaca nilai 1 maka LED menyala, jika bukan 1 maka mati
  
  //Start Tombol 1
  if(bacaTombol1==1){ 
    digitalWrite(LED1,HIGH);
  }else{
    digitalWrite(LED1,LOW);
}  //end tombol 1

  
}
