#include "juego.h"
#include <QMessageBox>
#include "mainwindow.h"

Juego::Juego(unsigned int nivel,QWidget *parent)
    : QGraphicsView(parent)
{
    nivelActual = nivel;

    // ESCENA

    scene = new QGraphicsScene();

    QPixmap fondo;

    if(nivelActual == 1)
    {
        fondo.load(":/sprites/fondo1.png");
    }
    else
    {
        fondo.load(":/sprites/fondo2.png");
    }

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

    setRenderHint(
        QPainter::Antialiasing
        );

    setRenderHint(
        QPainter::SmoothPixmapTransform
        );

    setViewportUpdateMode(
        QGraphicsView::FullViewportUpdate
        );

    setFocusPolicy(Qt::StrongFocus);
    setFocus();

    resize(
        1200,
        720
        );

    // JUGADOR

    jugador = new Jugador(nivelActual);

    jugador->setPos(250,350);

    scene->addItem(jugador);

    jugador->setFocus();

    //ENEMIGO

    if(nivelActual == 1)
    {
        enemigo = new Enemigo(jugador, nivelActual);

        enemigo->setPos(700,295);

        scene->addItem(enemigo);
    }
    else
    {
        enemigo = new Enemigo(jugador, nivelActual);

        enemigo->setPos(850,295);

        scene->addItem(enemigo);

        enemigo->recibirDanio(-100);
    }

    // BARRA DE VIDA JUGADOR:

    barraVida = new QGraphicsRectItem();

    barraVida->setRect(
        20,   // x
        20,   // y
        250,  // ancho
        15    // alto
        );

    barraVida->setBrush(Qt::white);

    scene->addItem(barraVida);

    //BARRA DE VIDA ENEMIGO:

    barraVidaEnemigo = new QGraphicsRectItem();

    barraVidaEnemigo->setRect(
        730,  // x
        20,   // y
        250,  // ancho
        15    // alto
        );

    barraVidaEnemigo->setBrush(Qt::red);

    scene->addItem(barraVidaEnemigo);

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

    if(enemigo != nullptr)
    {
        enemigo->actualizar();
    }

    if(jugador->quiereDisparar())
    {
        bool esAgua = false;
        bool esAire = false;
        bool esTierra = false;

        if(nivelActual == 1)
        {
            if(jugador->getPersonajeActual() == 1)
            {
                esAgua = true;
            }
        }
        else
        {
            if(jugador->getPersonajeActual() == 0)
            {
                esAire = true;
            }
            else
            {
                esTierra = true;
            }
        }

        Ataque *bola =
            new Ataque(
                jugador->miraDerecha(),
                esAgua,
                esAire,
                esTierra,
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

        if(enemigo != nullptr)
        {
            if(enemigo->quiereAtacar())
            {
                bool haciaDerecha =
                    jugador->x() > enemigo->x();

                Ataque *roca =
                    new Ataque(
                        haciaDerecha,
                        false, // agua
                        false, // aire
                        false, // tierra
                        false  // enemigo
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
            if(enemigo != nullptr)
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

                    //ELIMINAR ENEMIGO:
                    if(enemigo->getVida() <= 0)
                    {
                        scene->removeItem(
                            barraVidaEnemigo
                            );

                        delete barraVidaEnemigo;

                        barraVidaEnemigo = nullptr;

                        timer->stop();

                        scene->removeItem(enemigo);

                        delete enemigo;

                        enemigo = nullptr;

                        QMessageBox::StandardButton opcion;

                        if(nivelActual == 1)
                        {
                            opcion = QMessageBox::question(
                                this,
                                "Victoria",
                                "¡Ganaste!\n\n¿Ir al nivel 2?",
                                QMessageBox::Yes | QMessageBox::No
                                );

                            if(opcion == QMessageBox::Yes)
                            {
                                Juego *nivel2 =
                                    new Juego(2);

                                nivel2->showMaximized();

                                close();
                            }
                            else
                            {
                                MainWindow *menu =
                                    new MainWindow();

                                menu->showMaximized();

                                close();
                            }
                        }
                        else
                        {
                            QMessageBox::information(
                                this,
                                "Victoria",
                                "¡Has completado el juego!"
                                );

                            MainWindow *menu =
                                new MainWindow();

                            menu->showMaximized();

                            close();
                        }

                        return;
                    }

                    scene->removeItem(
                        ataques[i]
                        );

                    delete ataques[i];

                    ataques.removeAt(i);

                    i--;
                }
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

    if(jugador->getVida() <= 0)
    {
        timer->stop();

        QMessageBox::StandardButton opcion;

        opcion = QMessageBox::question(
            this,
            "Derrota",
            "Has perdido.\n\n¿Deseas reintentar?",
            QMessageBox::Yes | QMessageBox::No
            );

        if(opcion == QMessageBox::Yes)
        {
            Juego *nuevoJuego =
                new Juego(nivelActual);

            nuevoJuego->showMaximized();

            close();
        }
        else
        {
            MainWindow *menu =
                new MainWindow();

            menu->showMaximized();

            close();
        }

        return;
    }

    if(enemigo != nullptr)
    {
        int vidaEnemigo =
            enemigo->getVida();

        barraVidaEnemigo->setRect(
            730,
            20,
            vidaEnemigo * 250/ 300,
            20
            );
    }
}

void Juego::resizeEvent(
    QResizeEvent *event
    )
{
    QGraphicsView::resizeEvent(event);

    fitInView(
        scene->sceneRect(),
        Qt::KeepAspectRatio
        );
}
