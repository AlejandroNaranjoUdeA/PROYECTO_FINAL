#include "jugador.h"

#include <QPixmap>

Jugador::Jugador()
{
    setPixmap(QPixmap(":/sprites/jugador.png"));

    setFlag(QGraphicsItem::ItemIsFocusable);

    setFocus();
}

void Jugador::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A)
    {
        moverIzquierda();
    }

    if(event->key() == Qt::Key_D)
    {
        moverDerecha();
    }
}

void Jugador::actualizar()
{

}
