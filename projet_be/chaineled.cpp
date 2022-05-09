#include "chaineled.h"
#include <Arduino.h>

/*
 * Implémentation des fonctions de la classe chaineled.
 */

 //Constructeur
chaineled::chaineled(int clk, int data, int num_led):ChainableLED(clk, data,num_led){
  this->etat = new bool[num_led];
  this->nled = num_led ;
}

//Met la chaine LED sur OFF.
void chaineled::eteint() {
  for (int i=0;i<this->nled;i++) {
    this->setColorRGB(i,0,0,0);
    this->etat[i]=false;
  }
}

//Met la chaine LED sur ON.
void chaineled::allume(int r, int g, int b){
   for (int i=0;i<this->nled;i++) {
    this->setColorRGB(i,r,g,b);
    this->etat[i]=true;
  }
}

//Assesseur du tableau d'état de la chaine
bool chaineled::getEtat(int indice) {
  return this->etat ;
}

//Cette fonction affiche une configuration différente de LED allumées/éteintes pour chaque résultat possible du dé (1..6).
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

//La fonction sequence permet de déplacer une LED allumée le long de la chaine, suivant un motif prédéfini.
//Elle est utilisée avant d'afficher le résultat du dé.
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

//La fonction chrono lance le second mode du programme qui allume progressivement les LED décomposées en 3 sous-groupes. Après n secondes, toutes les LED seront complétement allumées.
//Chaque led possède 50 niveaux de luminosité qui changent à chaque pas.
//Un pas corrigé a été mis en place empirement afin de compenser le retard dû au temps de calcul.
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
