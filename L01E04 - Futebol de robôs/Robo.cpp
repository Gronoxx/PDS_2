#include "Robo.hpp"
#include <iostream>

Robo::Robo(int id, Ponto2D ponto, bool bola)
    {
    this->id=id;
    this->ponto=ponto;
    this->com_bola=bola;
    }
void Robo::mover(double v, double th, double t)
    {
        // v= magnitude, th = radianos, t = tempo de aplicação de velocidade
        double hip = v*t;
        this->ponto.X=this->ponto.X+cos(th)*hip;
        this->ponto.Y=this->ponto.Y+sin(th)*hip;
        this->energia=this->energia-hip;
    }
double Robo::calcular_distancia(Robo*robo)
    {
        Ponto2D* pponto= &(robo->ponto);
        this->ponto.calcular_distancia(pponto);
    }
 Robo* Robo::determinar_robo_mais_proximo(Robo** naves, int n)
    {   
        float aux;
        int countaux=0;
        if((this->id)==0)
        {
        aux=this->calcular_distancia(naves[1]);
        countaux=1;
        }
        else
        {
        aux=this->calcular_distancia(naves[0]);
        countaux=0;    
        }
        for(int count=0;count<n;count++)
        {
            if(count!=this->id)
            {
            if(this->calcular_distancia(naves[count])<aux)
            {
                
                aux=this->calcular_distancia(naves[count]);
                countaux=count;
            }
            }
        }
        return naves[countaux];
    }
void Robo::passar_bola(Robo** time, int n)
    {
        if(this->com_bola==false)
        std::cout<<"Estou sem a bola!"<<std::endl;
        else
        {
            this->com_bola=false;
            this->determinar_robo_mais_proximo( time,n)->com_bola=true;
        }
    }
void Robo::imprimir_status()
    {
         std::cout<<this->id<<"\t"<<this->ponto.X<<"\t"<<this->ponto.Y<<"\t"<<this->com_bola<<"\t"<<this->energia<<std::endl;
    }
