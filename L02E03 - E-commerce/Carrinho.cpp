#include "Carrinho.hpp"
#include <vector>
#include <iostream>
#include <iomanip>

void Carrinho::adicionar_pedido(Produto *produto, int quantidade) {
    _pedidos.push_back(new Pedido(produto,quantidade));
    quantidade_de_pedidos++;
    produto->set_quantidade_produto(produto->get_quantidade_produto()+quantidade);
}
void Carrinho::imprimir_resumo() {
    float total=0;
    for(int count=0;count<quantidade_de_pedidos;count++) {
        _pedidos.at(count)->get_produto()->imprimir_info();
            std::cout << "Qtde: " << _pedidos.at(count)->get_produto()->get_quantidade_produto()
                      << " Total produto: R$ " << std::fixed << std::setprecision(2)
                      << _pedidos.at(count)->get_produto()->get_valor_unitario() *
                         _pedidos.at(count)->get_produto()->get_quantidade_produto() << std::endl;
           total+= _pedidos.at(count)->get_produto()->get_valor_unitario() *_pedidos.at(count)->get_produto()->get_quantidade_produto();
    }
    std::cout<<"Total carrinho: R$ "<< std::fixed << std::setprecision(2)
    <<total<<std::endl;
}
Carrinho::~Carrinho() {
        for(unsigned int i = 0; i != _pedidos.size(); i++) {
            delete _pedidos.at(i);
        }
}
