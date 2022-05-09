#include "monappli.h" 

/*
 * Implémentation des fonctions de la classe monappli.
 */

//Cette fonction permet de lancer la liaison série et d'initialiser tous les composants du projet qui sont aussi des attributs de la classe monappli.
void monappli::init() {
  Serial.begin(9600);
  ecranlcd.init();
  ledled.init();
  buzz.init();
  pot.init();
  bou.init();
}

//Cette fonction est un constructeur qui initialise les variables du programme et instancie à la volée les composants du projet.
monappli::monappli():ledled(PIN_LEDC, PIN_LEDD, N_LED), bou(PIN_BOU), pot(PIN_POT, VOLTAGE_REF, ANGLE_MAX), ecranlcd(), buzz(PIN_BUZ) {
  affiche=0;
  de = 0;
  }

//Fonction loop du programme qui sera répété indéfiniment
void monappli::loop() {
  // Note : la variable affiche est utilisée de telle manière à ce que l'écran lcd ne réaffiche pas indéfiniment quelque chose qu'il est déjà en train d'afficher.
  
  if (pot.getPosition() == 1) {                       //Cas Dé
    if (affiche != 1) {
      ecranlcd.afficher_option(1);
      affiche = 1 ; 
    }
      if (bou.getEtat()== true) { //Une pression du bouton lance le dé
      ledled.sequence(2, ecranlcd) ;
      de = random(1,7);
      ledled.afficherDe(de);
      ecranlcd.afficher_chiffre(de, 0, 255, 0);
    }
  } else if (pot.getPosition() == 2) {                //Cas SABLIER 
    if (affiche != 2) {
      ecranlcd.afficher_option(2);
      affiche = 2 ;
    }
    if (bou.getEtat()== true) { //Une pression du bouton lance le sablier
      ecranlcd.print("Lancement chrono");
      delay(400);
      ledled.chrono(60, ecranlcd);
      buzz.alarme(4, ledled);
    }
  }
}
