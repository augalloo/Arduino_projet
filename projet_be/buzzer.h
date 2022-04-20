#ifndef BUZZER_H
#define BUZZER_H
#include "chaineled.h"

#define PIN_BUZ 12

class buzzer {
  private :
  bool etat ;
  
  public :
  buzzer();
  void init();
  void alarme(int secondes, chaineled led);
  void sonne();
  void eteint();
  bool getEtat();
  void tetris();
};

#endif
