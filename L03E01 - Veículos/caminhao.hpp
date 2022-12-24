#ifndef CAMINHAO_HPP
#define CAMINHAO_HPP

#include <string>
#include <iostream>
#include "veiculo.hpp"

class Caminhao: public Veiculo{
protected:
    int _carga_max;
public:
    Caminhao(string subtipo, int velo_max, int n_passageiros, int carga_max);
    Caminhao(int velo_max, int n_passageiros, int carga_max);
    virtual ~Caminhao();
    int estima_preco();
    void print_info() override;

};

#endif
