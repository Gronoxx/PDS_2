#include <iostream>
#include <vector>
#ifndef E_COMMERCE_PDS2_CARRINHO_HPP
#define E_COMMERCE_PDS2_CARRINHO_HPP

#include "Pedido.hpp"
#include "Produto.hpp"
class Carrinho {
private:
    std::vector<Pedido*> _pedidos;
    int quantidade_de_pedidos=0;
public:
    void adicionar_pedido( Produto * produto, int quantidade);
    void imprimir_resumo();
    ~Carrinho();
};


#endif
