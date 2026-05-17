#include "juego.h"

Juego::Juego(QWidget *parent)
    : QGraphicsView(parent)
{
    // ESCENA

    scene = new QGraphicsScene();

    scene->setSceneRect(0,0,1000,600);

    setScene(scene);

    setFixedSize(1000,600);

    // JUGADOR

    jugador = new Jugador();

    jugador->setPos(200,400);

    scene->addItem(jugador);

    // ENEMIGO

    enemigo = new Enemigo();

    enemigo->setPos(700,400);

    scene->addItem(enemigo);

    // TIMER

    timer = new QTimer();

    connect(timer,SIGNAL(timeout()),
            this,SLOT(actualizarJuego()));

    timer->start(16);
}

void Juego::actualizarJuego()
{
    jugador->actualizar();
    enemigo->actualizar();
}
