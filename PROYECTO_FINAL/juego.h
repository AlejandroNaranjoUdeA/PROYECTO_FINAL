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
    QGraphicsRectItem *barraVidaEnemigo;
    QTimer *timer;

    unsigned int nivelActual;

public:

    Juego(unsigned int nivel,QWidget *parent = nullptr);


public slots:

    void actualizarJuego();

protected:

    void resizeEvent(
        QResizeEvent *event
        ) override;
};

#endif // JUEGO_H
