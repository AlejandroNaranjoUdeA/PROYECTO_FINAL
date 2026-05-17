#include "personaje.h"

Personaje::Personaje()
{
    vida = 100;

    velocidad = 10;
}

void Personaje::actualizar()
{

}

void Personaje::moverIzquierda()
{
    setX(x() - velocidad);
}

void Personaje::moverDerecha()
{
    setX(x() + velocidad);
}

void Personaje::recibirDanio(int danio)
{
    vida -= danio;

    if(vida < 0)
    {
        vida = 0;
    }
}

int Personaje::getVida()
{
    return vida;
}
