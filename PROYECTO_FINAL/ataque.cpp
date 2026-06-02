#include "ataque.h"

Ataque::Ataque()
{
    danio = 100;

    frameActual= 0;

    spriteSheet= QPixmap(":/sprites/bolas de fuego.png");

    setPixmap(
        spriteSheet.copy(
            0,
            0,
            175,
            181
            )
        );

    setScale(0.3);

}

int Ataque::getDanio()
{
    return danio;
}

void Ataque::actualizar()
{
    frameActual++;

    if(frameActual >= 6)
    {
        frameActual = 0;
    }

    setPixmap(
        spriteSheet.copy(
            frameActual * 175,
            0,
            175,
            181
            )
        );

    setX(x() + 1);
}

