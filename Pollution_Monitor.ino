#include <DHT.h>

DHT dht(4, DHT11);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  

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
}
