/**
 * Programa usado para marcar o tempo de passagem do carrinho
 * nos experimentos de MRU e MRUV.
 */
 
#define LDRsize 4
#define LDR0pin A0
#define LDR1pin A1
#define LDR2pin A2
#define LDR3pin A3
#define threshold 700 //Limiar de sensibilidade usado para os sensores.

int LDRpin[] = {LDR0pin, LDR1pin, LDR2pin, LDR3pin};
int LDR[4];
int i, j;
long inicio = 0;
long tempos[LDRsize];
long contagem;

void setup() {
  for(i = 0; i < LDRsize; i++) {
    pinMode(LDRpin[i], INPUT);
    tempos[i] = 0;
  }
  Serial.begin(9600);
  Serial.println("Iniciando experimento...");
}

void loop() {
  for(i = 0; i < LDRsize; i++) {
      LDR[i] = 0; //Zera a variável LDR
  }
  if(tempos[0] == 0) {
    LDR[0] = lerLDR(LDR0pin);
    if(LDR[0] > threshold) {
      inicio = millis();
      tempos[0] = inicio;
      imprimeDados();
    }
  } else if(tempos[1] == 0) {
      LDR[1] = lerLDR(LDR1pin);
      if(LDR[1] > threshold) {
          tempos[1] = millis();
          imprimeDados();
      }
  } else if(tempos[2] == 0) {
      LDR[2] = lerLDR(LDR2pin);
      if(LDR[2] > threshold) {
        tempos[2] = millis();
        imprimeDados();
      }
  } else if(tempos[3] == 0) {
      LDR[3] = lerLDR(LDR3pin);
      if(LDR[3] > threshold) {
        tempos[3] = millis();
        imprimeDados();
      }
  }
}

int lerLDR(int pino) {
  int leitura = 0;
  int c;
  for (c = 0; c < 9; c ++) {
    leitura += analogRead(pino);
  }
  return leitura/10;
}

void imprimeDados() {
  int i;
  for(i = 0; i < LDRsize; i++) {
    Serial.print("LDR ");
    Serial.print(i);
    Serial.print(": ");
    Serial.print(LDR[i]);
    Serial.print("    ");
  }
  Serial.println();
    for(i = 0; i < LDRsize; i++) {
    Serial.print("tempo ");
    Serial.print(i);
    Serial.print(": ");
    Serial.print(tempos[i] - inicio);
    Serial.print("    ");
  }
  Serial.println();
}
