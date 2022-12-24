#include <iostream>
#include "avaliacao_basica_playlist.hpp"

#include "Playlist.hpp"
#include "Musica.hpp"

int main()
{
    Playlist playlist;
    char comando;
    string nome, artista, album;
    float duracao;

    while (cin>>comando)
    {

        switch (comando)
        {
            case 'a':
                cin>>nome>>artista>>album>>duracao;
                playlist.adicionar_musica(nome,artista,album,duracao);
                break;
            case 's':
                cin>>nome>>artista;
                playlist.buscar_musica(nome,artista)->imprimir_dados();
                break;
            case 'r':
                cin>>nome>>artista;
                playlist.remover_musica(playlist.buscar_musica(nome,artista)->_id);
                break;
            case 'f':
                cin>>nome>>artista;
                playlist.favoritar_musica(playlist.buscar_musica(nome,artista)->_id);
                break;
            case 'd':
                cin>>nome>>artista;
                playlist.desfavoritar_musica(playlist.buscar_musica(nome,artista)->_id);
                break;
            case 'p':
                playlist.imprimir();
                break;
            case 'b':
                avaliacao_basica();
                break;


            default:
                break;
        }

    }


}
