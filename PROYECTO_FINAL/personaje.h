#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QList>
#include <QGraphicsItem>

enum Estado
{
    IDLE,
    CAMINANDO,
    ATACANDO,
    DANIO
};

class Personaje : public QObject,
                  public QGraphicsPixmapItem
{
    Q_OBJECT

protected:

    int vida;

    float velocidad;

    bool atacando;

    Estado estado;

public:

    Personaje();

    virtual void actualizar();

    virtual void atacar();

    void moverIzquierda();

    void moverDerecha();

    void recibirDanio(int danio);

    int getVida();
};

#endif // PERSONAJE_H
