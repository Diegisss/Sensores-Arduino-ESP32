#include <DHT.h>
#define DHTPIN 6
#define DHTTYPE DHT11
#define led 8

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
  float humedad = dht.readHumidity();

  if(isnan(humedad)){
    Serial.println("ERROR");
  }

  Serial.print("HUMEDAD ");
  Serial.println(humedad);

  if(humedad > 55){
    digitalWrite(led, HIGH);
  }else{
    digitalWrite(led, LOW);
  }

}
