#ifndef E_COMMERCE_PDS2_ELETRONICO_HPP
#define E_COMMERCE_PDS2_ELETRONICO_HPP
#include <iostream>
#include <string>
#include "Produto.hpp"

class Eletronico: public Produto {
private:
    std::string _marca, _modelo;
public:
    Eletronico(int id, float valor, std::string marca, std::string modelo);
    void imprimir_info() override;
};


#endif 
