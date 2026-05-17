#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Personaje : public QObject,
                  public QGraphicsPixmapItem
{
    Q_OBJECT

protected:

    int vida;

    float velocidad;

public:

    Personaje();

    virtual void actualizar();

    void moverIzquierda();

    void moverDerecha();

    void recibirDanio(int danio);

    int getVida();
};

#endif // PERSONAJE_H
