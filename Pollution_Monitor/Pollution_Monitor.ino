#include <DHT.h>

DHT dht(1, DHT11);

int A=13, B=12, C=11, D=10, E=9, F=8, G=7, dp=6;
int del = 4;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(dp, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
}

void init(int DS){
  for(int i = 5; i >=2; i--){
      digitalWrite(i, HIGH);
      }
    digitalWrite(DS+1, LOW);

  //DISPLAY 8
  for(int i = 13; i >=7; i--){
     digitalWrite(i, HIGH);
    }
  }

void eight(int DS){
    init(DS);
  }

void nine(int DS){
    init(DS);
    digitalWrite(E, LOW);
    delay(del);
  }

void seven(int DS){
  init(DS);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  delay(del);
  }

void six(int DS){
  init(DS);
  digitalWrite(B, LOW);
  delay(del);
  }

void five(int DS){
  init(DS);
  digitalWrite(B, LOW);
  digitalWrite(E, LOW);
  }

void four(int DS){
  init(DS);
  digitalWrite(A, LOW);
  digitalWrite(E, LOW);
  digitalWrite(D, LOW);
  delay(del);
  }
  
void three(int DS){
  init(DS);
  digitalWrite(F, LOW);
  digitalWrite(E, LOW);  
  delay(del);
  }

void two(int DS){
  init(DS);
  digitalWrite(F, LOW);
  digitalWrite(C, LOW);
  delay(del);
  }

void one(int DS){
  init(DS);
  digitalWrite(A, LOW);
  digitalWrite(F, LOW);
  digitalWrite(E, LOW);
  digitalWrite(D, LOW);
  digitalWrite(G, LOW); 
  delay(del);
  }

void zero(int DS){
  init(DS);
  digitalWrite(G, LOW);
  delay(del);
  }


void loop() {
  // put your main code here, to run repeatedly:
  float t = dht.readTemperature();     // read temperature
  float h = dht.readHumidity();        // read humidity
  float vol = analogRead(0);
  float mx = abs(150-vol)/5;
  String hs = String(h);
  String ts = String(t);
  String dbs = String(mx);
  
  Serial.println(hs+" "+ts+" "+mx);
  delay(2000);
  
  digitalWrite(dp, LOW);
  for(int i=0; i<10; i++){
      one(4);
      nine(3);
      two(2);
      zero(1);
      }//1600msc

}
