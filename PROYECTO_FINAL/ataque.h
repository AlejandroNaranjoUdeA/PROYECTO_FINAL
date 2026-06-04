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

public:

    Ataque(bool derecha, bool esAgua);

    void actualizar();

    int getDanio();

    void setYInicial(double y);
};

#endif // ATAQUE_H
