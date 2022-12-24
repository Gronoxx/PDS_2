#ifndef E_COMMERCE_PDS2_PEDIDO_HPP
#define E_COMMERCE_PDS2_PEDIDO_HPP

#include "Pedido.hpp"
#include "Produto.hpp"
class Pedido {
private:
    Produto * _produto=nullptr;
    int _quantidade=0;
public:
    Pedido(Produto* produto, int quantidade);
    double get_valor_total();
    Produto* get_produto();
};


#endif
