#include "enemigo.h"

Enemigo::Enemigo(Jugador *jugador)
{
    objetivo = jugador;

    velocidad= 2;

    mirandoDerecha = true;

    velocidadRetroceso = 0;

    lanzarRoca = false;

    tiempoRecarga = 120;

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
    tiempoRecarga--;

    if(tiempoRecarga <= 0)
    {
        lanzarRoca = true;

        tiempoRecarga = 120;
    }

    if(velocidadRetroceso != 0)
    {
        setX(
            x() + velocidadRetroceso
            );

        velocidadRetroceso *= 0.85;

        if(abs(velocidadRetroceso) < 0.2)
        {
            velocidadRetroceso = 0;
        }
    }

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
            mirandoDerecha = true;

            moverIzquierda();
        }
        else
        {
            mirandoDerecha = false;

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

    QPixmap frame;

    switch(estado)
    {
    case IDLE:

        frame=
            spriteSheet.copy(
                1152,
                0,
                384,
                1024
                )
            ;

        break;

    case CAMINANDO:

        frame=
            spriteSheet.copy(
                384,
                0,
                384,
                1024
                )
            ;

        break;

    case ATACANDO:

        frame=
            spriteSheet.copy(
                768,
                0,
                384,
                1024
                )
            ;

        break;


    case DANIO:

        frame=
            spriteSheet.copy(
                0,
                0,
                384,
                1024
                )
            ;

        break;
    }

    if(!mirandoDerecha)
    {
        frame =
            frame.transformed(
                QTransform().scale(-1,1)
                );
    }

    setPixmap(frame);
}

void Enemigo::aplicarRetroceso(double velocidad)
{
    velocidadRetroceso = velocidad;
}

bool Enemigo::quiereAtacar()
{
    if(lanzarRoca)
    {
        lanzarRoca = false;

        return true;
    }

    return false;
}
