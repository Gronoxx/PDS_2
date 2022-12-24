#ifndef E_COMMERCE_PDS2_PRODUTO_HPP
#define E_COMMERCE_PDS2_PRODUTO_HPP
#include <iomanip>

class Produto {
private:
    int _id=0;
    int quantidade_produto=0;
    float _valor_unitario=0;
public:
    Produto(int id, float valor_unitario);
    virtual void imprimir_info() = 0;
    float get_valor_unitario();
    void set_valor_unitario(float valor);
    void set_id(int id);
    int get_id();
    void set_quantidade_produto(int qntd);
    int get_quantidade_produto();
};


#endif
