#include <iostream>
#include <list>
#include "veiculo.hpp"
#include "caminhao.hpp"
#include "caminhao_autonomo.hpp"
#include <string>

using namespace std;
int main() {
    list<Veiculo*> veiculos;
    void print_list(list<Veiculo*> l);
    void rm_id(list<Veiculo*> &l, int id);
    void liberar_list(list<Veiculo*> &l);
    int velocidade,passageiros,carga,id,aux;
    string fabricante;
    string comando;

     while (cin>>comando)
    {
        if (comando=="add_c")
            aux=1;
        else if(comando=="add_ca")
            aux=2;
        else if(comando=="rm")
            aux=3;
        else if(comando=="print")
            aux=4;
        switch  (aux)
        {
            case 1:
                cin>>velocidade>>passageiros>>carga;
                veiculos.push_back(new Caminhao(velocidade,passageiros,carga));
                break;
            case 2:
                cin>>velocidade>>passageiros>>carga>>fabricante;
                veiculos.push_back(new CaminhaoAutonomo(velocidade,passageiros,carga,fabricante));
                break;
            case 3:
                cin>>id;
                rm_id(veiculos,id);
                break;
            case 4:
                print_list(veiculos);
                break;
            default:
                break;
        }
    }

    return 0;
}
void print_list(list<Veiculo*> l){
    for (std::list<Veiculo*>::iterator it=l.begin(); it != l.end(); it++) {
        (*it)->print_info();
    }
}
void rm_id(list<Veiculo*> &l, int id)
{
    for (std::list<Veiculo*>::iterator it=l.begin(); it != l.end(); ++it) {
        if((*it)->get_id()==id) {
            delete (*it);
            l.remove(*it);
            break;
        }
    }
}
