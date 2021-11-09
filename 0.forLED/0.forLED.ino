int R=2; //Digunakan untuk variable led merah
int Y=3;
int G=4;


void setup() {
 // for (int i=2; i<=4; i++){
 // pinMode(i,OUTPUT);
 // }
 
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i=2; i<=4; i++){
    digitalWrite(i,HIGH);
    delay(100);
    digitalWrite(i,LOW);
    delay(100);
  }
}
