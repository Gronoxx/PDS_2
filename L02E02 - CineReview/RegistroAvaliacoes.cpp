#include "RegistroAvaliacoes.hpp"


void RegistroAvaliacoes::adicionar_usuario(std::string login, std::string nome){
    _usuarios.insert(pair<string ,Usuario*>(login,new Usuario(login,nome)));
}

void RegistroAvaliacoes::adicionar_filme(std::string nome, std::string genero, int duracao){
    filme_id++;
    _filmes.insert(pair<int ,Filme*>(filme_id,new Filme(filme_id,nome,genero,duracao)));
}

void RegistroAvaliacoes::adicionar_review(int id_filme, std::string login_usuario, std::string comentario, float nota){
    Review * review_atual;
    review_atual = new Review(_filmes.at(id_filme), comentario,nota);
    _usuarios.at(login_usuario)->associar_review(review_atual);
    _filmes.at(id_filme)->adicionar_review(comentario,nota);
}

void RegistroAvaliacoes::imprimir_estatisticas_usuarios(){
    std::map<std::string,Usuario*>::iterator it;
    for (it = _usuarios.begin(); it != _usuarios.end(); it++)
         it->second->imprimir_info();
}

void RegistroAvaliacoes::imprimir_registro_geral(){
    std::map<int,Filme*>::iterator it;
    for (it = _filmes.begin(); it != _filmes.end(); it++)
        it->second->imprimir_nota_consolidada();
}
void RegistroAvaliacoes::imprimir_reviews_usuario(std::string login) {
    _usuarios.at(login)->imprimir_reviews();
}
