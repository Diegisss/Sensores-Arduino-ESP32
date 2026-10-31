#define Rele 23

void setup() {
  pinMode(Rele, OUTPUT);
  digitalWrite(Rele, LOW);
  Serial.begin(115200);
}

void loop() {
  digitalWrite(Rele, HIGH);
  Serial.println("ENCENDIDO!!!");
  delay(2000);
  
  digitalWrite(Rele, LOW);
  Serial.println("APAGADO!!!");
  delay(5000);
}