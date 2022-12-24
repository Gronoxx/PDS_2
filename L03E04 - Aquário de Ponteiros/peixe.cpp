#include "peixe.hpp"
#include <iostream>
#include <list>

Peixe::Peixe(double peso, char sexo):Criatura("Peixe") {
    this->_peso= peso;
    this->_sexo= sexo;
    std::cout<<"Peixe:"<<this->_subtipo<<std::endl;
}
Peixe::~Peixe() noexcept {
    std::cout<<"~Peixe:"<<this->_subtipo<<std::endl;
}

double Peixe::get_peso() {
    return this->_peso;
}

char Peixe::get_sexo() {
    return this->_sexo;
}

void Peixe::print_info() {
    Criatura::print_info();
    std::cout<<"\t"<<"Peso: "<<this->_peso<<" kg"<<std::endl;
    std::cout<<"\t"<<"Sexo: "<<this->_sexo<<std::endl;
}

list<unique_ptr<Criatura>> Peixe::acasalar(shared_ptr<Criatura> c) {
    list<unique_ptr<Criatura>> filhos;
    if(c->get_subtipo()=="Peixe")
    {
        std::shared_ptr<Peixe> peixe_de_fora = std::dynamic_pointer_cast<Peixe>(c);
        if(peixe_de_fora->get_sexo() != this->_sexo)
        {
            double media_peso= (this->_peso+peixe_de_fora->get_peso())/2;
            std::unique_ptr<Peixe> filho1 (new Peixe(media_peso,'F'));
            filhos.push_back(std::move(filho1));
            std::unique_ptr<Peixe> filho2 (new Peixe(media_peso,'M'));
            filhos.push_back(std::move(filho2));

        }
        else
            return filhos;
    }
    else return filhos;
    
     }
