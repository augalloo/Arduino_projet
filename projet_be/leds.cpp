#include "leds.h"
#include <Arduino.h>

leds::leds(){
  this->chaine = ChainableLED(PIN_LEDC, PIN_LEDD, N_LED);
  this->etat = new bool[N_LED];
}

void leds::init() {
  this->chaine.init();
}

void leds::eteint() {
  for (int i=0;i<N_LED;i++) {
    this->chaine.setColorRGB(i,0,0,0);
    this->etat[i]=false;
  }
}

void leds::allume(int r, int g, int b){
  for (int i=0;i<N_LED;i++) {
    this->chaine.setColorRGB(i,r,g,b);
    this->etat[i]=true;
  }
}

//void sequence();

bool leds::getEtat(int indice) {
  return this->etat ;
}
