#define Alcohol A0
#define buzzer 2

void setup(){
  Serial.begin(9600);

  pinMode(Alcohol, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop(){
  int NAlcohol = analogRead(Alcohol);
  Serial.print("NIVEL DE ALCOHOL ");
  Serial.print(NAlcohol);
  Serial.print("  |  ");
  Serial.print("ESTADO: ");

  if(NAlcohol > 260){
    Serial.print("CRITICO!!! ");
    Serial.println("ALCOHOL DETECTADO");
    digitalWrite(buzzer, HIGH);
  }else{
    Serial.println("NORMAL");
    digitalWrite(buzzer, LOW);
  }

  delay(500);
}