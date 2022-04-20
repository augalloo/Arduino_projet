#ifndef LEDS_H
#define LEDS_H

#include <ChainableLED.h>
#include "ecran.h"

#define PIN_LEDC 13
#define PIN_LEDD 15
#define N_LED 7

class chaineled : public ChainableLED {
  private:
  bool *etat;
  
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
