#include <DHT.h>

DHT dht(4, DHT11);

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
//  pinMode(4, OUTPUT);
 pinMode(3, OUTPUT);
 pinMode(2, OUTPUT);
}

void init(int DS){
 for(int i = 5; i >=2; i--){
     digitalWrite(i, LOW);
     }
   digitalWrite(DS+1, HIGH);

 //DISPLAY 8
 for(int i = 13; i >=7; i--){
    digitalWrite(i, LOW);
   }
 }

void eight(int DS){
   init(DS);
   delay(del);
 }

void nine(int DS){
   init(DS);
   digitalWrite(E, HIGH);
   delay(del);
 }

void seven(int DS){
 init(DS);
 digitalWrite(D, HIGH);
 digitalWrite(E, HIGH);
 digitalWrite(F, HIGH);
 digitalWrite(G, HIGH);
 delay(del);
 }

void six(int DS){
 init(DS);
 digitalWrite(B, HIGH);
 delay(del);
 }

void five(int DS){
 init(DS);
 digitalWrite(B, HIGH);
 digitalWrite(E, HIGH);
 delay(del);
 }

void four(int DS){
 init(DS);
 digitalWrite(A, HIGH);
 digitalWrite(E, HIGH);
 digitalWrite(D, HIGH);
 delay(del);
 }
 
void three(int DS){
 init(DS);
 digitalWrite(F, HIGH);
 digitalWrite(E, HIGH);  
 delay(del);
 }

void two(int DS){
 init(DS);
 digitalWrite(F, HIGH);
 digitalWrite(C, HIGH);
 delay(del);
 }

void one(int DS){
 init(DS);
 digitalWrite(A, HIGH);
 digitalWrite(F, HIGH);
 digitalWrite(E, HIGH);
 digitalWrite(D, HIGH);
 digitalWrite(G, HIGH); 
 delay(del);
 }

void zero(int DS){
 init(DS);
 digitalWrite(G, HIGH);
 delay(del);
 }

void L(int DS){
 init(DS);
 digitalWrite(A, HIGH);
 digitalWrite(B, HIGH);
 digitalWrite(G, HIGH);
 digitalWrite(C, HIGH);
 delay(del);
 }

void Cc(int DS){
 init(DS);
 digitalWrite(B, HIGH);
 digitalWrite(G, HIGH);
 digitalWrite(C, HIGH);
 delay(del);
 }

void H(int DS){
 init(DS);
 digitalWrite(A, HIGH);
 digitalWrite(D, HIGH);
 delay(del);
 }


void segPrint(char ch, int DS){
 switch(ch){
   case '1':
     one(DS);
     break;
   case '2':
     two(DS);
     break;
   case '3':
     three(DS);
     break;
   case '4':
     four(DS);
     break;
   case '5':
     five(DS);
     break;
   case '6':
     six(DS);
     break;
   case '7':
     seven(DS);
     break;
   case '8':
     eight(DS);
     break;
   case '9':
     nine(DS);
     break;
   case '0':
     zero(DS);
     break;
   case 'L':
     L(DS);
     break;
   case 'C':
     Cc(DS);
     break;
   case 'H':
     H(DS);
     break;
   }
 }

void displaySeg(String s, char ch){
 for(int i = 0; i < 200; i++){
   segPrint(s[0], 1);
   digitalWrite(dp, LOW);
   segPrint(s[1], 2);
   digitalWrite(dp, HIGH);
   segPrint(s[2], 3);
   segPrint(ch, 4);
   }
 }

void loop() {
  // put your main code here, to run repeatedly:
  float t = dht.readTemperature();     // read temperature
  float h = dht.readHumidity();        // read humidity
  float vol = analogRead(0);
  float mx = abs(150-vol)/5;
  String hs = String(h);
  String ts = String(t);
  String dbs = String(mx*10);
  Serial.println(hs+" "+ts+" "+mx);

 digitalWrite(dp, HIGH);

 displaySeg(hs, 'H');
 displaySeg(ts, 'C');
 displaySeg(dbs, 'L');
  
}
