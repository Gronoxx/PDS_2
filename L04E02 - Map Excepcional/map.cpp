#include "map.hpp"
#include "map_exceptions.hpp"
void Map::read_from_file(std::string filename) {
    int count=0;
    std::ifstream inFile;
   try {
       inFile.open(filename);
   }
   catch(map_exc::file_not_found& e){
        std::cout<< e.what();
        throw;
   }
      if(inFile.is_open()) {
          while (inFile.good()) {
            inFile >> this->key;
            inFile >> this->val;
            count++;
            try {
                for (std::list<int>::iterator it = this->kys_vals.begin(); it != this->kys_vals.end(); ++it) {
                    if (*it == key ) {
                            const char *file_name = filename.c_str();
                            for(int i=0;i<((count-1)*2);i++)
                            {
                                std::list<int>::iterator it1 = this->kys_vals.end();
                                --it1;
                                kys_vals.erase(it1);
                            }
                            throw (map_exc::invalid_map_in_file(file_name, count, key));
                            break;
                    }
                    ++it;
                }
                kys_vals.push_back(this->key);
                kys_vals.push_back(this->val);
            }
            catch (map_exc::key_in_use &e) {
                std::cout << e.what() << std::endl;
                throw;
            }

          }
      }
      else{
          std::cout<<"FILE NOT OPEN"<<std::endl;
      }

        inFile.close();
}

bool Map::find(int key, int &found_val) {
    for (std::list<int>::iterator it = this->kys_vals.begin(); it != this->kys_vals.end(); ++it) {
        if (*it == key) {
            it++;
            found_val = *(it);
            return true;
        }
        ++it;
    }
    return false;
}

void Map::insert(int key, int val) {
    try {
        if (find(key, val)) {
            throw (map_exc::key_in_use(key));
        }
        else{
            kys_vals.push_back(key);
            kys_vals.push_back(val);
            }
        }
    catch( map_exc::key_in_use& e){
        std::cout<<e.what();
        throw;
    }
}

void Map::remove(int key) {
    int aux_value;
    try {
        if (!(find(key, aux_value))) {
            throw (map_exc::key_not_found(key));
        }
        else{
            for (std::list<int>::iterator it = this->kys_vals.begin(); it != this->kys_vals.end(); ++it) {
                if (*it == key) {
                    std::list<int>::iterator it2= it++;
                    kys_vals.erase(it);
                    kys_vals.erase(it2);
                    break;
                }
            }
        }
    }
    catch(map_exc::key_not_found& e) {
        std::cout<<e.what();
        throw;
    }
}

void Map::print() {
    std::cout<<"========================"<<std::endl;
    for (std::list<int>::iterator it = this->kys_vals.begin(); it != this->kys_vals.end(); ++it) {
        std::cout<<"<"<<*it<<",";
        ++it;
        std::cout<<*it<<">"<<std::endl;
    }
    std::cout<<"========================"<<std::endl;
}
