#ifndef MON_APPLI_H
#define MON_APPLI_H

#include "bouton.h"
#include "potentiometre.h"
#include "chaineled.h"
#include "ecran.h"
#include "buzzer.h"

#define PIN_LEDC 13
#define PIN_LEDD 15
#define N_LED 7
#define PIN_BUZ 12
#define PIN_BOU 14


class monappli {

  private:
  bouton bou;
  potentiometre pot;
  chaineled ledled ;
  ecran ecranlcd; 
  int de ;
  buzzer buzz ;
  int affiche ;

  public:
  
  monappli();
  
  void init();

  void loop();
};

#endif
