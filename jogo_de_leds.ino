int tempo = 600;
int nivel = 0;

void setup() {
  // Configuração inicial
  Serial.begin(9600);
  pinMode(13, INPUT);

  for (int x = 2; x <= 12; x++) {
    pinMode(x, OUTPUT);
  }

  Serial.print("Nivel --> ");
  Serial.println(nivel);
}

void loop() {
  // Loop principal
  for (int x = 2; x <= 12; x++) {
    digitalWrite(x, HIGH);
    delay(tempo);

    if (digitalRead(13) == 1) {
      while (digitalRead(13));

      if (x == 8) {
        nivel = nivel + 1;
        Serial.print("Nivel --> ");
        Serial.println(nivel);
        tempo -= 50;
        if(nivel == 10){
          Serial.println("Você ganhou!");
        }
      } else {
        Serial.println("GAME OVER");
        game_over();
        tempo = 600;
        nivel = 0;
        Serial.print("Nivel --> ");
        Serial.println(nivel);
        return;
      }
    }

    digitalWrite(x, LOW);
  }

  for (int x = 12; x >= 2; x--) {
    digitalWrite(x, HIGH);
    delay(tempo);
    digitalWrite(x, LOW);

    if (digitalRead(13) == 1) {
      while (digitalRead(13));

      if (x == 8) {
        nivel = nivel + 1;
        Serial.print("Nivel --> ");
        Serial.println(nivel);
        tempo -= 50;
        if(nivel == 10){
          Serial.println("Você ganhou!");
        }
      } else {
        Serial.println("GAME OVER");
        game_over();
        tempo = 600;
        nivel = 0;
        Serial.print("Nivel --> ");
        Serial.println(nivel);
        return;
      }
    }
  }
}

void game_over() {
  for (int j = 0; j < 4; j++) {
    for (int x = 2; x <= 12; x++) {
      digitalWrite(x, HIGH);
      digitalWrite(14 - x, HIGH);
      delay(100);
      digitalWrite(x, LOW);
      digitalWrite(14 - x, LOW);
    }
  }
}
