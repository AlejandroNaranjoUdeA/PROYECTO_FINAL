#ifndef JUGADOR_H
#define JUGADOR_H


#include "personaje.h"

#include <QKeyEvent>
#include <QPixmap>

class Jugador : public Personaje
{
private:

    QPixmap spriteSheet;

public:

    Jugador();

    void keyPressEvent(QKeyEvent *event);

    void actualizar();
};
#endif // JUGADOR_H
