#ifndef CAPTEUR_H
#define CAPTEUR_H

/*
 * Cette classe est la classe mère de tous les capteurs, son utilité est la fonction abstraite init() qui sera implémentée différemment par chacune de ses classes filles.
 */

class capteur {

  public:
  //Constructeur sans argument
  capteur() ;
  
  //Méthode abstraite
  virtual void init()=0;

};

#endif
