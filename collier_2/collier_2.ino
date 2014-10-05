//Définition des pins
int led1 = 5;
int led2 = 6;
int led3 = 7;
int led4 = 8;
int led5 = 11;
int led6 = 12;
int led7 = 13;

// SETUP
void setup() {    
  // initialisation des ports 5 à 14 en sorties
  for(int x=5; x<14; x++){
    pinMode(x, OUTPUT); 
  } 
  // On éteint toutes les leds
  for(int x=5; x<14; x++){
    digitalWrite(x, LOW);
  }

}
//LOOP
void loop() {
  //On lit la photo-résistance
  int lumi = analogRead(A3);
  //Si la valeur est supérieure à 80
  if (lumi > 80) {
    //On éteint toutes les leds
    for(int x=5; x<14; x++){
      digitalWrite(x, LOW);
    }
  }
  //sinon
  else {
    int lumi1 = map(lumi, 0, 200, 255, 0); //On map la valeur de la photo résistance en fonction de l'amplitude de PWN
    int lumi2 = constrain(lumi1, 0, 255);//On fait sortir une valeur toujours supérieure ou égale à 0
    //On allume les leds avec notre valeur lumi2
    for(int x=5; x<14; x++){
      analogWrite(x, lumi2);
    }
  }
  //On attend une seconde
  delay(1000);
  //Et on recommence tout...
}















