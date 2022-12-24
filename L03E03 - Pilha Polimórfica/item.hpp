#ifndef ITEM_HPP
#define ITEM_HPP
#include <iostream>
class Item{
private:
    int _key, _val;
public:
    Item(){

    };
    Item(int key, int val){
        this->_key=key;
        this->_val=val;
    };
    friend bool operator >(const Item &i1, const Item &i2){
        return i1._val>i2._val;
    };
    friend std::ostream & operator << (std::ostream &out, const Item &i){
        return out << "("<<i._key<<","<<i._val<<")";
    };
};
#endif
