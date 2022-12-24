#include <iostream>
#ifndef MAP_EXCP_MAP_EXCEPTIONS_H
#define MAP_EXCP_MAP_EXCEPTIONS_H


namespace map_exc {

    class key_in_use : public std::exception {
    private:
        int key;
    public:
        key_in_use(int key) {
            this->key = key;
        };

        const char *what() const throw() {
            return "Key in use";
        };

        int get_key() {
            return this->key;
        };
    };

    class key_not_found : public std::exception {
    private:
        int key;
    public:
        key_not_found(int key) {
            this->key = key;
        };

        const char *what() const throw() {
            return "Key not found";
        };

        int get_key() {
            return this->key;
        };
    };

    class file_not_found : public std::exception {
    private:
        const char *file_name;
    public:
        file_not_found(const char *file_name) {
            this->file_name = file_name;
        };

        const char *what() const throw() {
            return "File not found";
        };

        const char *get_file_name() {
            return this->file_name;
        };
    };

    class invalid_map_in_file : public std::exception {
    private:
        const char *file_name;
        int line, key;
    public:
        invalid_map_in_file(const char *file_name, int line, int key) {
            this->file_name = file_name;
            this->line = line;
            this->key = key;
        };

        const char *what() const throw() {
            return "Invalid Map in File";
        }

        const char *get_file_name() {
            return file_name;
        };

        int get_line() {
            return this->line;
        };

        int get_key() {
            return this->key;
        };
    };
}

#endif 
