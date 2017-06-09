/**
 * O programa imprime na serial "Iniciando experimento..." ao iniciar 
 * e inicia a leitura do primeiro LDR (LDR0).
 * Quando a leitura do LDR0 eh maior que o limiar marcamos esse tempo
 * e iniciamos a leitura do proximo LDR.
 * Ficamos sempre lendo o valor do proximo LDR e marcando quando ele 
 * eh maior que o limiar ate termos marcado tempos para todos os LDR.
 */

#define LDRsize 11
#define LDR0pin A0
#define LDR1pin A1
#define LDR2pin A2
#define LDR3pin A3
#define LDR4pin A4
#define LDR5pin A5
#define LDR6pin A6
#define LDR7pin A7
#define LDR8pin A8
#define LDR9pin A9
#define LDR10pin A10


#define threshold 770 //Limiar de sensibilidade usado para os sensores.

int LDRpin[] = {LDR0pin, LDR1pin, LDR2pin, LDR3pin, LDR4pin, LDR5pin, LDR6pin, LDR7pin, LDR8pin, LDR9pin, LDR10pin};
int LDR = 0;
int k = 0;
long inicio = 0;

void setup() {
  for(int i = 0; i < LDRsize; i++) {
    pinMode(LDRpin[i], INPUT);
  }
  Serial.begin(9600);
  Serial.println("Iniciando experimento...");
  while(inicio == 0) {
    if(analogRead(LDR0pin) > threshold) {
      inicio = millis();
    }
  }
  Serial.println(inicio);
  k = 1;
}

void loop() {
  LDR = 0;
  while (k < LDRsize) {
    LDR = analogRead(LDRpin[k]);
    if(LDR > threshold) {
      Serial.print(LDR);
      Serial.print(", ");
      Serial.println((millis() - inicio));
      k++;
    }
  }
  delay(1); 
}
