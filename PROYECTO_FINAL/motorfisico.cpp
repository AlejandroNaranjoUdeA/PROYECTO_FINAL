#include "motorfisico.h"

#include <cmath>

float MotorFisico::retrocesoAmortiguado(float velocidad,
                                        float amortiguacion)
{
    return velocidad * amortiguacion;
}

float MotorFisico::movimientoSenoidal(float amplitud,
                                      float tiempo)
{
    return amplitud * sin(tiempo);
}

float MotorFisico::movimientoParabolico(float x)
{
    return -(0.01f * x * x);
}
