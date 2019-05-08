const int NBLED=14;
int pinLed[14]={0,1,2,3,4,5,6,7,8,9,10,11,12,13};

void setup() {
  for (int i=0;i<NBLED;i++)
  {
    pinMode(pinLed[i],OUTPUT);
    digitalWrite(pinLed[i],LOW);
  }  
}

void loop() {
}
