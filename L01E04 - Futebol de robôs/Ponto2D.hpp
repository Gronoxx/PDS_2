#ifndef PONTO2D_HPP
#define PONTO2D_HPP

#include<cmath>
struct Ponto2D{
    double X;
    double Y;
 Ponto2D();
    Ponto2D(double x,double y);
    double calcular_distancia(Ponto2D *ponto);
};
#endif
