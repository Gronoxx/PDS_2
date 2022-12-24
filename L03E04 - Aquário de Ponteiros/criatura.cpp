#include "criatura.hpp"
#include <iostream>
Criatura::Criatura(std::string subtipo) {
    this->_subtipo=subtipo;
    std::cout<<"Criatura:"<<subtipo<<endl;
}
Criatura::~Criatura() {
    std::cout<<"~Criatura:"<<this->_subtipo<<endl;
}
string Criatura::get_subtipo() {
    return this->_subtipo;
}

void Criatura::print_info() {
    std::cout<<"Info: "<<this->_subtipo<<endl;
}
