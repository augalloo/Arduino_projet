#include "chaineled.h"
#include <Arduino.h>

chaineled::chaineled(){
  this->etat = new bool[N_LED];
}


void chaineled::init() {
  this->chaine.init();
}

void chaineled::eteint() {
  for (int i=0;i<N_LED;i++) {
    this->chaine.setColorRGB(i,0,0,0);
    this->etat[i]=false;
  }
}

void chaineled::allume(int r, int g, int b){
  for (int i=0;i<N_LED;i++) {
    this->chaine.setColorRGB(i,r,g,b);
    this->etat[i]=true;
  }
}

//void sequence();

bool chaineled::getEtat(int indice) {
  return this->etat ;
}
