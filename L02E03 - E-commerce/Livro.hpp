#ifndef E_COMMERCE_PDS2_LIVRO_HPP
#define E_COMMERCE_PDS2_LIVRO_HPP
#include <iostream>
#include <string>
#include "Produto.hpp"
class Livro:public Produto {
private:
    std::string _titulo,_autor;
    int _ano;
public:
    Livro(int id, float valor, std::string titulo, std::string autor, int ano);
    void imprimir_info() override;
};


#endif
