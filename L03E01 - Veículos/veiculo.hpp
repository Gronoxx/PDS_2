#ifndef VEICULO_HPP
#define VEICULO_HPP

#include <string>
#include <iostream>

using namespace  std;
class Veiculo{
private:
    int _id=0;
    string subtipo;
    static int _next_id;
protected:
    int _velo_max, _n_passageiros;
public:
    Veiculo(string subtipo, int velo_max, int n_passageiros);
    virtual ~Veiculo();
    int get_id();
    virtual int estima_preco()=0;
    virtual void print_info();
    string get_subtipo();
    void set_subtipo(string subtipo);

};
#endif
