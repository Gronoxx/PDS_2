#include "Livro.hpp"

Livro::Livro(int id, float valor, std::string titulo, std::string autor, int ano): Produto(id,valor) {
    this->_ano=ano;
    this->_autor=autor;
    this->_titulo=titulo;
}

void Livro::imprimir_info() {
    std::cout<<this->get_id()<<"\t"<<"Livro"<<"\t"<<this->_titulo<<"\t"<<this->_autor<<"\t"<<this->_ano<<"\t"<<"R$"<<std::fixed<<std::setprecision(2)<<this->get_valor_unitario()<<std::endl;
}
