#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>
#include "Review.hpp"
#include "Filme.hpp"
#include <map>
#include <iostream>
using namespace std;
class Usuario{
public:
   string _login="", _nome="";
    int review_index=0;
    map<int,Review*> _reviews;
    Usuario(string login, string nome);
    void associar_review(Review* review);
    void imprimir_info();
    void imprimir_reviews();



};


#endif
