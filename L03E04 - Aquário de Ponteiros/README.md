Este é um exercício de POO Avançado para exercitar downcasting, smart pointers e construtor de cópia.

A tarefa é implementar um aquário de criaturas que se reproduzem. As criaturas podem ser peixes ou polvos que possuem mecanismos de acasalamento diferentes, justificando o uso de downcasting.

Arquivos fornecidos e que não podem ser alterados:

(links privados da ufmg)

Você deve fornecer os arquivos: criatura.cpp, peixe.cpp, polvo.cpp e aquario.cpp .

Dicas:

Este exercício requer usar bem sintaxe e conceitos, então antes de implementar cada parte sugiro que experimente com um conceito de cada vez com programas e classes mais simples.

Ou seja, aprenda e experimente downcasting, smart pointers e construtor de cópia um de cada vez.

Smart pointers são diferentes de ponteiros normais e é importante estar confortável com os seguintes aspectos:

Conceitos de unique_ptr<> e shared_ptr<>.

https://learn.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp?view=msvc-170

https://betterprogramming.pub/smart-pointers-in-cpp-708486276526

Declarar e inicializar. 

Transferir usando o comando std::move()

https://www.geeksforgeeks.org/stdmove-in-c/

https://en.cppreference.com/book/intro/smart_pointers

Passar um unique_ptr e um shared_ptr como argumento para uma função.

Fazer downcasting usando dynamic_pointer_cast

Implemente o exercício de forma gradual, deixando o construtor de cópia por último.

Especificação:

Criatura:

Atributos protected: string _subtipo

Métodos public:


Criatura(string subtipo);

Imprime: "Criatura:<_subtipo>"

Preenche _subtipo.

virtual ~Criatura();

Imprime: "~Criatura:<_subtipo>"

string get_subtipo();

Retorna _subtipo

virtual void print_info();

Imprime: "Info: <_subtipo>"

virtual list<unique_ptr<Criatura>> acasalar(shared_ptr<Criatura> c) = 0;

  
Peixe:

  
Atributos protected: double _peso, char _sexo;

Métodos public:
  

Peixe(double peso, char sexo);
  
Informa ao construtor de Criatura que esse objeto é do subtipo "Peixe"
  
Preenche _peso e _sexo
  
Imprime "Peixe:<_subtipo>"
  
virtual ~Peixe();
  
Imprime "~Peixe:<_subtipo>"
  
double get_peso();
  
char get_sexo();
  
virtual void print_info() override;
  
Chama print_info() de Criatura.
  
Imprime: "        Peso: <_peso> kg" com tab (\t)
  
Imprime: "        Sexo: <_sexo>" com tab (\t)
  
virtual list<unique_ptr<Criatura>> acasalar(shared_ptr<Criatura> c) override;
  
Gera novos filhotes retornando uma lista de ponteiros. Pode receber qualquer criatura como argumento.
  
O acasalamento só pode ocorrer entre dois peixes de sexos diferentes. Para qualquer caso inválido, retorne uma lista vazia.
  
No caso válido são gerados dois filhotes. O primeiro da lista possui _sexo = "F" e o segundo _sexo = "M". Ambos possuem _peso = média(peso do pai, peso da mãe).
  
Observações: 
  
Para descobrir o sexo e o peso do peixe você deve chamar métodos que não existem na classe Criatura. Então é necessário fazer um downcasting de shared_ptr<Criatura> c. Utilize a função: dynamic_pointer_cast.

  
Polvo:
  
Atributos protected: double _qi;
  
Métodos public:
  
Polvo(double qi);
  
Informa ao construtor de Criatura que esse objeto é do subtipo "Polvo"
  
Preenche _qi
  
Imprime "Polvo:<_subtipo>"
  
virtual ~Polvo();
  
Imprime "~Polvo:<_subtipo>"
  
double get_qi();
  
virtual void print_info() override;
  
Chama print_info() de Criatura.
  
Imprime: "        QI: <_qi>" com tab (\t)
  
virtual list<unique_ptr<Criatura>> acasalar(shared_ptr<Criatura> c) override;
  
Um Polvo só pode acasalar com outro Polvo e gera apenas um filhote, cujo qi = média do qi dos pais.

Aquario:
  
Atributos protected:  vector<shared_ptr<Criatura>> _criaturas;
  
Métodos public:
  
void add_peixe(double peso, char sexo);
  
Aloca um novo Peixe com shared_ptr e coloca com push_back no _criaturas.
  
void add_polvo(double qi);
  
Aloca um novo Polvo com shared_ptr e coloca com push_back no _criaturas.
  
void acasalamento(int id1, int id2);
  
id1 e id2 são indices do vetor _criaturas.
  
Caso id1 e id2 sejam inválidos, não faça nada.
  
Chame a função acasalar da criatura em id1 com a criatura em id2 como argumento.
  
Insira os novos filhotes, na ordem da lista retornada, no _criaturas.
  
Você provavelmente precisará usar a função move para manipular os smart pointers.
  
https://medium.com/factset/modern-c-in-depth-move-semantics-part-1-8a29d33944e4
void print();
  
  
Imprime o conteúdo do aquário chamando os métodos print_info() da seguinte forma:

=============
  
Aquario Info:
  
Info: Peixe
  
        Peso: 10 kg
  
        Sexo: M
  
Info: Polvo
  
        QI: 45
  
=============
  
Aquario(const Aquario &orig);
  
Construtor de cópia que deve fazer uma cópia profunda de um aquário. O novo aquário deve ser idêntico ao orig, mas não podem compartilhar nenhuma posição de memória apontada. Ou seja, modificar orig, e suas criaturas, não modifica o novo aquário e vice e versa.

Em C++ os modificadores de acesso são a nível de classe, então você acessar orig._criaturas.
  
O this->_criaturas deve ser preenchido com base em orig._criaturas.
  
Para cada Criatura você deve copiar o conteúdo e alocar uma nova posição de memória usando smart pointers.
  
O desafio aqui é manter o comportamento polimórfico dessas Criaturas. Dicas:
  
Use downcasting: dynamic_pointer_cast
  
Você deve usar o construtor de cópia definido implicitamente pelo compilador para Peixe e Polvo. Peixe(const Peixe &p) e Polvo(const Polvo &p).
  
Note que nas saídas dos teste 6,7 e 8, e no exemplo abaixo, não vemos os prints de construtor dos objetos alocados no construtor de cópia do Aquário. Isso ocorre pois eles devem ser criados utilizando o construtor de cópia implícito de Peixe e Polvo, e estes não dão os prints. 

Observações:

A avaliação será feita em parte com base nos prints dos destrutores e construtores, então a ordem da criação e dos objetos nas estruturas é importante. Além disso, não pode alocar objetos Peixe ou Polvo extras, pois gerariam prints errados. 

Pode ser que no seu computador a ordem dos destrutores seja diferente, então teste no Moodle caso esteja diferente dos exemplos.
  
Caso precise de um ponteiro auxiliar, não aloque memória, simplesmente aponte para o objeto desejado.
  
Os únicos pontos que devem alocar novos objetos são: 
  
Aquario::add_peixe()
  
Aquario::add_polvo()
  
Aquario::Aquario(const Aquario &orig)
  
Peixe::acasalar(shared_ptr<Criatura> c)
  
Polvo::acasalar(shared_ptr<Criatura> c)


Exemplo:

programa =


int main(){
    Aquario a;
    a.add_peixe(10, 'M');
    a.add_polvo(44.3);
    a.print();
    Aquario a2(a);
    a2.add_polvo(45.7);
    a2.acasalamento(1, 2);
    a2.print();
    return 0;
}

output =
  
Criatura:Peixe
  
Peixe:Peixe
  
Criatura:Polvo
  
Polvo:Polvo
  
=============
  
Aquario Info:
  
Info: Peixe
  
	Peso: 10 kg
  
	Sexo: M
  
Info: Polvo
  
	QI: 44.3
=============
  
Criatura:Polvo
  
Polvo:Polvo
  
Criatura:Polvo
  
Polvo:Polvo
  
=============
  
Aquario Info:
  
Info: Peixe
  
	Peso: 10 kg
  
	Sexo: M
  
Info: Polvo
  
	QI: 44.3
  
Info: Polvo
  
	QI: 45.7
  
Info: Polvo
  
	QI: 45
  
=============
  
~Peixe:Peixe
  
~Criatura:Peixe
  
~Polvo:Polvo
  
~Criatura:Polvo
  
~Polvo:Polvo
  
~Criatura:Polvo
  
~Polvo:Polvo
  
~Criatura:Polvo
  
~Peixe:Peixe
  
~Criatura:Peixe
  
~Polvo:Polvo
  
~Criatura:Polvo
