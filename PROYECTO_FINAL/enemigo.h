#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "personaje.h"
#include "jugador.h"
#include <cstdlib>

#include <QPixmap>

class Enemigo : public Personaje
{
private:

    QPixmap spriteSheet;

    Jugador* objetivo;

    unsigned int contadorAtaque;

    bool mirandoDerecha;

    double velocidadRetroceso;

    bool lanzarRoca;
    int tiempoRecarga;

    unsigned int nivelActual;

    int tiempoTeleport;

public:

    Enemigo(Jugador* jugador, unsigned int nivel);

    void actualizar() override;

    void aplicarRetroceso(double velocidad);

    bool quiereAtacar();
};

#endif // ENEMIGO_H
