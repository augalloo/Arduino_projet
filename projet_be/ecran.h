#ifndef ECRAN_H
#define ECRAN_H

#include <Wire.h>
#include "rgb_lcd.h"
#include "actionneur.h"

/*
 * La classe ecran est une classe fille de actionneur et de rgb_lcd (bibliothèque). Elle ne possède pas d'attributs.
 */

class ecran : public rgb_lcd, public actionneur {
  
  public:
  //Constructeur
  ecran();

  //Méthodes
  virtual void init();
  void afficher_option(int position);
  void afficher_chiffre(int chiffre, int r, int g, int b);
  void afficher_texte(String texte, int r, int g, int b);
  
  
};

#endif
