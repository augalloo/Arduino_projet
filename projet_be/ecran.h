#ifndef ECRAN_H
#define ECRAN_H
#include <Wire.h>
#include "rgb_lcd.h"
#include "actionneur.h"

class ecran : public rgb_lcd, public actionneur {
  private:
  public:
  ecran();
  virtual void init();
  void afficher_option(int position);
  void afficher_chiffre(int chiffre, int r, int g, int b);
  void afficher_texte(String texte, int r, int g, int b);
  
  
};

#endif
