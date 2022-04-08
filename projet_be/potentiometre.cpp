#include "potentiometre.h"
#include <Arduino.h>

potentiometre::potentiometre():capteur(){
  this->position = 0 ;
  this->angle = 0 ;
  this->voltage = 0 ;
}

void potentiometre::init(){
  pinMode(PIN_POT,INPUT);
}

float potentiometre::getVoltage() {
  this->voltage = (float)analogRead(PIN_POT)*VOLTAGE_REF/1023;
  return this->voltage ;
}

float potentiometre::getAngle() {
  this->angle = this->getVoltage()*ANGLE_MAX/VOLTAGE_REF;
  return this->angle ;
}

int potentiometre::getPosition() {
  if (this->getVoltage()<1.35) {
    this->position = 1 ;
  } else {
    this->position = 2 ;
  }
  return this->position ;
}
