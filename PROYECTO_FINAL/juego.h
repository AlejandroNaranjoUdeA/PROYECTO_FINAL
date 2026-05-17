#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>

#include "jugador.h"
#include "enemigo.h"

class Juego : public QGraphicsView
{
    Q_OBJECT

private:

    QGraphicsScene *scene;

    Jugador *jugador;
    Enemigo *enemigo;

    QTimer *timer;

public:

    Juego(QWidget *parent = nullptr);

public slots:

    void actualizarJuego();
};

#endif // JUEGO_H
