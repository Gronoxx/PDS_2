O objetivo deste exercício é aplicar template e sobrecarga de operadores para Polimorfismo.

Você deve implementar uma pilha que funcione com qualquer tipo que tenha os operadores: ">" e "<<".Também implementará uma classe específica que possui esses operadores.

Especificação:

Pilha

Classe polimórfica usando template. Deve funcionar com int, double, float e Item.

template<class T>

  class Pilha{
  
  ...

  };

  Para que o template funcione, o .hpp deve conter tanto a declaração quanto a implementação da classe Pilha. Ou seja, não deve haver um .cpp separado. Para referência: https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl

  Atributos private:

  T* _arr : Array que armazena a pilha.

  int _max_tam : Tamanho máximo da pilha.

  int _top : Índice do elemento no topo da pilha.

  Métodos public:

  Pilha(int max_tam): Inicializa e aloca o array.

  ~Pilha() : Desaloca o array. Não precisa desalocar os elementos da pilha, eles são responsabilidade de fora.

  bool push(const T& novo_e) : Insere um novo elemento na pilha.Retorna true caso tenha espaço na pilha. false caso contrário.

  bool pop(T& valor) :Remove o elemento do topo da pilha, retornando por referência pelo argumento valor.Retorna true caso seja possível fazer o pop, ou seja, caso exista um elemento no topo. false caso contrário.

  bool get_maior(T& valor) :Retorna por referência o maior elemento da pilha pelo argumento valor.O maior elemento deve ser encontrado utilizando o operador ">" .Retorna true caso tenha algum elemento na pilha, ou seja, caso exista um elemento no topo. false caso contrário.

  bool vazia(): true se pilha está vazia, false caso contrário.

  void print(): itera pela pilha da base até o topo imprimindo cada elemento seguido de quebra de linha.
  
A impressão deve ser feita usando algo como: cout << elemento << endl;

  Item
  
  Classe que armazena um par <key, value> e é compatível com a Pilha.

  Queremos instanciar uma pilha da forma: Pilha<Item> pilha(10); 

  Atributos privados:

  int _key, _val;

  Métodos public:

  Item();

  Item(int key, int val);

  Operadores sobrecarregados para ser compatível com a Pilha:
  
  friend bool operator >(const Item &i1, const Item &i2);
 i1 > i2 se e somente se i1._val > i2._val
  
  friend std::ostream & operator << (std::ostream &out, const Item &i);

  Impressão de i: "(<i._key>,<i._val>)". Sem quebra de linha.

  Note que os operadores não são membros de Item e que "friend" permite que o operador acesse atributos private da classe Item.


Dicas:

  Implemente primeiro a Pilha para funcionar com tipos básicos como int e float.

  O exercício é simples e o mais importante é entender a sintaxe e funcionamento dos templates.
