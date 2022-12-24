#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP

#include "Musica.hpp"
using namespace std;
struct  Playlist
{
    Playlist();
    Musica * Primeira_Musica=nullptr;
    Musica * Musica_Atual;
    Musica * Ultima_Musica=nullptr;
    void adicionar_musica(string nome, string artista, string album, float duracao);
    Musica* buscar_musica(string nome, string artista);
    void remover_musica(int id);
    void favoritar_musica(int id);
    void desfavoritar_musica(int id);
    void imprimir();
    int countaux=0;
};

#endif 
