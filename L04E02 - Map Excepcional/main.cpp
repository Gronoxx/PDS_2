#include <iostream>
#include "map_exceptions.hpp"
#include "map.hpp"
#include <string>
int main(){
   std::string comando;
   int key,val;
   Map map;
   std::string filename;
   while(std::cin>>comando){
       if(comando=="i"){
        std::cin>>key>>val;
        try {
            map.insert(key, val);
        }
        catch(map_exc::key_in_use& e){
            std::cout<<" key = "<<key<<std::endl;
        }
        }
       else if(comando=="f"){
        std::cin>>key;
        if(map.find(key,val)){
            std::cout<<"found "<<val<<" in key "<<key<<std::endl;
        }
        else{
            std::cout<<"key "<<key<<" not found"<<std::endl;
        }
       }
       else if(comando=="r"){
           std::cin>>key;
           try{
                    map.remove(key);
                }
           catch(map_exc::key_not_found& e){
               std::cout<<" key = "<<key<<std::endl;
           }
       }
       else if(comando=="p"){
            map.print();
       }
       else if("r_f"){
           std::cin>>filename;
           try{
               map.read_from_file(filename);
           }
           catch (map_exc::file_not_found& e){
               std::cout<<" "<<filename<<std::endl;
           }
           catch(map_exc::invalid_map_in_file& e){
               std::cout<<"Invalid Map in File"<<" "<<filename<<" Key "<<e.get_key()<<" in line "<<e.get_line()<<std::endl;
           }
       }

   }

    return 0;
}
