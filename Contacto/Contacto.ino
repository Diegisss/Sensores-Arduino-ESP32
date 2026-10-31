#define RELE 16
#define CONTACTO 19

bool estado = LOW;
int anterior = LOW;

void setup() {
  Serial.begin(115200);
  pinMode(RELE, OUTPUT);
  pinMode(CONTACTO, INPUT_PULLUP); // Mantiene estable el pin

  digitalWrite(RELE, estado);
}

void loop() {
  int actual = digitalRead(CONTACTO);

  if (anterior == HIGH && actual == LOW) {

    estado = !estado; 
    digitalWrite(RELE, estado);

    if (estado == HIGH) {
      Serial.println("ENCENDIDO");
    } else {
      Serial.println("APAGADO");
    }

    delay(250); 
  }

  anterior = actual;
}