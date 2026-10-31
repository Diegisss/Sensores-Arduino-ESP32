#define BUZZER 3
#define SENSOR_GAS A0
#define LED 2

void setup(){
  Serial.begin(9600);

  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(SENSOR_GAS, INPUT);
}

void loop(){
  int NGas = analogRead(SENSOR_GAS);
  Serial.println(NGas);
  delay(100);

  if(NGas > 500){
    digitalWrite(BUZZER, HIGH);
    digitalWrite(LED, HIGH);
  }else{
    digitalWrite(BUZZER, LOW);
    digitalWrite(LED,LOW);
  }
}