#include "ataque.h"

Ataque::Ataque(bool derecha, bool esAgua, bool esAire, bool esTierra, bool esDelJugador, unsigned int nivel)
{

    nivelActual = nivel;

    this->derecha = derecha;

    this->esDelJugador = esDelJugador;

    ataqueAgua = esAgua;
    ataqueAire = esAire;
    ataqueTierra = esTierra;

    tiempo = 0;

    amplitud = 10;

    frecuencia = 5;

    if(esDelJugador)
    {
        if(ataqueAgua)
        {
            danio = 3;
        }
        else if(ataqueAire)
        {
            danio = 4;
        }
        else if(ataqueTierra)
        {
            danio = 6;
        }
        else
        {
            danio = 5; // fuego
        }
    }
    else
    {
        if(nivel == 1)
        {
            danio = 50;
        }
        else
        {
            danio = 100;
        }
    }

    frameActual= 0;

    if(esDelJugador)
    {
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
        else if(ataqueAire)
        {
            spriteSheet =
                QPixmap(":/sprites/bolas_aire.png");

            setPixmap(
                spriteSheet.copy(
                    0,
                    0,
                    256,
                    181
                    )
                );
        }
        else if(ataqueTierra)
        {
            spriteSheet =
                QPixmap(":/sprites/bolas_tierra.png");

            setPixmap(
                spriteSheet.copy(
                    0,
                    0,
                    175,
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
    }
    else
    {
        spriteSheet =
            QPixmap(":/sprites/bolas_roca.png");

        setPixmap(
            spriteSheet.copy(
                0,
                0,
                234,
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

    if(ataqueAgua || ataqueAire)
    {
        setPixmap(
            spriteSheet.copy(
                frameActual * 256,
                0,
                256,
                181
                )
            );

        setX(x() + velocidadX);

        setY(
            yInicial +
            amplitud * sin(frecuencia * tiempo)
            );
    }
    else if(ataqueTierra)
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

bool Ataque::perteneceAlJugador()
{
    return esDelJugador;
}
