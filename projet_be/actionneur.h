#ifndef ACTIONNEUR_H
#define ACTIONNEUR_H

/*
 * Cette classe est la classe mère de tous les actionneurs, son utilité est la fonction abstraite init() qui sera implémentée différemment par chacune de ses classes filles.
 */

class actionneur {
  
  public:
  //Constructeur sans argument
  actionneur() ;

  //Méthode abstraite
  virtual void init()=0;

};

#endif
