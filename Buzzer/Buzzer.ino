#define Sensor_Buzzer 8
#define Boton 7
#define led 4
bool estado = false;
void setup() {
  Serial.begin(9600);
  pinMode(Sensor_Buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(Boton, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(Boton) == LOW){
    estado = !estado;
    digitalWrite(Sensor_Buzzer, estado);
    digitalWrite(led, estado);
    delay(300);
  }
}
