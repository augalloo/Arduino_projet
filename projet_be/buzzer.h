#ifndef BUZZER_H
#define BUZZER_H

#include "chaineled.h"
#include "actionneur.h"

/*
 * La classe buzzer est une classe fille de la classe actionneur. Elle possède 2 attributs (etat, pin).
 */

class buzzer : public actionneur {
  
  private : //Attributs
  bool etat ;
  int pin ;
  
  public :
  //Constructeur
  buzzer(int pin);

  //Méthodes
  virtual void init();
  void alarme(int secondes, chaineled led);
  void sonne();
  void eteint();
  bool getEtat();
};

#endif
