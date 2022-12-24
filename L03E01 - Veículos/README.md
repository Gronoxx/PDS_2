O objetivo deste exercício é praticar mais os conceitos de Herança implementando uma hierarquia simples de veículos.

Especificações das classes a serem implementadas:

Veiculo:

Atributos private:

int _id, string subtipo, static int _next_id;

string subtipo guarda qual é o tipo mais específico do objeto, o mais baixo na hierarquia da herança. Ou seja, se um objeto é da classe CaminhaoAutonomo, então subtipo = "CaminhaoAutonomo" e não "Veiculo" nem "Caminhao".

Atributos protected:

int _velo_max, int _n_passageiros;

Métodos public:

Veiculo(string subtipo, int velo_max, int n_passageiros): Construtor que preenche os atributos e gera o _id. 

O _id deve ser gerado a partir da variável estática _next_id e contabiliza quantos veículos foram criados até agora. _id do primeiro veículo = 1.

O construtor é encarregado de incrementar _next_id.

virtual ~Veiculo():

Deve apenas imprimir: Destrutor Veiculo  

Destrutor da classe Veiculo precisa ser virtual, pois no caso abaixo ambos os destrutores ~Caminhao e ~Veiculo devem ser chamados. Entretanto, isso só ocorre quando é virtual. Esse assunto será tratado nas aulas de Polimorfismo.

Veiculo* vp;

vp = new Caminhao(120, 2, 1000);

delete vp;

int get_id(): Retorna _id.

virtual int estima_preco()=0;

virtual void print_info(): Imprime informações do veículo, no formato:

Info: Veiculo <_id>

Preco estimado: RS <print_info()>,00

Subtipo: <_subtipo>

Velocidade maxima: <_velo_max> km/h

Capacidade de passageiros: <_n_passageiros>



Os grandes espaços à esquerda são tabs (\t).

Caminhao :

Atributos protected:

int _carga_max;

Métodos public:

Caminhao(string subtipo, int velo_max, int n_passageiros, int carga_max)

Caminhao(int velo_max, int n_passageiros, int carga_max)

virtual ~Caminhao(): Deve imprimir: Destrutor Caminhao

int estima_preco()- Sobrescrita.

O preço de um caminhão é definido por: 50000 + 100 x carga_max + 10 x velo_max

void print_info() - Sobrescrita.

Imprime o print_info() da superclasse primeiro e depois:
        Carga maxima: <_carga_max> kg


CaminhaoAutonomo :

Atributos protected:

string _fabricante;

Métodos public:

CaminhaoAutonomo(int velo_max, int n_passageiros, int carga_max, string fabricante)

virtual ~CaminhaoAutonomo(): Deve imprimir: Destrutor CaminhaoAutonomo

int estima_preco() - Sobrescrita.

O preço de um caminhão autonomo é definido por:

Se fabricante == "Tesla": 500000 + 100 x carga_max + 10 x velo_max

Se fabricante == "Waymo": 400000 + 100 x carga_max + 10 x velo_max

void print_info() - Sobrescrita.

Imprime o print_info da superclasse primeiro e depois:

Fabricante: <_fabricante>

main.cpp

Por fim, você deve implementar o arquivo main.cpp da seguinte forma:

list<Veiculo*> veiculos : armazena objetos de subclasses de Veiculo.

void print_list(list<Veiculo*> l): Itera pela lista chamando o método print_info() de cada objeto.

void rm_id(list<Veiculo*> &l, int id): Modifica a lista l passada por referência removendo o elemento cujo _id é igual a id. Deve desalocar o elemento e remover da lista. Não faz nada caso não encontre o id.

Adicionar toda a parte de entrada/saída que será responsável por manipular os seguintes comandos:

add_c velocidade passageiros carga : Adiciona um novo caminhao a veiculos.

add_ca velocidade passageiros carga fabricante : Adiciona um novo caminhao autonomo a veiculos.

rm id: Chama a função rm_id

print: Chama a função print_list

Exemplo de entrada/saída:


input =

add_c 120 1 1000

add_c 100 4 200

add_ca 80 0 1000 Tesla

print

rm 1

rm 3

print

output =

Info: Veiculo 1

Preco estimado: RS 151200,00
     
     Subtipo: Caminhao
     
     Velocidade maxima: 120 km/h
     
     Capacidade de passageiros: 1
     
     Carga maxima: 1000 kg

Info: Veiculo 2

Preco estimado: RS 71000,00

        Subtipo: Caminhao

        Velocidade maxima: 100 km/h

        Capacidade de passageiros: 4

        Carga maxima: 200 kg


Info: Veiculo 3

Preco estimado: RS 600800,00

        Subtipo: CaminhaoAutonomo

        Velocidade maxima: 80 km/h

        Capacidade de passageiros: 0

        Carga maxima: 1000 kg

        Fabricante: Tesla


Destrutor Caminhao

Destrutor Veiculo

Destrutor CaminhaoAutonomo

Destrutor Caminhao

Destrutor Veiculo

Info: Veiculo 2

Preco estimado: RS 71000,00

        Subtipo: Caminhao

        Velocidade maxima: 100 km/h

        Capacidade de passageiros: 4

        Carga maxima: 200 kg
