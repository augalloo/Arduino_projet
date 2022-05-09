#ifndef MON_APPLI_H
#define MON_APPLI_H

#include "bouton.h"
#include "potentiometre.h"
#include "chaineled.h"
#include "ecran.h"
#include "buzzer.h"

/*
 * Cette classe est la classe application du projet. Elle ne comporte que deux fonctions qui sont directement utilisé dans le main (projet_be.ino).
 */

//Déclaration des constantes (numéro de broche ou valeurs de références des composants)
#define PIN_LEDC 13
#define PIN_LEDD 15
#define N_LED 7
#define PIN_BUZ 12
#define PIN_BOU 14
#define VOLTAGE_REF 3.3
#define ANGLE_MAX 300
#define PIN_POT A0


class monappli {

  private://Attributs
  bouton bou;
  potentiometre pot;
  chaineled ledled ;
  ecran ecranlcd; 
  int de ;
  buzzer buzz ;
  int affiche ;

  public:

  //Constructeur
  monappli();

  //Méthodes
  void init();
  void loop();
};

#endif
