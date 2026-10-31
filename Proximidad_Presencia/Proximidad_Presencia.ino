#define Sensor_ProximidadPresencia 23
#define led1 21
#define led2 19
#define led3 18
#define led4 5
#define led5 17
#define led6 16

void setup() {
  // put your setup code here, to run once:
  pinMode(Sensor_ProximidadPresencia, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  bool detectado = (digitalRead(Sensor_ProximidadPresencia)==LOW);

    int estado = detectado ? HIGH:LOW;
    digitalWrite(led1, estado);
    digitalWrite(led2, estado);
    digitalWrite(led3, estado);
    digitalWrite(led4, estado);
    digitalWrite(led5,estado);
    digitalWrite(led6, estado);

    Serial.println(detectado ? "PRESENCIA/PROXIMIDAD DETECTADA!!!" : "PRESENCIA/PROXIMIDAD NO DETECTADA!!!");

  delay(50);
}
