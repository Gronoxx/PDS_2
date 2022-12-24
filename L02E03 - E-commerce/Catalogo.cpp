#include "Catalogo.hpp"

void Catalogo::adicionar_produto(std::string nome, int idade_minima, float valor) {
    this->_id++;
    _produtos.push_back(new Brinquedo(this->_id,valor,nome,idade_minima));
}

void Catalogo::adicionar_produto(std::string marca, std::string modelo, float valor) {
    this->_id++;
    _produtos.push_back(new Eletronico(this->_id,valor,marca,modelo));
}

void Catalogo::adicionar_produto(std::string titulo, std::string autor, int ano, float valor) {
    this->_id++;
    _produtos.push_back(new Livro(this->_id,valor,titulo,autor,ano));
}

Produto *Catalogo::buscar_produto(int id) {
    if(this->_id>=id && id>0) {
        return (_produtos.at(id - 1));
    }else
    {
    std::cout<<"Produto não encontrado!"<<std::endl;
    return nullptr;
    }
}

void Catalogo::imprimir() {
    for(unsigned int i = 0; i != _produtos.size(); i++) {
        _produtos.at(i)->imprimir_info();
    }
}
Catalogo::~Catalogo() {
    for(unsigned int i = 0; i != _produtos.size(); i++) {
       delete _produtos.at(i);
    }
}
