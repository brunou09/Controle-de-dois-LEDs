// C++ code
int buttonPin = 7;
int ledPin = 10;
int ledPin2 = 11;

int estadoCiclo = 0;
int ultimoEstado = HIGH; 
 


void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  
  digitalWrite(ledPin, LOW);
  digitalWrite(ledPin2, LOW);
}

void loop() {
int atualEstado = digitalRead(buttonPin);

  if (atualEstado == LOW && ultimoEstado == HIGH){
    estadoCiclo++;
    
    if (estadoCiclo > 2) {
      estadoCiclo = 0;
    }

    if (estadoCiclo == 0) {
      digitalWrite(ledPin, LOW);
      digitalWrite(ledPin2, LOW);
    } 
    else if (estadoCiclo == 1) {
      digitalWrite(ledPin, HIGH);
      digitalWrite(ledPin2, LOW);
    } 
    else if (estadoCiclo == 2) {
      digitalWrite(ledPin, LOW);
      digitalWrite(ledPin2, HIGH);
    }

    delay(50);


}
    ultimoEstado = atualEstado;
}
  estadoBotaoAnterior = leituraAtual;
}
