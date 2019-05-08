const int TrigPin = 2; 
const int EchoPin = 3; 
float cm;
int indnote = 0;
const int speakerPin = 8;

//int length = 28; // the number of notes
int length = 16; // the number of notes
//char notes[] = "GGAGcB GGAGdc GGxecBA yyecdc";
char notes[] = " CDEFGABcdefgab ";
//int beats[] = { 2, 2, 8, 8, 8, 16, 1, 2, 2, 8, 8,8, 16, 1, 2,2,8,8,8,8,16, 1,2,2,8,8,8,16 };
//int beats[] = { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4};
int beat = 2;
int tempo = 150;

void playTone(int tone, int duration) {

  for (long i = 0; i < duration * 1000L; i += tone * 2) {
     digitalWrite(speakerPin, HIGH);
     delayMicroseconds(tone);
     digitalWrite(speakerPin, LOW);
     delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {

  char names[] = {'C', 'D', 'E', 'F', 'G', 'A', 'B',
                   'c', 'd', 'e', 'f', 'g', 'a', 'b',
                   'x', 'y' };
  
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014,
                   956,  834,  765,  593,  468,  346,  224,
                   655 , 715 };
  
  int SPEE = 5;
  
  // play the tone corresponding to the note name
  
  for (int i = 0; i < 17; i++) {
  
    if (names[i] == note) {
      int newduration = duration/SPEE;
      playTone(tones[i], newduration);
    }
  }
}


void setup() 
{ 
  Serial.begin(9600); 
  pinMode(TrigPin, OUTPUT); 
  pinMode(EchoPin, INPUT);
  pinMode(speakerPin, OUTPUT); 
} 

void loop() 
{ 
  digitalWrite(TrigPin, LOW); //Low high and low level to send a short pulse to TrigPin
  delayMicroseconds(2); 
  digitalWrite(TrigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(TrigPin, LOW); 
  
  cm = pulseIn(EchoPin, HIGH) / 58.0; //The echo time is converted into cm
  cm = (int(cm * 100.0)) / 100.0; //Keep two decimal places
  Serial.print(cm); 
  Serial.print("cm"); 
  Serial.println(); 

  indnote = (cm / 5) - 1;
  if (indnote > 15) indnote = 15;
  Serial.print("note :");
  Serial.println(indnote);
  playNote(notes[indnote], beat * tempo);
  //delay(tempo);
  delay(1);
}




/*  for (int i = 0; i < length; i++) {  
     if (notes[i] == ' ') {
       delay(beats[i] * tempo); // rest
     } else {
       playNote(notes[i], beats[i] * tempo);
     }
  
     // pause between notes
     delay(tempo);  
  }

 */
