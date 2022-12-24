#ifndef REGISTROAVALIACOES_HPP
#define REGISTROAVALIACOES_HPP
#include "Filme.hpp"
#include "Usuario.hpp"
#include "Review.hpp"
using namespace std;

class RegistroAvaliacoes {
public:
    int filme_id=0;
    map<string ,Usuario*> _usuarios;
    map<int ,Filme*> _filmes;
    void adicionar_usuario(string login, string nome);
    void adicionar_filme(string nome, string genero, int duracao);
    void adicionar_review(int id_filme, string login_usuario, string comentario, float nota);
    void imprimir_estatisticas_usuarios();
    void imprimir_registro_geral();
    void imprimir_reviews_usuario(string login);
};


#endif 
