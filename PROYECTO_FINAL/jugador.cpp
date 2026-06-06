#include "jugador.h"

#include <QPixmap>
#include <QDebug>

Jugador::Jugador(unsigned int nivel)
{
    nivelActual = nivel;

    // CARGAR SPRITE SHEET

    if(nivelActual == 1)
    {
        spriteSheet =
            QPixmap(":/sprites/sprites1.png");
    }
    else
    {
        spriteSheet =
            QPixmap(":/sprites/sprites2.png");
    }

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

    /*setTransformOriginPoint(
        boundingRect().center()
        );*/

    setFlag(QGraphicsItem::ItemIsFocusable);

    setFocus();

    tiempoAtaque = 0;

    mirandoDerecha = true;

    lanzarBola = false;

    //FISICA:

    saltando = false;

    velocidadY = 0;

    gravedad = 0.6;

    sueloY = 350;
}

void Jugador::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "TECLA";

    if(event->key() == Qt::Key_A)
    {
        //moverIzquierda();

        if(x() > 100)
        {
            setX(x() - 10);
        }

        estado = CAMINANDO;

        mirandoDerecha = false;
    }

    if(event->key() == Qt::Key_D)
    {
        //moverDerecha();

        double ancho =
            boundingRect().width() * scale();

        if(x() + ancho < 900)
        {
            setX(x() + 10);
        }

        estado = CAMINANDO;

        mirandoDerecha = true;
    }

    if(event->key() == Qt::Key_J)
    {
        atacar();

        estado = ATACANDO;

        tiempoAtaque = 25;

        lanzarBola = true;
    }

    if(event->key() == Qt::Key_W)
    {
        if(!saltando)
        {
            saltando = true;

            velocidadY = -12;
        }
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
    if(event->key() == Qt::Key_Space)
    {
        if(!saltando)
        {
            saltando = true;

            velocidadY = -12;
        }
    }
}

void Jugador::actualizar()
{
    //FISICA DEL SALTO:

    if(saltando)
    {
        setY(
            y() + velocidadY
            );

        velocidadY += gravedad;

        if(y() >= sueloY)
        {
            setY(sueloY);

            saltando = false;

            velocidadY = 0;
        }
    }

    //ATAQUE

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

    QPixmap frame;

    switch(estado)
    {
    case IDLE:

        frame=
            spriteSheet.copy(
                0,
                fila,
                384,
                512
                )
            ;

        break;

    case CAMINANDO:

        frame=
            spriteSheet.copy(
                384,
                fila,
                384,
                512
                )
            ;

        break;

    case ATACANDO:

        frame=
            spriteSheet.copy(
                768,
                fila,
                384,
                512
                )
            ;

        break;

    case DANIO:

        frame=
            spriteSheet.copy(
                1152,
                fila,
                384,
                512
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

    estado = IDLE;
}


bool Jugador::quiereDisparar()
{
    if(lanzarBola)
    {
        lanzarBola = false;
        return true;
    }

    return false;
}

bool Jugador::miraDerecha()
{
    return mirandoDerecha;
}

int Jugador::getPersonajeActual()
{
    return personajeActual;
}
