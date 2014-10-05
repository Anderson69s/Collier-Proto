int ledG = 0;//On définit le port de la première rangé de LED 
int ledD = 1;//On définit le port de la seconde rangé de LED
int phre = 0;//On définit le port de la photo resistance
 
void setup()
{
//Serial.begin(9600); //On peut faire du Serial @ 9600 baud
pinMode(ledG, OUTPUT); //On définit les port en OUTPUT
pinMode(ledD, OUTPUT); //On définit les port en OUTPUT
}

void loop()
{
phre = analogRead(1); //On lit la valeur de la photo résistance
phre = map(phre, 0, 200, 255, 0); //On map la valeur de la photo résistance en fonction de l'amplitude de PWN
phre = constrain(phre, 0, 255); //On restreint le nouvel interval entre à-255
analogWrite(ledG, phre ); //On utilise la lecture de la photo résistance pour piloter les LED
analogWrite(ledD, phre ); //On utilise la lecture de la photo résistance pour piloter les LED

}
