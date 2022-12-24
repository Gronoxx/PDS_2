#include "Usuario.hpp"
using namespace std;

Usuario::Usuario(string login, string nome) {
    this->_login=login;
    this->_nome=nome;
}
void Usuario::associar_review(Review* review)
{
    review_index++;
    _reviews.insert(pair<int,Review*>(review_index, review));
}
void Usuario::imprimir_info()
{
    cout<<this->_nome<<"\t"<<"Reviews:"<<"\t"<<review_index<<endl;
}
void Usuario::imprimir_reviews()
{
    if(review_index==0){
        cout<<"Usuario "<<this->_nome<<" nao possui reviews!"<<endl;
    }
    else {
        imprimir_info();
        map<int,Review*>::iterator it;
        for (it = _reviews.begin();it!=_reviews.end();it++) {
cout<<it->second->filme->_nome<<"\t"<<it->second->_comentario<<"  "<<it->second->_nota<<endl;
        }
    }
}
