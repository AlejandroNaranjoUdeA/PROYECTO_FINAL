#include "jugador.h"

#include <QPixmap>
#include <QDebug>

Jugador::Jugador()
{
    // CARGAR SPRITE SHEET

    spriteSheet = QPixmap(":/sprites/sprites1.png");

    qDebug() << spriteSheet.width();
    qDebug() << spriteSheet.height();

    // 0 = Fuego
    // 1 = Agua

    personajeActual = 0;

    // SPRITE INICIAL

    setPixmap(
        spriteSheet.copy(
            0,
            0,
            384,
            512
            )
        );

    setScale(0.2);

    setTransformOriginPoint(
        boundingRect().center()
        );

    setFlag(QGraphicsItem::ItemIsFocusable);

    setFocus();

    tiempoAtaque = 0;

    mirandoDerecha = true;
}

void Jugador::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A)
    {
        moverIzquierda();

        estado = CAMINANDO;

        mirandoDerecha = false;
    }

    if(event->key() == Qt::Key_D)
    {
        moverDerecha();

        estado = CAMINANDO;

        mirandoDerecha = true;
    }

    if(event->key() == Qt::Key_J)
    {
        atacar();

        estado = ATACANDO;

        tiempoAtaque = 25;
    }

    if(event->key() == Qt::Key_W)
    {
        moverArriba();

        estado= CAMINANDO;
    }

    if(event->key() == Qt::Key_X)
    {
        personajeActual = 1 - personajeActual;

        if(personajeActual == 0)
        {
            setScale(0.20); // Fuego
            setY(350);
        }
        else
        {
            setScale(0.23); // Agua
            setY(357);
        }

        qDebug() << "Personaje:" << personajeActual;
    }
    if(event->key() == Qt::Key_P)
    {
        recibirDanio(10);
    }
}

void Jugador::actualizar()
{
    int fila = personajeActual * 512;

    if(tiempoAtaque > 0)
    {
        tiempoAtaque--;

        estado = ATACANDO;
    }
    else
    {
        estado = IDLE;
    }



    float escala;

    if(personajeActual == 0)
    {
        escala = 0.20;
    }
    else
    {
        escala = 0.23;
    }

    if(mirandoDerecha)
    {
        setScale(escala);
    }
    else
    {
        setScale(-escala);
    }



    switch(estado)
    {
    case IDLE:

        setPixmap(
            spriteSheet.copy(
                0,
                fila,
                384,
                512
                )
            );

        break;

    case CAMINANDO:

        setPixmap(
            spriteSheet.copy(
                384,
                fila,
                384,
                512
                )
            );

        break;

    case ATACANDO:

        setPixmap(
            spriteSheet.copy(
                768,
                fila,
                384,
                512
                )
            );

        break;

    case DANIO:

        setPixmap(
            spriteSheet.copy(
                1152,
                fila,
                384,
                512
                )
            );

        break;
    }
}
