#ifndef POTENTIOMETRE_H
#define POTENTIOMETRE_H

#include "capteur.h"

/*
 * La classe potentiometre est une classe fille de actionneur. Elle possède 4 attributs réels (voltage, angle, position et pin) et
 * 2 autres attributs étant des constantes (voltage_ref = 3.3V et angle_max = 300)
 */

class potentiometre : public capteur {
  
  private : //Attributs
  int position ;
  float voltage ;
  float angle ;
  float voltage_ref ;
  float angle_max ;
  int pin ;
  
  public :
  //Constructeur
  potentiometre(int pin, float voltage_ref, float angle_max);

  //Méthodes
  virtual void init();
  float getVoltage();
  float getAngle();
  int getPosition();
};

#endif
