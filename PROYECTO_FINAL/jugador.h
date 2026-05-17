#ifndef JUGADOR_H
#define JUGADOR_H


#include "personaje.h"

#include <QKeyEvent>

class Jugador : public Personaje
{
public:

    Jugador();

    void keyPressEvent(QKeyEvent *event);

    void actualizar();
};

#endif // JUGADOR_H
