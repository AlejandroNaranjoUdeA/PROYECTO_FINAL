#include "personaje.h"

#include <QDebug>

Personaje::Personaje()
{
    vida = 100;

    velocidad = 10;

    atacando = false;

    estado = IDLE;
}

void Personaje::actualizar()
{
    if(atacando)
    {
        QList<QGraphicsItem*> colisiones =
            collidingItems();

        for(int i = 0; i < colisiones.size(); i++)
        {
            Personaje* enemigo =
                dynamic_cast<Personaje*>(colisiones[i]);

            if(enemigo)
            {
                enemigo->recibirDanio(10);
            }
        }

        atacando = false;
    }
}

void Personaje::atacar()
{
    atacando = true;
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

    qDebug() << "Vida restante:" << vida;
}

int Personaje::getVida()
{
    return vida;
}
