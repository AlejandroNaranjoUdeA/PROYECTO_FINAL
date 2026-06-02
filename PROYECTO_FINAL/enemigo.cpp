#include "enemigo.h"

Enemigo::Enemigo(Jugador *jugador)
{
    objetivo = jugador;

    velocidad= 2;

    spriteSheet = QPixmap(":/sprites/enemigo.png");

    // IDLE

    setPixmap(
        spriteSheet.copy(
            0,
            0,
            384,
            1024
            )
        );

    setScale(0.2);
}

void Enemigo::actualizar()
{
    if(!objetivo)
    {
        return;
    }

    contadorAtaque++;

    float distancia =
        abs(objetivo->x() - x());

    // SEGUIR AL JUGADOR

    if(distancia > 40)
    {
        estado = CAMINANDO;

        if(objetivo->x() < x())
        {
            moverIzquierda();
        }
        else
        {
            moverDerecha();
        }
    }

    // ATACAR

    else
    {
        estado = ATACANDO;

        if(contadorAtaque >= 60)
        {
            objetivo->recibirDanio(10);

            contadorAtaque = 0;
        }
    }

    // CAMBIO DE SPRITES

    switch(estado)
    {
    case IDLE:

        setPixmap(
            spriteSheet.copy(
                1152,
                0,
                384,
                1024
                )
            );

        break;

    case CAMINANDO:

        setPixmap(
            spriteSheet.copy(
                384,
                0,
                384,
                1024
                )
            );

        break;

    case ATACANDO:

        setPixmap(
            spriteSheet.copy(
                768,
                0,
                384,
                1024
                )
            );

        break;


    case DANIO:

        setPixmap(
            spriteSheet.copy(
                0,
                0,
                384,
                1024
                )
            );

        break;
    }
}
