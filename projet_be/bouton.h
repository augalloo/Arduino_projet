#ifndef BOUTON_H
#define BOUTON_H
#include "capteur.h"




class bouton : public capteur {
  private:
  bool etat ;
  int pin ;

  public:
  bouton(int pin);
  virtual void init();
  bool getEtat();
};


#endif
