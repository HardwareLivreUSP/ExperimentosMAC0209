/**
 * Programa usado para marcar o mensurar a posicao do pendulo
 * nos experimentos de pendulo.
 */

// 
#include <Ultrasonic.h>

#define TRIGGER_PIN  12
#define ECHO_PIN     13
#define BUTTON_PIN 8
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
long tempo = 0;
long start = 0;
boolean iniciado = 0;
boolean flagNaoIniciado = true;


void setup(){
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);
  start = millis();
  Serial.println("Iniciando arduino");
}

void loop() {
  iniciado = iniciado || digitalRead(BUTTON_PIN);
  if(iniciado){
    if(flagNaoIniciado) {
      start = millis();
      flagNaoIniciado = false;
    }
    float cmMsec, inMsec;
    long microsec = ultrasonic.timing();
    cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
    inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);  
    tempo = millis() - start;
    Serial.print(tempo);
    Serial.print(", ");
    Serial.print(cmMsec);
    Serial.println();
  }
  delay(10);
}
