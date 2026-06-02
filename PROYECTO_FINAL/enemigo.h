#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "personaje.h"
#include "jugador.h"

#include <QPixmap>

class Enemigo : public Personaje
{
private:

    QPixmap spriteSheet;

    Jugador* objetivo;

    unsigned int contadorAtaque;

public:

    Enemigo(Jugador* jugador);

    void actualizar() override;
};

#endif // ENEMIGO_H
