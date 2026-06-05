#include "juego.h"

Juego::Juego(unsigned int nivel,QWidget *parent)
    : QGraphicsView(parent)
{
    nivelActual = nivel;

    // ESCENA

    scene = new QGraphicsScene();

    QPixmap fondo(":/sprites/fondo1.png");

    scene->setBackgroundBrush(
        QBrush(
            fondo.scaled(
                1000,
                600,
                Qt::IgnoreAspectRatio,
                Qt::SmoothTransformation
                )
            )
        );

    scene->setSceneRect(0,0,1000,600);

    setScene(scene);

    setFocusPolicy(Qt::StrongFocus);
    setFocus();

    setFixedSize(1000,600);

    // JUGADOR

    jugador = new Jugador();

    jugador->setPos(250,350);

    scene->addItem(jugador);

    jugador->setFocus();

    //ENEMIGO

    if(nivelActual == 1)
    {
        enemigo = new Enemigo(jugador);

        enemigo->setPos(700,295);

        scene->addItem(enemigo);
    }
    else
    {
        enemigo = new Enemigo(jugador);

        enemigo->setPos(850,295);

        scene->addItem(enemigo);

        enemigo->recibirDanio(-100);
    }

    // BARRA DE VIDA:

    barraVida = new QGraphicsRectItem();

    barraVida->setRect(
        20,   // x
        20,   // y
        250,  // ancho
        15    // alto
        );

    barraVida->setBrush(Qt::white);

    scene->addItem(barraVida);

    scene->setFocusItem(jugador);

    jugador->setFocus();


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

    if(jugador->quiereDisparar())
    {
        bool esAgua =
            (jugador->getPersonajeActual() == 1);

        Ataque *bola =
            new Ataque(
                jugador->miraDerecha(),
                esAgua,
                true
                );



        if(jugador->miraDerecha())
        {
            bola->setPos(
                jugador->x() + 60,
                jugador->y() + 40
                );
        }
        else
        {
            bola->setPos(
                jugador->x() - 30,
                jugador->y() + 40
                );
        }

        double xSpawn = jugador->x() + 60;
        double ySpawn = jugador->y() + 40;

        if(enemigo->quiereAtacar())
        {
            bool haciaDerecha =
                jugador->x() > enemigo->x();

            Ataque *roca =
                new Ataque(
                    haciaDerecha,
                    false,
                    false
                    );

            if(haciaDerecha)
            {
                roca->setPos(
                    enemigo->x() + 60,
                    enemigo->y() + 80
                    );
            }
            else
            {
                roca->setPos(
                    enemigo->x() - 60,
                    enemigo->y() + 80
                    );
            }

            scene->addItem(roca);

            ataques.append(roca);
        }

        bola->setPos(
            xSpawn,
            ySpawn
            );

        bola->setYInicial(ySpawn);

        scene->addItem(bola);

        ataques.append(bola);
    }

    for(int i = 0; i < ataques.size(); i++)
    {
        ataques[i]->actualizar();

        if(ataques[i]->perteneceAlJugador())
        {
            if(ataques[i]->collidesWithItem(enemigo))
            {
                enemigo->recibirDanio(
                    ataques[i]->getDanio()
                    );

                if(ataques[i]->vaDerecha())
                {
                    enemigo->aplicarRetroceso(10);
                }
                else
                {
                    enemigo->aplicarRetroceso(-10);
                }

                scene->removeItem(
                    ataques[i]
                    );

                delete ataques[i];

                ataques.removeAt(i);

                i--;
            }
        }
        else
        {
            if(ataques[i]->collidesWithItem(jugador))
            {
                jugador->recibirDanio(
                    ataques[i]->getDanio()
                    );

                scene->removeItem(
                    ataques[i]
                    );

                delete ataques[i];

                ataques.removeAt(i);

                i--;
            }
        }
    }

    int vida = jugador->getVida();

    barraVida->setRect(
        20,
        20,
        vida * 3,
        20
        );
}

