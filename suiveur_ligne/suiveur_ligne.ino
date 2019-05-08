void setup() {
  Serial.begin(9600);
  pinMode(6, INPUT);
  pinMode(7, INPUT);

}

void loop() {
    if (!digitalRead(7) && digitalRead(6)) {
      Serial.println("droite");

    }
    if (digitalRead(7) && !digitalRead(6)) {
      Serial.println("gauche");

    }
    if (digitalRead(7) && digitalRead(6)) {
      Serial.println("avance");

    }
    if (!digitalRead(7) && !digitalRead(6)) {
      Serial.println("arret");
    }

    delay(500);

}
