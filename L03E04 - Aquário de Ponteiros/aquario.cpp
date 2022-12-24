#include "aquario.hpp"
#include <iostream>
void Aquario::add_peixe(double peso, char sexo) {
    std::shared_ptr<Peixe> shared_peixe = std::make_shared<Peixe>(peso,sexo);
    _criaturas.push_back(shared_peixe);
}

void Aquario::add_polvo(double qi) {
    std::shared_ptr<Polvo> shared_polvo = std::make_shared<Polvo>(qi);
    _criaturas.push_back(shared_polvo);
}

void Aquario::acasalamento(int id1, int id2) {
    int csize= _criaturas.size();
    if(0<=id1 && id1<csize && 0<=id2 && id2<csize)
    {
        list<unique_ptr<Criatura>> lista_filhos=(_criaturas[id1]->acasalar(_criaturas[id2]));
        for(std::list<unique_ptr<Criatura>>::iterator it=lista_filhos.begin();it!=lista_filhos.end();++it)
        {
            _criaturas.push_back(std::move(*it));
        }
    }
}

void Aquario::print() {
    cout<<"============="<<endl;
    cout<<"Aquario Info:"<<endl;
    for(std::vector<shared_ptr<Criatura>>::iterator it=_criaturas.begin();it!=_criaturas.end();++it)
    {
        (*it)->print_info();
    }
    cout<<"============="<<endl;
}
Aquario::Aquario(const Aquario &orig) {
  for(int i=0;i<orig._criaturas.size();i++)
    {
        if(orig._criaturas[i]->get_subtipo()=="Peixe")
        {
         std::shared_ptr<Peixe> peixe_de_fora = std::dynamic_pointer_cast<Peixe>(orig._criaturas[i]);
         std::shared_ptr<Peixe> peixe_novo = make_shared<Peixe>(*peixe_de_fora);
         this->_criaturas.push_back(peixe_novo); 
        }
        if(orig._criaturas[i]->get_subtipo()=="Polvo")
        {
         std::shared_ptr<Polvo> polvo_de_fora = std::dynamic_pointer_cast<Polvo>(orig._criaturas[i]);
         std::shared_ptr<Polvo> polvo_novo = make_shared<Polvo>(*polvo_de_fora);
         this->_criaturas.push_back(polvo_novo); 
        }
    }

    }
