#ifndef MAP_EXCP_MAP_H
#define MAP_EXCP_MAP_H
#include <fstream>
#include <iostream>
#include <list>

class Map {
private:
    int key=0,val=0;
    std::list<int> kys_vals;

public:
    void read_from_file( std::string filename);
    bool find(int key, int &found_val);
    void insert(int key, int val);
    void remove(int key);
    void print();
};


#endif //MAP_EXCP_MAP_H
