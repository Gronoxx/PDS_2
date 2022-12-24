#include "Playlist.hpp"
#include <cmath>
#include <iomanip>
int id=0;
Playlist::Playlist()
{

}
void Playlist::adicionar_musica(string nome, string artista, string album, float duracao)
{
    id++;
    countaux++;
    Musica * Criador_de_Musica = new Musica;
    if(Primeira_Musica ==nullptr)
    {
        Primeira_Musica = Criador_de_Musica;
        Ultima_Musica = Criador_de_Musica;
    }
    else{
        Criador_de_Musica->Musica_Anterior=Ultima_Musica;
        Ultima_Musica->Proxima_Musica=Criador_de_Musica;
        Ultima_Musica = Criador_de_Musica;
    }
    Ultima_Musica->_id=id;
    Ultima_Musica->_nome=nome;
    Ultima_Musica->_artista=artista;
    Ultima_Musica->_album=album;
    Ultima_Musica->_duracao=duracao;
}
Musica * Playlist::buscar_musica(string nome, string artista)
{
    Musica * Retorno= nullptr;
    Retorno=Primeira_Musica;
    for(int count= 1; count<=Ultima_Musica->_id;count++)
    {
        if(Retorno->_nome == nome && Retorno->_artista == artista)
        {
            return Retorno;
        }
        else
        {
            Retorno=Retorno->Proxima_Musica;
        }
    }
    return Retorno;
}

void Playlist::remover_musica(int id)
{
    countaux--;
    Musica * Encontrar_Musica= Primeira_Musica;
    for(int count= 1; count<=Ultima_Musica->_id;count++)
    {
        if(Encontrar_Musica->_id==id)
        {
            if(id==Primeira_Musica->_id)
            {
                Primeira_Musica=Primeira_Musica->Proxima_Musica;
                delete Encontrar_Musica;
                break;
            }
            else if(id==Ultima_Musica->_id)
            {
                Ultima_Musica=Ultima_Musica->Musica_Anterior;
                Ultima_Musica->Proxima_Musica=nullptr;
                delete Encontrar_Musica;
                break;
            }
            else
            {
                Encontrar_Musica->Musica_Anterior->Proxima_Musica=Encontrar_Musica->Proxima_Musica;
                Encontrar_Musica->Proxima_Musica->Musica_Anterior=Encontrar_Musica->Musica_Anterior;
                delete Encontrar_Musica;
                break;
            }
        }
        else
        {
            Encontrar_Musica=Encontrar_Musica->Proxima_Musica;
        }
    }
}
void Playlist::favoritar_musica(int id)
{
    Musica * Encontrar_Musica= Primeira_Musica;
    for(int count= 1; count<=Ultima_Musica->_id;count++)
    {
        
        if(Encontrar_Musica->_id==id)
        {
           if(Encontrar_Musica->_favorita==false)
           {
            Encontrar_Musica->_favorita=true;
            if(id==Primeira_Musica->_id)
            {

                break;
            }
            else if(id==Ultima_Musica->_id)
            {
                Encontrar_Musica->Musica_Anterior->Proxima_Musica=nullptr;
                Ultima_Musica=Encontrar_Musica->Musica_Anterior;
                Primeira_Musica->Musica_Anterior=Encontrar_Musica;
                Encontrar_Musica->Musica_Anterior=nullptr;
                Encontrar_Musica->Proxima_Musica=Primeira_Musica;
                Primeira_Musica=Encontrar_Musica;
                break;
            }
            else
            {
                Encontrar_Musica->Musica_Anterior->Proxima_Musica=Encontrar_Musica->Proxima_Musica;
                Encontrar_Musica->Proxima_Musica->Musica_Anterior=Encontrar_Musica->Musica_Anterior;
                Primeira_Musica->Musica_Anterior=Encontrar_Musica;
                Encontrar_Musica->Musica_Anterior=nullptr;
                Encontrar_Musica->Proxima_Musica=Primeira_Musica;
                Primeira_Musica=Encontrar_Musica;
                break;
            }
           }
        }
        else
        {
            Encontrar_Musica=Encontrar_Musica->Proxima_Musica;
        }
    
        
    }
}
void Playlist::desfavoritar_musica(int id)
{
    Musica * Encontrar_Musica= Primeira_Musica;
    for(int count= 1; count<=countaux;count++)
    {
        if (Encontrar_Musica->_favorita == true)
        {
        if(Encontrar_Musica->_id==id)
        {
                Encontrar_Musica->_favorita = false;
                if (id == Primeira_Musica->_id) {
                    Primeira_Musica->Proxima_Musica->Musica_Anterior = nullptr;
                    Primeira_Musica->Musica_Anterior = Ultima_Musica;
                    Primeira_Musica = Primeira_Musica->Proxima_Musica;
                    Encontrar_Musica->Proxima_Musica = nullptr;
                    Ultima_Musica->Proxima_Musica = Encontrar_Musica;
                    Ultima_Musica = Encontrar_Musica;
                    break;
                } else if (id == Ultima_Musica->_id) {
                    break;
                } else {
                    Encontrar_Musica->Musica_Anterior->Proxima_Musica = Encontrar_Musica->Proxima_Musica;
                    Encontrar_Musica->Proxima_Musica->Musica_Anterior = Encontrar_Musica->Musica_Anterior;
                    Ultima_Musica->Proxima_Musica = Encontrar_Musica;
                    Encontrar_Musica->Musica_Anterior = Ultima_Musica;
                    Encontrar_Musica->Proxima_Musica = nullptr;
                    Ultima_Musica = Encontrar_Musica;
                    break;
                }
            } else {
                Encontrar_Musica = Encontrar_Musica->Proxima_Musica;
            }
        }
    }
}

void Playlist::imprimir()
{
    int horas=0;
    float duracaototal=0;
    Musica * Encontrar_Musica= Primeira_Musica;
    for(int count= 1; count<=countaux;count++)
    {
        duracaototal+=Encontrar_Musica->_duracao;
        Encontrar_Musica->imprimir_dados();
        if(Encontrar_Musica->Proxima_Musica!=nullptr)
            Encontrar_Musica=Encontrar_Musica->Proxima_Musica;
        else
            break;
    }


    int duracaototal_em_minutos=duracaototal;
    float duracaototal_em_minutosdec=((round(((duracaototal-duracaototal_em_minutos)*100)))/100*60);
    if(duracaototal_em_minutos>=60)
    {
        horas= duracaototal_em_minutos/60;
        duracaototal_em_minutos= duracaototal_em_minutos - (horas*60);
    }
    if(horas<10)
    {
        if(duracaototal_em_minutos>=10) {
            if (duracaototal_em_minutosdec < 10)
                cout << "Tempo total: " << "0" << horas << ":" << duracaototal_em_minutos << ":0" << setprecision(2)<< duracaototal_em_minutosdec << "\n";
            else
                cout << "Tempo total: " << "0" << horas << ":" << duracaototal_em_minutos << ":" << setprecision(2)<< duracaototal_em_minutosdec << "\n";
        }
            else
        if (duracaototal_em_minutosdec < 10)
            cout << "Tempo total: " << "0" << horas << ":0" << duracaototal_em_minutos << ":0" << setprecision(2)<< duracaototal_em_minutosdec << "\n";
        else
            cout << "Tempo total: " << "0" << horas << ":0" << duracaototal_em_minutos << ":" << setprecision(2)<< duracaototal_em_minutosdec << "\n";
    }
    else {
        if (duracaototal_em_minutos >= 10)
            cout << "Tempo total: " << horas << ":" << duracaototal_em_minutos << ":" << setprecision(2)
                 << duracaototal_em_minutosdec << "\n";
        else
            cout << "Tempo total: " << horas << ":0" << duracaototal_em_minutos << ":0" << setprecision(2)
                 << duracaototal_em_minutosdec << "\n";
    }
}
