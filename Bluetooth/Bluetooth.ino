#include <BluetoothSerial.h>

//FUNCIONA TANTO CON ESP32 COMO CON ARDUINO (COMPRAR MODULO)
BluetoothSerial SerialBT;
#define foco 16

void setup() {
  SerialBT.begin("Bluetooth Foco");
  Serial.begin(115200);
  pinMode(foco,OUTPUT);

  digitalWrite(foco,LOW);
}

void loop() 
{   
  if (SerialBT.available()) {
    String texto = SerialBT.readStringUntil('\n');
    texto.trim();

    if(texto == "1" || texto.equalsIgnoreCase("encendido") || texto.equalsIgnoreCase("E")){
      digitalWrite(foco, HIGH);
      SerialBT.print("ENCENDIDO\n");
    }
    else if(texto == "0" || texto.equalsIgnoreCase("apagado") || texto.equalsIgnoreCase("A")){
      digitalWrite(foco, LOW);
      SerialBT.print("APAGADO\n");
    }
    else{
      SerialBT.print("VALOR INVALIDO\n");
    }
   
  }

}
