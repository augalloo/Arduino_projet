#ifndef LEDS_H
#define LEDS_H

#include <ChainableLED.h>
#include "ecran.h"

/*
 * La classe chaineled est une classe fille de la classe ChainableLED. Elle utilise une fonction d'initialisation (init()) provenant de cette classe mère et n'a donc
 * pas besoin d'hériter de la classe actionneur, bien qu'elle en soit un.
 * Elle possède 3 attributs (clk, data, num_led).
 */

class chaineled : public ChainableLED {
  
  private: //Attributs
  bool *etat;
  int nled ;
  
  public:
  //Constructeur (clk : Clock Pin, data : Data Pin, num_led : nombre de LEDs de la chaine)
  chaineled(int clk, int data, int num_led);

  //Méthodes
  void eteint();
  void allume(int r, int g, int b);
  void sequence(int repet, ecran ecran);
  bool getEtat(int indice);
  void afficherDe(int resultat) ;
  void chrono(float secondes, ecran ecran);
};


#endif
