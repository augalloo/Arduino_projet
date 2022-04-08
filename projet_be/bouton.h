#ifndef BOUTON_H
#define BOUTON_H
#include "capteur.h"

#define PIN_BOU 14


class bouton : public capteur {
  private:
  bool etat ;

  public:
  bouton();
  void init();
  bool getEtat();
};


#endif
