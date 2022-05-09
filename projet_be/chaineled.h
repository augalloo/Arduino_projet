#ifndef LEDS_H
#define LEDS_H

#include <ChainableLED.h>
#include "ecran.h"



class chaineled : public ChainableLED {
  private:
  bool *etat;
  int nled ;
  
  public:
  chaineled(int clk, int data, int num_led);
  void eteint();
  void allume(int r, int g, int b);
  void sequence(int repet, ecran ecran);
  bool getEtat(int indice);
  void afficherDe(int resultat) ;
  void chrono(float secondes, ecran ecran);
};


#endif
