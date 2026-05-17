#ifndef MOTORFISICO_H
#define MOTORFISICO_H

class MotorFisico
{
public:

    static float retrocesoAmortiguado(float velocidad,
                                      float amortiguacion);

    static float movimientoSenoidal(float amplitud,
                                    float tiempo);

    static float movimientoParabolico(float x);
};

#endif // MOTORFISICO_H
