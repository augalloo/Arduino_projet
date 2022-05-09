#include "monappli.h"

/*
 * Ce .ino fait office de main et c'est ici que s'execute le programme principal via la classe application monappli.
 * Ici, le setup ne se compose que de l'initialisation de l'appli et le loop contient uniquement le loop de l'application.
 */


// Instanciation de l'application
monappli app ;


void setup() {
  app.init();
}

void loop() {
  app.loop();
}
