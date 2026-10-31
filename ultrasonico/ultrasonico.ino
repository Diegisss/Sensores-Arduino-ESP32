#define LED_1 2
#define LED_2 3
#define LED_3 4
#define LED_4 5
#define LED_5 6
#define sensorPin A0 

const int ventana = 50;

void setup() {
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(LED_5, OUTPUT);
  
  Serial.begin(9600);
  analogReference(INTERNAL); 
}

void loop() { 
  unsigned long inicioMillis = millis();
  unsigned int nivelMaximo = 0;
  unsigned int nivelMinimo = 1023;

  while (millis() - inicioMillis < ventana) {
    int lectura = analogRead(sensorPin);
    
    if (lectura < 1024) {
      if (lectura > nivelMaximo) {
        nivelMaximo = lectura; //guardamos el ruido del circuito mas alto
      } else if (lectura < nivelMinimo) {
        nivelMinimo = lectura; //almaceno el valor mas bajo
      }
    }
  }

  // Calculamos la intensidad real del sonido, esto con el fin de que el sonido no se eleve a mas de 50
  int sonido;
  sonido = nivelMaximo - nivelMinimo;
  
  Serial.println(sonido); //lo que voy a mostrar en el circuito

  //unicamente para refrescarlos
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, LOW);
  digitalWrite(LED_4, LOW);
  digitalWrite(LED_5, LOW);

  // Como ahora medimos la diferencia, el silencio marcará números muy bajos 
  if (sonido > 15) {
    if (sonido > 15) digitalWrite(LED_1, HIGH);
    if (sonido > 30) digitalWrite(LED_2, HIGH);
    if (sonido > 45) digitalWrite(LED_3, HIGH);
    if (sonido > 60) digitalWrite(LED_4, HIGH);
    if (sonido > 80) digitalWrite(LED_5, HIGH); 
    
    delay(50);
  }
}