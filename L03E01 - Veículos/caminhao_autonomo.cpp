#include "caminhao_autonomo.hpp"
CaminhaoAutonomo::CaminhaoAutonomo(int velo_max, int n_passageiros, int carga_max, string fabricante): Caminhao(velo_max,n_passageiros,carga_max){
    set_subtipo("CaminhaoAutonomo");
    this->_fabricante=fabricante;
}
CaminhaoAutonomo::~CaminhaoAutonomo() {
    cout<<"Destrutor CaminhaoAutonomo"<<endl;
}

int CaminhaoAutonomo::estima_preco() {
    if(this->_fabricante=="Tesla")
        return (500000+100*_carga_max+10*_velo_max);
    else if(this->_fabricante=="Waymo")
        return (400000+100*_carga_max+10*_velo_max);
    else
    return 0;    
}
void CaminhaoAutonomo::print_info() {
      Caminhao::print_info();
    cout<<"\t"<<"Fabricante: "<<_fabricante<<endl;
}
