#ifndef JUGADOR_H
#define JUGADOR_H

#include "personaje.h"
#include "ataque.h"
#include <QKeyEvent>
#include <QPixmap>

class Jugador : public Personaje
{
private:

    QPixmap spriteSheet;

    int personajeActual;

    int tiempoAtaque;

    bool mirandoDerecha;

    bool lanzarBola;

    //FISICA PARABOLICO:

    bool saltando;

    double velocidadY;

    double gravedad;

    double sueloY;

public:

    Jugador();

    void keyPressEvent(QKeyEvent *event);

    void actualizar();

    bool quiereDisparar();

    bool miraDerecha();

    int getPersonajeActual();
};

#endif // JUGADOR_H
