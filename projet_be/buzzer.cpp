#include "buzzer.h"
#include <Arduino.h>

/*
 * Implémentation des fonctions de la classe buzzer.
 */

//Constructeur
buzzer::buzzer(int pin):actionneur() {
  this->etat = false ;
  this->pin = pin ;
}

void buzzer::init() {
  pinMode(this->pin, OUTPUT);
}

//Cette fonction fait sonner le buzzer en rythme avec les LED pendant une periode définie de temps.
void buzzer::alarme(int secondes, chaineled led) {
  for (int i=0; i<secondes ; i++) {
    this->sonne();
    led.allume(255,0,0);
    delay(500);
    this->eteint();
    led.eteint();
    delay(500);
  }
}

//Fonction qui met le buzzer sur ON.
void buzzer::sonne() {
  digitalWrite(this->pin, HIGH);
  this->etat = true ;
}

//Fonction qui met le buzzer sur OFF.
void buzzer::eteint() {
  digitalWrite(this->pin, LOW);
  this->etat = false ;
}

//A chaque appel de getEtat, l'état du buzzer est réactualisé avant d'être retourné par la fonction.
bool buzzer::getEtat() {
  this->etat = digitalRead(this->pin);
  return this->etat ;
}
