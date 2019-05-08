#include <Servo.h>

Servo droite;
Servo gauche;
int traits = 0;
// Décrire cette fonction
void tdroite() {
  droite.write(83);
  gauche.write(110);
}

// Décrire cette fonction
void tgauche() {
  droite.write(75);
  gauche.write(97);
}

// Décrire cette fonction
void arret() {
  droite.write(90);
  gauche.write(90);
}

// Décrire cette fonction
void avancer() {
  droite.write(0);
  gauche.write(180);
}

//Décrire cette fonction
void trait() {
  droite.write(0);
  gauche.write(180);
}


void setup() {
  droite.attach(3);
  gauche.attach(2);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  Serial.begin(9600);

}

void loop() {
    if (digitalRead(6) && !digitalRead(7)) {
      tdroite();
      Serial.println("droite");
    }
    if (!digitalRead(6) && digitalRead(7)) {
      tgauche();
      Serial.println("gauche");
    }
    if (!digitalRead(6) && !digitalRead(7)) {
      if (traits == 8){
        arret();
      }
      else {
        trait();
        delay(130);
        traits++;
      }
      Serial.println("arret");
    }
    if (digitalRead(6) && digitalRead(7)) {
      avancer();
      Serial.println("avance");
    }

}
