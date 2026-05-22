#include "jugador.h"

#include <QPixmap>

Jugador::Jugador()
{
    setPixmap(QPixmap("sprites/jugador.png"));

    // IDLE INICIAL

    setPixmap(spriteSheet.copy(0,0,64,64));

    setFlag(QGraphicsItem::ItemIsFocusable);

    setFocus();
}

void Jugador::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A)
    {
        moverIzquierda();

        estado = CAMINANDO;
    }

    if(event->key() == Qt::Key_D)
    {
        moverDerecha();

        estado = CAMINANDO;
    }

    if(event->key() == Qt::Key_J)
    {
        atacar();

        estado = ATACANDO;
    }
}

void Jugador::actualizar()
{
    switch(estado)
    {
    case IDLE:

        setPixmap(spriteSheet.copy(0,0,64,64));

        break;

    case CAMINANDO:

        setPixmap(spriteSheet.copy(64,0,64,64));

        break;

    case ATACANDO:

        setPixmap(spriteSheet.copy(128,0,64,64));

        break;

    case DANIO:

        setPixmap(spriteSheet.copy(192,0,64,64));

        break;
    }

    estado = IDLE;
}
