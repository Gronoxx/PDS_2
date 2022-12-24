#include "Filme.hpp"
#include <iomanip>  
#include <iostream>
using namespace std;
Filme::Filme(int id, std::string nome, std::string genero, int duracao)
{
    this->_id=id;
    this->_nome=nome;
    this->_genero=genero;
    this->_duracao=duracao;
}

Review *Filme::adicionar_review(std::string comentario, float nota)
{
    nota_total=nota_total+nota;
    numeros_reviews++;
    Review *_atual = new Review(this,comentario,nota);
    _reviews.insert(_atual);
    return _atual;
}
void Filme::imprimir_nota_consolidada()
{
    if(numeros_reviews!=0)
    this->nota_media=this->nota_total/numeros_reviews;
    else
    this->nota_media=0.00;
    cout<<this->_nome<<"\t"<<"Reviews: "<<numeros_reviews<<"\t"<<"Nota Media: "<<std::fixed<< std::setprecision(1) <<nota_media<<endl;
}
