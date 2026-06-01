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
            172,
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

    if(frameActual >= 8)
    {
        frameActual = 0;
    }

    setPixmap(
        spriteSheet.copy(
            frameActual * 172,
            0,
            172,
            181
            )
        );

    setX(x() + 15);
}

