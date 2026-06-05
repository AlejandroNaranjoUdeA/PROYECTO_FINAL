#ifndef ATAQUE_H
#define ATAQUE_H

#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <cmath>

class Ataque : public QGraphicsPixmapItem
{
private:

    QPixmap spriteSheet;

    int danio;

    unsigned int frameActual;

    int velocidadX;

    bool ataqueAgua;


    //fisica:

    double tiempo;
    double amplitud;
    double frecuencia;
    double yInicial;


    bool derecha;

    bool esDelJugador;

public:

    Ataque(bool derecha, bool esAgua, bool esDelJugador);

    void actualizar();

    int getDanio();

    void setYInicial(double y);

    bool vaDerecha();

    bool perteneceAlJugador();
};

#endif // ATAQUE_H
