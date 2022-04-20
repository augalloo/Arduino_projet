#include "bouton.h"
#include "potentiometre.h"
#include "chaineled.h"
#include "ecran.h"
#include "buzzer.h"

bouton bou;
potentiometre pot;
chaineled ledled(PIN_LEDC, PIN_LEDD, N_LED) ;
ecran ecranlcd; 
int de ;
buzzer buzz ;
int affiche = 0 ;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  ecranlcd.init();
  ledled.init();
  buzz.init();
  pot.init();
  bou.init();
  Serial.println("boucle");
}



void loop() {


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
        ledled.chrono(15, ecranlcd);
     
      buzz.alarme(1, ledled);
    }
  }
  

 
}
