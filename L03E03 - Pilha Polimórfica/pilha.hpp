#ifndef PILHA_HPP
#define PILHA_HPP
#include "item.hpp"
#include <iostream>
template<class T>
class Pilha{
private:
    T* arr;
    int _max_tam,_top=0;
public:
    Pilha(int max_tam){
        this->_max_tam=max_tam;
        this->arr= new T[max_tam];
    };
    ~Pilha(){
        delete this->arr;
    };
    bool push(const T& novo_e){
        if(this->_top==this->_max_tam)
            return false;
        else {
            *(arr + this->_top)=novo_e;
            this->_top++;
            return true;
        }
    };

    bool pop(T& valor){
        if (this->_top!=0){
            this->_top--;
            valor=*(arr + this->_top);
            return true;
        }
        else
            return false;
    };
    bool get_maior(T& valor){
        T aux=*(arr);
        if (this->_top==0)
            return false;
        for(int i=1;i<this->_top;i++) {
            if(*(arr + i)>aux)
                aux=*(arr + i);
        }
        valor=aux;
        return true;
        };
    bool vazia(){
        if (this->_top!=0)
            return false;
        else
            return true;
    };
    void print(){
        for(int i=0;i<this->_top;i++) {
            std::cout<<arr[i]<<std::endl;
        }
    };
};

#endif
