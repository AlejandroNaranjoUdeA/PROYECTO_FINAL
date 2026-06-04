#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>

#include "ataque.h"
#include "jugador.h"
#include "enemigo.h"
#include <QList>

class Juego : public QGraphicsView
{
    Q_OBJECT

private:

    QGraphicsScene *scene;

    Jugador *jugador;
    Enemigo *enemigo;
    QList<Ataque*> ataques;
    QGraphicsRectItem *barraVida;
    QTimer *timer;

public:

    Juego(QWidget *parent = nullptr);

public slots:

    void actualizarJuego();
};

#endif // JUEGO_H
