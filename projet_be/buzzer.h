#ifndef BUZZER_H
#define BUZZER_H
#include "chaineled.h"
#include "actionneur.h"



class buzzer : public actionneur {
  private :
  bool etat ;
  int pin ;
  
  public :
  buzzer(int pin);
  virtual void init();
  void alarme(int secondes, chaineled led);
  void sonne();
  void eteint();
  bool getEtat();
  void tetris();
};

#endif
