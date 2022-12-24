#include "veiculo.hpp"
int Veiculo::_next_id = 1;
Veiculo::Veiculo(std::string subtipo, int velo_max, int n_passageiros) {
     _id=Veiculo::_next_id;
     Veiculo::_next_id++;
    this->subtipo=subtipo;
    _velo_max=velo_max;
    _n_passageiros=n_passageiros;
}
Veiculo::~Veiculo() {
    cout<< "Destrutor Veiculo"<<endl;
}
int Veiculo::get_id() {
    return this->_id;
}
void Veiculo::print_info() {
    cout<<"Info: Veiculo "<<_id<<endl
    <<"Preco estimado: RS "<<this->estima_preco()<<",00"<<endl
    <<"\t"<<"Subtipo: "<<subtipo<<endl
    <<"\t"<<"Velocidade maxima: "<< _velo_max<<" km/h"<<endl
    <<"\t"<<"Capacidade de passageiros: "<<_n_passageiros<<endl;
}
string Veiculo::get_subtipo() {
    return subtipo;
}
void Veiculo::set_subtipo(std::string subtipo) {
    this->subtipo=subtipo;
}
