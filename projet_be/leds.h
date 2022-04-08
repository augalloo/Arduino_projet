#ifndef LEDS_H
#define LEDS_H

#include <ChainableLED.h>
#define PIN_LEDC 13
#define PIN_LEDD 15
#define N_LED 5

class leds {
  private:
  ChainableLED chaine;
  bool *etat;
  
  public:
  leds();
  void init();
  void eteint();
  void allume(int r, int g, int b);
  void sequence();
  bool getEtat(int indice);
  
};


#endif
