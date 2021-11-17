int R=PA1;
int y=PA2;
int G=PA3;
int sensorIR=PA0;
int pinLDR=PA4;
int kunci=0;

void setup() {
  Serial.begin(9600);
  pinMode(R,OUTPUT);
  pinMode(y,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(sensorIR,INPUT);

}

void loop() {
 int bacasensorIR=digitalRead(sensorIR);
 int bacapinLDR=analogRead(pinLDR);
     bacapinLDR=map(bacapinLDR,55,4095,0,255);

 //PRINT TO SERIAL
 Serial.print("sensorIR:");
 Serial.print(bacasensorIR);
 Serial.print("pinLDR:");
 Serial.print(bacapinLDR);
 Serial.println();

if(bacasensorIR==0 and kunci==0){
  Serial.print("LDR aktif");
  Serial.println();
  delay(200);
    kunci=1;

}else if(bacasensorIR==0 and kunci==1){
  Serial.print("LDR OFF");
  Serial.println();
digitalWrite(y,LOW);
  digitalWrite(G,LOW);
  digitalWrite(R,LOW);
    kunci=0;
  delay(200);

  
}
if (bacapinLDR<100 and kunci==1){
  digitalWrite(G,HIGH);
  digitalWrite(y,LOW);
  digitalWrite(R,LOW);
  delay(500);
  
}else if(bacapinLDR>100 && bacapinLDR<200 and kunci==1){
  digitalWrite(y,HIGH);
  digitalWrite(R,LOW);
  digitalWrite(G,LOW);
  delay(500);
}if (bacapinLDR>200 and kunci==1){
  digitalWrite(R,HIGH);
  digitalWrite(y,LOW);
  digitalWrite(G,LOW);
  delay(500);

}
}
 
