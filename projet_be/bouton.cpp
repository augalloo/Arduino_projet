#include "bouton.h"
#include <Arduino.h>

bouton::bouton():capteur() {
  this->etat = false ;
}

void bouton::init() {
  pinMode(PIN_BOU,INPUT);
}
bool bouton::getEtat() {
  this->etat = digitalRead(PIN_BOU);
  return this->etat ;
}
