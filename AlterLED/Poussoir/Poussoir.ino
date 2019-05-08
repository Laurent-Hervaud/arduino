/*

le bouton poussoir est connecté au pin 2 avec un résistance pull-down

les leds sont connectées au pins 4 et 6 avec des resistances de 220Ω

*/


//déclaration des variables
int pinBouton, pinLed1, pinLed2;

void setup()
{
  //initialisation des variables
  pinBouton = 2;
  pinLed1 = 4;
  pinLed2 = 6;
  //définition des modes
  pinMode(pinBouton, INPUT);
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);

}

void loop()
{
  //lecture de l'état du bouton et stockage dans etatBouton
  boolean etatBouton = digitalRead(pinBouton);
  //test des conditions
  if (etatBouton)//si bouton appuyé (donc 1)
  {
    digitalWrite(pinLed1,LOW);
    digitalWrite(pinLed2,HIGH);
  }
  else //sinon
  {
    digitalWrite(pinLed1,HIGH);
    digitalWrite(pinLed2,LOW);
  }
  delay(100);
}
