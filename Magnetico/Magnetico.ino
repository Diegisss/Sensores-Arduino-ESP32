#define Sensor_Magnetico A0
#define Buzzer 12


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Sensor_Magnetico, INPUT);
  pinMode(Buzzer, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int detector = digitalRead(Sensor_Magnetico);

  if (detector == LOW){
    Serial.println("IMAN DETECTADO");
    digitalWrite(Buzzer, HIGH);
    delay(50);
    digitalWrite(Buzzer, LOW);
    delay(50);
  }else{
    Serial.println("NO DETECTADO");
    digitalWrite(Buzzer, LOW);
  }
  delay(300);
}


