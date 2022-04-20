#include "buzzer.h"
#include <Arduino.h>



buzzer::buzzer() {
  this->etat = false ;
}

void buzzer::init() {
  pinMode(PIN_BUZ, OUTPUT);
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
  digitalWrite(PIN_BUZ, HIGH);
  this->etat = true ;
}

void buzzer::eteint() {
  digitalWrite(PIN_BUZ, LOW);
  this->etat = false ;
}

bool buzzer::getEtat() {
  this->etat = digitalRead(PIN_BUZ);
  return this->etat ;
}

void buzzer::tetris() {
  tone(PIN_BUZ, 2637, 200);
  delay(400);
  tone(PIN_BUZ, 1975, 200);
  delay(200);
  tone(PIN_BUZ, 2093, 200);
  delay(200);
  tone(PIN_BUZ, 2349, 200);
  delay(400);
  tone(PIN_BUZ, 2093, 200);
  delay(200);
  tone(PIN_BUZ, 1975, 200);
  delay(200);
  tone(PIN_BUZ, 1760, 200);
  delay(400);
  tone(PIN_BUZ, 1760, 200);
  delay(200);
  tone(PIN_BUZ, 2093, 200);
  delay(200);
  tone(PIN_BUZ, 2637, 200);
  delay(400);
  tone(PIN_BUZ, 2349, 200);
  delay(200);
  tone(PIN_BUZ, 2093, 200);
  delay(200);
  tone(PIN_BUZ, 1975, 200);
  delay(400);
  tone(PIN_BUZ, 1975, 200);
  delay(200);
  tone(PIN_BUZ, 2093, 200);
  delay(200);
  tone(PIN_BUZ, 2349, 200);
  delay(400);
  tone(PIN_BUZ, 2637, 200);
  delay(400);
  tone(PIN_BUZ, 2093, 200);
  delay(400);
  tone(PIN_BUZ, 1760, 200);
  delay(400);
  tone(PIN_BUZ, 1760, 200);
  delay(800);
  tone(PIN_BUZ, 1760, 200);
  delay(400);
  tone(PIN_BUZ, 2349, 200);
  delay(200);
  tone(PIN_BUZ, 2794, 200);
  delay(200);
  tone(PIN_BUZ, 3520, 200);
  delay(400);
  tone(PIN_BUZ, 3136, 200);
  delay(200);
  tone(PIN_BUZ, 2794, 200);
  delay(200);
  tone(PIN_BUZ, 2637, 200);
  delay(600);
  tone(PIN_BUZ, 2093, 200);
  delay(200);
  tone(PIN_BUZ, 2637, 200);
  delay(400);
  tone(PIN_BUZ, 2349, 200);
  delay(200);
  tone(PIN_BUZ, 2093, 200);
  delay(200);
  tone(PIN_BUZ, 1975, 200);
  delay(400);
  tone(PIN_BUZ, 1975, 200);
  delay(200);
  tone(PIN_BUZ, 2093, 200);
  delay(200);
  tone(PIN_BUZ, 2349, 200);
  delay(400);
  tone(PIN_BUZ, 2637, 200);
  delay(400);
  tone(PIN_BUZ, 2093, 200);
  delay(400);
  tone(PIN_BUZ, 1760, 200);
  delay(400);
  tone(PIN_BUZ, 1760, 200);
  delay(800);
}
