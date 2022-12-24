#ifndef CAMINHAOAUTONOMO_HPP
#define CAMINHAOAUTONOMO_HPP

#include <string>
#include <iostream>
#include "caminhao.hpp"

class CaminhaoAutonomo: public Caminhao{
protected:
    string _fabricante;
public:
    CaminhaoAutonomo(int velo_max, int n_passageiros, int carga_max, string fabricante);
    virtual ~CaminhaoAutonomo();
    int estima_preco() override;
    void print_info() override;


};





#endif
