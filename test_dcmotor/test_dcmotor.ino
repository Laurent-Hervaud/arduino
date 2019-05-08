int pinMoteur=10; //pin de commande relié au transistor
int sens = 1;

void setup() {
  Serial.begin(9600);
//Initialise the Motor outpu pins
    pinMode (8, OUTPUT);
    pinMode (9, OUTPUT);
    pinMode (10, OUTPUT);
    pinMode (11, OUTPUT);

//By default turn off both the motors
    analogWrite(8,LOW);
    analogWrite(9,LOW);
    analogWrite(10,LOW);
    analogWrite(11,LOW);

  pinMode(8,OUTPUT); // pin de commande en mode sortie
  pinMode(10,OUTPUT); // pin de commande en mode sortie
}

void loop() {
  
  for (int pourcentage=0;pourcentage<=100;pourcentage+=25){//boucle de variation en %
    //int valeur8=map(pourcentage,0,100,0,255); //conversion en valeur
    //int valeur10=map(pourcentage,0,100,0,255); //conversion en valeur
    double valeur8 = -140;
    double valeur10 = -140;
    analogWrite(8,valeur8); // pin de commande en mode impulsion
    analogWrite(10,valeur10); // pin de commande en mode impulsion
    //analogWrite(11,0);
    Serial.print(valeur10);
    Serial.print("\n");
    delay (3000); // attente de 3 secondes
  }
  sens = sens * -1;
}
