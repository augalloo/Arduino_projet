#include "bouton.h"
#include <Arduino.h>

/*
 * Implémentation des fonctions de la classe bouton.
 */

//Constructeur
bouton::bouton(int pin):capteur() {
  this->etat = false ;
  this->pin = pin ;
}

void bouton::init() {
  pinMode(this->pin,INPUT);
}

//A chaque appel de getEtat, l'état du bouton est réactualisé avant d'être retourné par la fonction.
bool bouton::getEtat() {
  this->etat = digitalRead(this->pin);
  return this->etat ;
}
