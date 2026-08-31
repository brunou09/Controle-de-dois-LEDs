const int PINO_BOTAO = 2;
const int PINO_LED1 = 8;
const int PINO_LED2 = 9;

int estadoCiclo = 0;
int estadoBotaoAnterior = HIGH;

unsigned long ultimoTempoDebounce = 0;
const unsigned long atrasoDebounce = 50;

void atualizarLEDs() {
  switch (estadoCiclo) {
    case 1:
      digitalWrite(PINO_LED1, HIGH);
      digitalWrite(PINO_LED2, LOW);
      break;

    case 2:
      digitalWrite(PINO_LED1, LOW);
      digitalWrite(PINO_LED2, HIGH);
      break;

    case 3:
      digitalWrite(PINO_LED1, LOW);
      digitalWrite(PINO_LED2, LOW);
      break;
  }
}

void setup() {
  pinMode(PINO_LED1, OUTPUT);
  pinMode(PINO_LED2, OUTPUT);
  pinMode(PINO_BOTAO, INPUT_PULLUP);

  digitalWrite(PINO_LED1, LOW);
  digitalWrite(PINO_LED2, LOW);
}

void loop() {
  int leituraAtual = digitalRead(PINO_BOTAO);

  if (leituraAtual != estadoBotaoAnterior) {
    ultimoTempoDebounce = millis();
  }

  if ((millis() - ultimoTempoDebounce) > atrasoDebounce) {
    if (leituraAtual == LOW && estadoBotaoAnterior == HIGH) {
      estadoCiclo++;

      if (estadoCiclo > 3) {
        estadoCiclo = 1;
      }

      atualizarLEDs();
    }
  }

  estadoBotaoAnterior = leituraAtual;
}
