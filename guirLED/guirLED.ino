const int NBLED=12;
const int NBSEQUENCES=14;
int pinLed[12]={1,2,3,4,5,6,7,8,9,10,11,12}; // Tableau listant les pins

//Tableau à double entrée listant l’état (booléen 1 allumé, 0 éteint) des LED à chaque séquence
boolean affichage[NBSEQUENCES][NBLED]={
  0,0,0,0,0,0,0,0,0,0,0,0,
  1,0,0,0,0,0,0,0,0,0,0,0,
  0,1,0,0,0,0,0,0,0,0,0,0,
  0,0,1,0,0,0,0,0,0,0,0,0,
  0,0,0,1,0,0,0,0,0,0,0,0,
  0,0,0,0,1,0,0,0,0,0,0,0,
  0,0,0,0,0,1,0,0,0,0,0,0,
  0,0,0,0,0,0,1,0,0,0,0,0,
  0,0,0,0,0,0,0,1,0,0,0,0,
  0,0,0,0,0,0,0,0,1,0,0,0,
  0,0,0,0,0,0,0,0,0,1,0,0,
  0,0,0,0,0,0,0,0,0,0,1,0,
  0,0,0,0,0,0,0,0,0,0,0,1,
  1,1,1,1,1,1,1,1,1,1,1,1};

void setup() {
  for (int i=0;i<NBLED;i++)
  {
    pinMode(pinLed[i],OUTPUT);
    digitalWrite(pinLed[i],LOW);
  }
  
}

void loop() {
  for (int i=0;i<NBSEQUENCES;i++) // boucle de séquence d'affichage
  {
    for (int p=0;p<NBLED;p++) // boucle pour chaque pin
    {
      boolean etat=affichage[i][p]; // on va chercher l'état pour le pin
      digitalWrite(pinLed[p],etat); // on met le pin concerné à l'état
    }
    //tous les pins sont dans l'état de la séquence en cours
    delay(300); //petite pause d'affichage
    // on passe à la séquence suivante
  }
  // fin des séquences et on repart au début de la loop()
  delay(3000);

}
