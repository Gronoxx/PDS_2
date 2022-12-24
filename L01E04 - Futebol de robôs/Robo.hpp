#ifndef ROBO_HPP
#define ROBO_HPP

#include "Ponto2D.hpp"
#include <cmath>

struct Robo
{
    Robo();
double energia=100;
    bool com_bola;
    Ponto2D ponto;
    int id;
    bool bola;
    Robo(int id, Ponto2D ponto, bool bola);
    void mover(double v, double th, double t);
    double calcular_distancia(Robo*robo);
    Robo* determinar_robo_mais_proximo(Robo** naves, int n);
    void passar_bola(Robo** time, int n);
    void imprimir_status();
};
#endif
