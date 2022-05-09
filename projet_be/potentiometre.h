#ifndef POTENTIOMETRE_H
#define POTENTIOMETRE_H

#include "capteur.h"

#define VOLTAGE_REF 3.3
#define ANGLE_MAX 300
#define PIN_POT A0

class potentiometre : public capteur {
  private :
  int position ;
  float voltage ;
  float angle ;

  public :
  potentiometre();
  virtual void init();
  float getVoltage();
  float getAngle();
  int getPosition();
};

#endif
