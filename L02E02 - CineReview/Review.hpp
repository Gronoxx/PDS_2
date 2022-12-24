#ifndef REVIEW_HPP
#define REVIEW_HPP

#include <string>

class Filme;
class Review
{
public:
    Filme * filme;
    std::string _comentario;
    float _nota;
    Review(Filme*, std::string comentario, float nota);
};


#endif 
