//déclaration des variables
int pinBouton, pinLed1, etat;

void setup()
{
  //initialisation des variables
  etat = 0;
  pinBouton = 2;
  pinLed1 = 4;
  //définition des modes
  pinMode(pinBouton, INPUT_PULLUP);
  pinMode(pinLed1, OUTPUT);
  digitalWrite(pinLed1,etat);

}

void loop()
{
  //lecture de l'état du bouton et stockage dans etatBouton
  boolean etatBouton = digitalRead(pinBouton);
  //test des conditions
  if (etatBouton == 0)//si bouton appuyé en PULLUP (donc 0)
  {
    if (etat == 0)
      etat = 1;
    else
      etat = 0;
    digitalWrite(pinLed1,etat);;      
  }
  delay(200);
}
