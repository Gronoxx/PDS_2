#include "Pedido.hpp"
#include "Produto.hpp"
Pedido::Pedido(Produto * produto, int quantidade) {
    this->_produto=produto;
    this->_quantidade=quantidade;
}

Produto* Pedido::get_produto() {
    return this->_produto;
}
double Pedido::get_valor_total()  {
    return (this->_produto->get_valor_unitario())*_quantidade;
}
