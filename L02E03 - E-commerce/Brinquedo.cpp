#include <iostream>
#include "Brinquedo.hpp"
Brinquedo::Brinquedo(int id, float valor, std::string nome, int idade_minima): Produto(id, valor){
    this->_nome=nome;
    this->_idade_minima=idade_minima;
}

void Brinquedo::imprimir_info() {
    std::cout<<this->get_id()<<"\t"<<"Brinquedo"<<"\t"<<this->_nome<<"\t"<<this->_idade_minima<<"\t"<<"R$"<<std::fixed<<std::setprecision(2)<<this->get_valor_unitario()<<std::endl;
}
