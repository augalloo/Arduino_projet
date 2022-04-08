#include "bouton.h"
#include "potentiometre.h"
#include "leds.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  
}

bouton coucou;
potentiometre pot;

leds ledasse ;

void loop() {
  ledasse.init();
  ledasse.allume(255,0,0);
  delay(500);
  ledasse.eteint();
}
