int R=5; //Digunakan untuk variable led merah
int Y=3;
int G=6;


void setup() {
 Serial.begin(9600);
  for (int i=3; i<=6; i++){
  pinMode(i,OUTPUT);
 }
 
}

void loop() {
  for (int i=0; i<=255; i++){
  analogWrite(3,i); 
  //float volt=map(i,0,255,0,5);
  float volt=(5.0/255.0);
  float hasil= i*volt;
  //Serial.println("Nilai :" + String(hasil)+ " Volt");
  Serial.println(hasil);
  delay(50);
  }
   for (int i=255; i<=0; i--){
    analogWrite(3,i); 
  //float volt=map(i,0,255,0,5);
  float volt=(5.0/255.0);
  float hasil=i*volt;
  //Serial.println("Nilai :" + String(hasil)+ " Volt");
  Serial.println(hasil);
  delay(50);
}  

}
