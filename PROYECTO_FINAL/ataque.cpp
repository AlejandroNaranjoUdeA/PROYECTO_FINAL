#include "ataque.h"

Ataque::Ataque(bool derecha, bool esAgua)
{
    this->derecha = derecha;

    ataqueAgua = esAgua;

    tiempo = 0;

    amplitud = 10;

    frecuencia = 5;

    danio = 100;

    frameActual= 0;

    if(ataqueAgua)
    {
        spriteSheet =
            QPixmap(":/sprites/bolas_agua.png");

        setPixmap(
            spriteSheet.copy(
                0,
                0,
                256,
                181
                )
            );
    }
    else
    {
        spriteSheet =
            QPixmap(":/sprites/bolas_fuego.png");

        setPixmap(
            spriteSheet.copy(
                0,
                0,
                175,
                181
                )
            );
    }

    setScale(0.2);

    if(derecha)
    {
        velocidadX = 8;
    }
    else
    {
        velocidadX = -8;
    }

}

int Ataque::getDanio()
{
    return danio;
}

void Ataque::actualizar()
{
    tiempo += 1;

    frameActual++;

    if(frameActual >= 6)
    {
        frameActual = 0;
    }

    if(ataqueAgua)
    {
        setPixmap(
            spriteSheet.copy(
                frameActual * 256,
                0,
                256,
                1024
                )
            );

        setX(x() + velocidadX);

        setY(
            yInicial +
            amplitud * sin(frecuencia * tiempo)
            );
    }
    else
    {
        setPixmap(
            spriteSheet.copy(
                frameActual * 175,
                0,
                175,
                181
                )
            );
    }

    setX(x() + velocidadX);
}

void Ataque::setYInicial(double y)
{
    yInicial = y;
}

bool Ataque::vaDerecha()
{
    return derecha;
}
