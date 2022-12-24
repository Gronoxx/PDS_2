#include "polvo.hpp"

Polvo::Polvo(double qi): Criatura("Polvo") {
    this->_qi=qi;
    std::cout<<"Polvo:"<<_subtipo<<endl;
}
Polvo::~Polvo() noexcept {
    std::cout<<"~Polvo:"<<_subtipo<<endl;
}

double Polvo::get_qi() {
    return _qi;
}

void Polvo::print_info() {
    Criatura::print_info();
    std::cout<<"\t"<<"QI: "<<this->_qi<<std::endl;
}

list<unique_ptr<Criatura>> Polvo::acasalar(shared_ptr<Criatura> c) {
    std::list<unique_ptr<Criatura>> filhos={};
    if(c->get_subtipo()=="Polvo")
    {
        std::shared_ptr<Polvo> polvo_de_fora = std::dynamic_pointer_cast<Polvo>(c);
            double qi_media=(this->_qi+polvo_de_fora->get_qi())/2;
            std::unique_ptr<Polvo> filho (new Polvo(qi_media));
            filhos.push_back(std::move(filho));
            return filhos;
    }
    return filhos;
}
