#define Sensor_Laser 8
#define Button 11
bool estado = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Sensor_Laser, OUTPUT);
  pinMode(Button, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(Button) == HIGH){
    estado = !estado;
    digitalWrite(Sensor_Laser, estado);
    delay(300);
  }
  
  
}
