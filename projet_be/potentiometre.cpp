#include "potentiometre.h"
#include <Arduino.h>

/*
 * Implémentation des fonctions de la classe potentiometre.
 */

//Constructeur
potentiometre::potentiometre(int pin, float voltage_ref, float angle_max):capteur(){
  this->position = 0 ;
  this->angle = 0 ;
  this->voltage = 0 ;
  this->voltage_ref = voltage_ref ;
  this->angle_max = angle_max ;
  this->pin = pin ;
}

//Fonction d'initialisation
void potentiometre::init(){
  pinMode(this->pin,INPUT);
}

//A chaque appel de getVoltage, le voltage du potentiomètre est réactualisé avant d'être retourné par la fonction.
float potentiometre::getVoltage() {
  this->voltage = (float)analogRead(this->pin)*this->voltage_ref/1023;
  return this->voltage ;
}

//A chaque appel de getAngle, l'angle du potentiomètre est réactualisé avant d'être retourné par la fonction.
float potentiometre::getAngle() {
  this->angle = this->getVoltage()*this->angle_max/this->voltage_ref;
  return this->angle ;
}

//Cette fonction renvoie 1 ou 2 en fonction de la position du potentiomètre et donc de son voltage (moitié supérieure ou inférieure).
int potentiometre::getPosition() {
  if (this->getVoltage()<1.35) {
    this->position = 1 ;
  } else {
    this->position = 2 ;
  }
  return this->position ;
}
