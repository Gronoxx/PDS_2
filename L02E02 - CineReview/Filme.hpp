#ifndef FILME_HPP
#define FILME_HPP

#include "Review.hpp"
#include <string>
#include <set>
using namespace std;
class Review;
class Filme {
public:
    int _id=0, _duracao,numeros_reviews=0;
    string _nome, _genero;
    set<Review*> _reviews;
    Filme(int id, string nome, string genero, int duracao);
    Review * adicionar_review(string comentario, float nota);
    void imprimir_nota_consolidada();
    double nota_media=0,nota_total=0;
};




#endif 
