#include "potentiometre.h" ; 
#include "ecran.h";
#include <Arduino.h>

ecran::ecran():rgb_lcd(),actionneur(){
}

void ecran::init() {
  this->begin(16,2);
  this->clear();
  this->home();
  this->setRGB(255,192,203);
  this->print(" W E L C O M E !");
  delay(3000);
}

void ecran::afficher_option(int position) {
  this->begin(16,2);
  this->clear();
  this->display();
  if (position==1) {
    this->setRGB(0,255,0);
    this->print("Option 1 frero");
    this->setCursor(0,1);
    this->print("Appuyer bouton");
  }
  else {
    this->setRGB(255,0,0);
    this->print("Option 2 frero");
    this->setCursor(0,1);
    this->print("Appuyer bouton");
    
  }

  
}

void ecran::afficher_chiffre(int chiffre, int r, int g, int b) {
  this->clear();
  this->home();
  this->setRGB(r,g,b);
  this->print(chiffre);
  
}

void ecran::afficher_texte(String texte, int r, int g, int b) {
  this->clear();
  this->home();
  this->setRGB(r,g,b);
  this->print(texte);  
}
