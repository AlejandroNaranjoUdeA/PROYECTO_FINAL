#ifndef ATAQUE_H
#define ATAQUE_H

#include <QPixmap>
#include <QGraphicsPixmapItem>

class Ataque : public QGraphicsPixmapItem
{
private:

    QPixmap spriteSheet;

    int danio;

    unsigned int frameActual;

public:

    Ataque();

    void actualizar();

    int getDanio();
};

#endif // ATAQUE_H
