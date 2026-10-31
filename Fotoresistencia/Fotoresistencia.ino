#define Sensor_fotoresistencia 4
#define Sensor_laser 21
#define Buzzer 18

void setup() {
  pinMode(Sensor_laser, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(Sensor_fotoresistencia, INPUT);
  Serial.begin(115200);
}

void loop() {
  int valor = analogRead(Sensor_fotoresistencia);
  int light = map(valor, 0, 4095, 0, 10);
  digitalWrite(Sensor_laser, HIGH);
  
  if (light >= 3) {
     digitalWrite(Buzzer, HIGH);
  } 
  else {
    digitalWrite(Buzzer, LOW);
  }

  Serial.print("LUZ: ");
  Serial.println(light);
  delay(500); 
}