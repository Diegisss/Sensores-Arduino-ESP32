#define SENSOR_TEMPERATURA A0

void setup(){
  Serial.begin(9600);
  pinMode(SENSOR_TEMPERATURA, INPUT);
}
  
void loop(){
  int Voltaje = analogRead(SENSOR_TEMPERATURA);
  float Resistencia = (10000.0*(1023/Voltaje-1));
  float TEMPERATURA = (1.0/(log(Resistencia/10000.0)/3950.0 + 1.0 / 298.15))-273.15;
  Serial.println(Voltaje);
  delay(100);

}