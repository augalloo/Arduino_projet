#ifndef BOUTON_H
#define BOUTON_H

#include "capteur.h"

/*
 * La classe bouton est une classe fille de capteur. Elle possède 2 attributs (etat, pin).
 */


class bouton : public capteur {
  
  private: // Attributs
  bool etat ;
  int pin ;

  public:
  //Constructeur
  bouton(int pin);

  //Méthodes
  virtual void init();
  bool getEtat();
};


#endif
