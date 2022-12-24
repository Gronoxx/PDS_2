#include "Musica.hpp"
#include <cmath>
#include <iomanip>
Musica::Musica()
{


}

Musica::Musica(int id, string nome, string artista, string album, float duracao)
{
    this->_id =id;
    this->_nome =nome;
    this->_artista =artista;
    this->_album =album;
    this->_duracao =duracao;
};
void Musica::imprimir_dados()
{
    duracao_em_minutos=this->_duracao;
    duracao_em_minutosdec= ((round(((_duracao-duracao_em_minutos)*100)))/100*60);
    if(duracao_em_minutos>=10)
    {
        if(duracao_em_minutosdec<10)
            std::cout<<this->_id<<"\t"<<this->_album<<"\t"<<this->_artista<<"\t"<<this->_nome<<"\t"<<duracao_em_minutos<<":0"<<setprecision(1)<<duracao_em_minutosdec<<"\t"<<this->_favorita<<"\n";
        else
            std::cout<<this->_id<<"\t"<<this->_album<<"\t"<<this->_artista<<"\t"<<this->_nome<<"\t"<<duracao_em_minutos<<":"<<setprecision(2)<<duracao_em_minutosdec<<"\t"<<this->_favorita<<"\n";
    }
    else
    {
        if(duracao_em_minutosdec<10)
            std::cout<<this->_id<<"\t"<<this->_album<<"\t"<<this->_artista<<"\t"<<this->_nome<<"\t"<<"0"<<duracao_em_minutos<<":0"<<setprecision(1)<<duracao_em_minutosdec<<"\t"<<this->_favorita<<"\n";
        else
            std::cout<<this->_id<<"\t"<<this->_album<<"\t"<<this->_artista<<"\t"<<this->_nome<<"\t"<<"0"<<duracao_em_minutos<<":"<<setprecision(2)<<duracao_em_minutosdec<<"\t"<<this->_favorita<<"\n";
    }
}
