O objetivo deste VPL é praticar definir, lançar e capturar exceções.

Você deve implementar a classe Map, que é um std::map simplificado.

Map

Métodos públicos:

void read_from_file(string filename);

Insere novos pares (key, val) a partir do arquivo filename.

O arquivo é composto por várias linhas, cada uma no formato: "key val". (sem as aspas)

Exemplo: https://virtual.ufmg.br/20222/pluginfile.php/457235/mod_vpl/intro/map4.txt

Caso o arquivo não exista, deve lançar uma exceção do tipo map_exc::file_not_found .

Caso alguma das chaves inseridas entre em conflito, deve lançar map_exc::invalid_map_in_file informando a primeira linha com uma key problemática.

Os novos pares só devem ser inseridos no map caso nenhuma key dê conflito. Caso contrário, a exceção deve ser lançada e o map deve permanecer igual era antes de chamar read_from_file.

O arquivo pode ser inconsistente com ele mesmo, ou seja, ter pelo menos 2 keys iguais. Quando isso ocorrer, também deve-se lançar a exceção. Nesse caso, a linha da key problemática é a que tenta inserir a mesma key pela segunda vez.

bool find(int key, int &found_val);
Procura pela key. Casos:
Encontrou a key: retorna o val correspondente por referência pelo found_val, e retorna true.
Não encontrou: retorna false.
Essa função não utiliza exceções, pois foi feita pensando em utilizar para checar se uma key está sendo usada, ou seja, não é um comportamento excepcional não encontrar a key.

void insert(int key, int val);
Insere um novo par key e val.
Caso a key já esteja em uso, deve lançar map_exc::key_in_use

void remove(int key);
Remove um par do Map.
Caso a key não exista, deve lançar map_exc::key_not_found

void print();

Imprime todos os pares do mapa no formato <key, val>:

========================

<9,8>

<1,1>

<3,6>

<2,45>

========================

Utilize um std::list para guardar os pares (key, val).


Exceções: Todas devem herdar de std::exception e lembre-se de lançar por valor e capturar por referência (https://isocpp.org/wiki/faq/exceptions#what-to-catch).

Declare e implemente todas dentro do namespace map_exc no arquivo map_exceptions.hpp.

Por exemplo, para chamar a exceção key_in_use, eu devo usar map_exc::key_in_use.

key_in_use:

Métodos públicos:

key_in_use(int key); Único construtor.

const char * what () const throw (): Deve retornar "Key in use".

int get_key();

key_not_found:

Métodos públicos:

key_not_found(int key); Único construtor.

const char * what () const throw (): Deve retornar "Key not found".

int get_key();

file_not_found

Métodos públicos:

file_not_found(const char* file_name); Único construtor.

const char * what () const throw (): Deve retornar "File not found".

const char * get_file_name()

invalid_map_in_file: Métodos públicos:

invalid_map_in_file(const char* file_name, int line, int key); Único construtor

const char * what () const throw (): Deve retornar "Invalid Map in File".

const char * get_file_name();

int get_line();

int get_key();

main.cpp

O main deve receber comandos pela entrada padrão. Comandos:

i <key> <val>

Insere novo par.

Caso seja lançada uma exceção, deve imprimir: "Key in use key = <key>"

f <key>
  
Procura por um par.
  
Se encontrar imprime: "found <val> in key <key>"
  
Senão: "key <key> not found"
  
r <key>
  
Remove um par.
  
Caso seja lançada exceção: "Key not found key = <key>"
  
p
Chama Map::print()
  
r_f <filename>
  
Chama Map::read_from_file(filename)
  
Caso dê map_exc::invalid_map_in_file, imprime: "Invalid Map in File <filename> Key <key> in line <line_num>"
  
Caso dê map_exc::file_not_found, imprime: "File not found <filename>"
  


Exemplo:

Input:
i 0 1
  
i 1 2
  
i 0 1
  
r 0
  
r 3
  
i 0 2
  
p
  
Output:
  
Key in use key = 0
  
Key not found key = 3
  
========================
  
<1,2>
  
<0,2>
  
========================
