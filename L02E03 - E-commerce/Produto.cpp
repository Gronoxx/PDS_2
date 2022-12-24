#include "Produto.hpp"
Produto::Produto(int id, float valor_unitario) {
    this->_id=id;
    this->_valor_unitario=valor_unitario;
}
void Produto::set_valor_unitario(float valor) {
    this->_valor_unitario=valor;
}
float Produto::get_valor_unitario(){
    return this->_valor_unitario;
};
void Produto::set_id(int id) {
    this->_id=id;
}
int Produto::get_id(){
    return this->_id;
};

int Produto::get_quantidade_produto() {
    return this->quantidade_produto;
}

void Produto::set_quantidade_produto(int qntd) {
    this->quantidade_produto=qntd;
}
