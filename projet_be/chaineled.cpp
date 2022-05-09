#include "chaineled.h"
#include <Arduino.h>


chaineled::chaineled(int clk, int data, int num_led):ChainableLED(clk, data,num_led){
  this->etat = new bool[num_led];
  this->nled = num_led ;
}


void chaineled::eteint() {
  for (int i=0;i<this->nled;i++) {
    this->setColorRGB(i,0,0,0);
    this->etat[i]=false;
  }
}

void chaineled::allume(int r, int g, int b){
   for (int i=0;i<this->nled;i++) {
    this->setColorRGB(i,r,g,b);
    this->etat[i]=true;
  }
}

//void sequence();

bool chaineled::getEtat(int indice) {
  return this->etat ;
}

void chaineled::afficherDe(int resultat) {
  int r = 0;
  int g = 255;
  int b = 0;
  this->eteint();
  switch (resultat){
    case 1 : setColorRGB(3, r,g,b);
    break;
    case 2 : setColorRGB(0, r,g,b); setColorRGB(4, r,g,b);
    break;
    case 3 : setColorRGB(0, r,g,b); setColorRGB(3, r,g,b); setColorRGB(4, r,g,b);
    break;
    case 4 : setColorRGB(0, r,g,b); setColorRGB(2, r,g,b); setColorRGB(6, r,g,b); setColorRGB(4, r,g,b);
    break;
    case 5: setColorRGB(0, r,g,b); setColorRGB(2, r,g,b); setColorRGB(3, r,g,b); setColorRGB(6, r,g,b);setColorRGB(4, r,g,b);
    break;
    case 6:  setColorRGB(0, r,g,b); setColorRGB(1, r,g,b); setColorRGB(2, r,g,b); setColorRGB(6, r,g,b);setColorRGB(5, r,g,b);setColorRGB(4, r,g,b);
    break;         
  }
}

void chaineled::sequence(int repet, ecran ecran) {
  int r = 0 ;
  int g = 200 ;
  int b = 0 ;
  this->eteint();
  ecran.clear();
  for (int i=0 ; i<repet ; i++) {
    for (int led=0; led<7; led++){
      this->setColorRGB(led,r,g,b);
      delay(100);
      this->setColorRGB(led,0,0,0);
      if ((led)!=5){
        this->setColorRGB(led+1,r,g,b);
      }
    }
    for (int led2=6; led2>-1; led2=led2-3) {
      this->setColorRGB(led2,r,g,b);
      delay(100);
      this->setColorRGB(led2,0,0,0);
      if ((led2-3)!=0){
        this->setColorRGB(led2-3,r,g,b);
      }
    }
  }
  this->eteint();
}

void chaineled::chrono(float secondes, ecran ecran) {
  float pas = (secondes/150.0)*1000.0;
  float pascorrige = pas - 0.10*1000 ;
  float temps = 0 ;
  this->eteint();
  for (int j=1 ; j<51 ; j++) {
    delay(pascorrige);
    temps = temps + pas/1000 ;
    this->setColorHSL(2,0,1,j*0.01);
    this->setColorHSL(4,0,1,j*0.01);
    ecran.afficher_chiffre(secondes-temps, 255, 0, 0);
  }
    for (int j=1 ; j<51 ; j++) {
    delay(pascorrige);
    temps = temps + pas/1000 ;
    this->setColorHSL(1,0,1,j*0.01);
    this->setColorHSL(3,0,1,j*0.01);
    this->setColorHSL(5,0,1,j*0.01);
    ecran.afficher_chiffre(secondes-temps, 255, 0, 0);
  }
    for (int j=1 ; j<51 ; j++) {
    delay(pascorrige);
    temps = temps + pas/1000 ;
    this->setColorHSL(0,0,1,j*0.01);
    this->setColorHSL(6,0,1,j*0.01);
    ecran.afficher_chiffre(secondes-temps, 255, 0, 0);
  } 
}
