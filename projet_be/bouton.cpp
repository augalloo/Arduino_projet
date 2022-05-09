#include "bouton.h"
#include <Arduino.h>

bouton::bouton(int pin):capteur() {
  this->etat = false ;
  this->pin = pin ;
}

void bouton::init() {
  pinMode(this->pin,INPUT);
}
bool bouton::getEtat() {
  this->etat = digitalRead(this->pin);
  return this->etat ;
}
