#include "buzzer.h"
#include <Arduino.h>



buzzer::buzzer(int pin):actionneur() {
  this->etat = false ;
  this->pin = pin ;
}

void buzzer::init() {
  pinMode(this->pin, OUTPUT);
}

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

void buzzer::sonne() {
  digitalWrite(this->pin, HIGH);
  this->etat = true ;
}

void buzzer::eteint() {
  digitalWrite(this->pin, LOW);
  this->etat = false ;
}

bool buzzer::getEtat() {
  this->etat = digitalRead(this->pin);
  return this->etat ;
}
