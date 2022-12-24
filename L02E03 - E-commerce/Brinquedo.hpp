#ifndef E_COMMERCE_PDS2_BRINQUEDO_HPP
#define E_COMMERCE_PDS2_BRINQUEDO_HPP
#include "Produto.hpp"
#include <string>
#include <iostream>

class Brinquedo : public Produto {
private:
    std::string _nome;
    int _idade_minima;
public:
    Brinquedo(int id, float valor, std::string nome, int idade_minima);
    void imprimir_info() override;
};


#endif
