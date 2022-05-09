#include "monappli.h" 

void monappli::init() {
  Serial.begin(9600);
  ecranlcd.init();
  ledled.init();
  buzz.init();
  pot.init();
  bou.init();
}

monappli::monappli():ledled(PIN_LEDC, PIN_LEDD, N_LED), bou(PIN_BOU), pot(), ecranlcd(), buzz(PIN_BUZ) {
  affiche=0;
  de = 0;
  }

void monappli::loop() {
  if (pot.getPosition() == 1) {
    if (affiche != 1) {
      ecranlcd.afficher_option(1);
      affiche = 1 ; 
    }
      if (bou.getEtat()== true) {
      ledled.sequence(2, ecranlcd) ;
      de = random(1,7);
      ledled.afficherDe(de);
      ecranlcd.afficher_chiffre(de, 0, 255, 0);
    }
  } else if (pot.getPosition() == 2) {
    if (affiche != 2) {
      ecranlcd.afficher_option(2);
      affiche = 2 ;
    }
    if (bou.getEtat()== true) {
      ecranlcd.print("Lancement chrono");
      delay(400);
      ledled.chrono(60, ecranlcd);
      buzz.alarme(4, ledled);
    }
  }
}
