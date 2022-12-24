#include "avaliacao_basica_ecommerce.hpp"

#include "Catalogo.hpp"
#include <iostream>
#include <string>
#include "Carrinho.hpp"
using namespace std;
int main()
{
    Catalogo catalogo;
    char comando;
    string nome,titulo,autor,marca,modelo;
    int id,idade,ano,quantidade;
    float valor;
    Carrinho carrinho;

    while (cin>>comando)
    {

        switch (comando)
        {
            case 'q':
                cin>>nome>>idade>>valor;
                catalogo.adicionar_produto(nome,idade,valor);
                break;
            case 'l':
                cin>>titulo>>autor>>ano>>valor;
               catalogo.adicionar_produto(titulo,autor,ano,valor);
                break;
            case 'e':
                cin>>marca>>modelo>>valor;
                catalogo.adicionar_produto(marca,modelo,valor);
                break;
            case 'c':
                catalogo.imprimir();
                break;
            case 'p':
                cin>>id>>quantidade;
                if(catalogo.buscar_produto(id)!= nullptr)
                carrinho.adicionar_pedido(catalogo.buscar_produto(id),quantidade);
                break;
            case 'r':
                carrinho.imprimir_resumo();
                break;
            case 'b':
                avaliacao_basica();
                break;


            default:
                cout<<endl;
                break;
        }

    }


}
