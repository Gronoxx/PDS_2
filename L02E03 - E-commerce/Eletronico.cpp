#include "Eletronico.hpp"
Eletronico::Eletronico(int id, float valor, std::string marca, std::string modelo) : Produto(id,valor){
    this->_marca=marca;
    this->_modelo=modelo;
}

void Eletronico::imprimir_info() {
    std::cout<<this->get_id()<<"\t"<<"Eletronico"<<"\t"<<this->_marca<<"\t"<<this->_modelo<<"\t"<<"R$"<<std::fixed<<std::setprecision(2)<<this->get_valor_unitario()<<std::endl;
}
