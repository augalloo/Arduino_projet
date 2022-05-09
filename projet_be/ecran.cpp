#include "potentiometre.h" ; 
#include "ecran.h";
#include <Arduino.h>

/*
 * Implémentation des fonctions de la classe ecran.
 */

//Constructeur sans arguments
ecran::ecran():rgb_lcd(),actionneur(){
}

//Cette fonction d'initialisation permet de mettre en place la configuration permet de faire fonctionner l'écran.
//Elle y affiche ensuite un message d'accueil pour une durée de 3 secondes.
void ecran::init() {
  this->begin(16,2);
  this->clear();
  this->home();
  this->setRGB(255,192,203);
  this->print(" W E L C O M E !");
  delay(3000);
}

//Cette fonction permet d'afficher l'option désirée (1..2) et le texte qui y est associé.
void ecran::afficher_option(int position) {
  this->begin(16,2);
  this->clear();
  this->display();
  if (position==1) {
    this->setRGB(0,255,0);
    this->print("Option 1");
    this->setCursor(0,1);
    this->print("Appuyer bouton");
  }
  else {
    this->setRGB(255,0,0);
    this->print("Option 2");
    this->setCursor(0,1);
    this->print("Appuyer bouton");
    
  }

  
}

//Cette fonction permet d'afficher un chiffre avec la couleur désirée en fond (composantes RGB)
void ecran::afficher_chiffre(int chiffre, int r, int g, int b) {
  this->clear();
  this->home();
  this->setRGB(r,g,b);
  this->print(chiffre);
  
}

//Cette fonction permet d'afficher un texte avec la couleur désirée en fond (composantes RGB)
//Fonction créée mais finalement non utilisée.
void ecran::afficher_texte(String texte, int r, int g, int b) {
  this->clear();
  this->home();
  this->setRGB(r,g,b);
  this->print(texte);  
}
