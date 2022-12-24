#ifndef E_COMMERCE_PDS2_CATALOGO_HPP
#define E_COMMERCE_PDS2_CATALOGO_HPP

#include "Brinquedo.hpp"
#include "Livro.hpp"
#include "Eletronico.hpp"
#include "Produto.hpp"
#include <iostream>
#include <vector>
class Catalogo {
private:
    std::vector<Produto*> _produtos;
    int _id=0;
public:
    void adicionar_produto(std::string nome, int idade_minima, float valor);
    void adicionar_produto(std::string titulo, std::string autor, int ano, float valor);
    void adicionar_produto(std::string marca, std::string modelo, float valor);
    Produto* buscar_produto(int id);
    void imprimir();
    ~Catalogo();
};


#endif
