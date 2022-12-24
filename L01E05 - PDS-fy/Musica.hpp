#ifndef MUSICA_HPP
#define MUSICA_HPP

#include <iostream>
#include <string>
#include <iostream>
using namespace std;


struct Musica{
    Musica * Musica_Anterior=nullptr;
    Musica * Proxima_Musica=nullptr;
    Musica();
    int _id;
    string _nome;
    string _artista;
    string _album;
    float _duracao;
    bool _favorita=false;
    Musica (int id, string nome, string artista, string album, float duracao);
    void imprimir_dados();
    int duracao_em_minutos=0;
    float duracao_em_minutosdec=0;
};

#endif 
