#include "Ponto2D.hpp"


Ponto2D::Ponto2D()
{
    
}
Ponto2D::Ponto2D(double x=0,double y=0)
    {
        this->X=x;
        this->Y=y;
    }
double Ponto2D::calcular_distancia(Ponto2D *ponto)
    {
        double dx = this->X - ponto->X;
        double dy = this->Y - ponto->Y;
        return sqrt(dx*dx+dy*dy);
    }
