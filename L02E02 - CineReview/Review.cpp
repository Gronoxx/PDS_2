#include "Review.hpp"
Review::Review(Filme *filme, std::string comentario, float nota)
{
    this->filme=filme;
    this->_comentario=comentario;
    this->_nota=nota;
}
