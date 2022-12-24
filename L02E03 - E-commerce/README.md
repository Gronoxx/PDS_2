O objetivo deste exercício é avançar no uso de Orientação à Objetos e praticar a parte básica de Herança.

Você deve fazer um programa para uma loja virtual. Para isso, deverá implementar diferentes classes de acordo com as especificações abaixo:

Carrinho:

Atributos: vector<Pedido*> _pedidos.

void adicionar_pedido(Produto* produto, int quantidade): método que cria e adiciona um novo pedido na coleção.

void imprimir_resumo(): método que imprime um resumo dos pedidos do carrinho. Para cada produto primeiro deve-se chamar o método 'imprimir_info()', em seguida adicionar as informações 'Qtde: X Total produto: R$ VV.VV', por fim adicionar 'Total carrinho: R$ VV.VV', onde é informado o somatório de todos os pedidos. Os valores devem ser impressos com duas casas decimais.

Pedido: 

Atributos: Produto* _produto, int _quantidade.

Pedido(Produto* produto, int quantidade): método construtor para a inicialização dos atributos. 

double get_valor_total(): retorna o valor total do pedido, resultado da multiplicação do valor unitário do produto pela quantidade pedida.

Produto:

Atributos: int _id, float _valor_unitario.

Produto(int id, float valor_unitario): método construtor para a inicialização dos atributos.

virtual void imprimir_info() = 0: método virtual puro que será implementado nas subclasses.

Brinquedo (herda de Produto):

Atributos: string _nome, int _idade_minima.

Brinquedo(int id, float valor, string nome, int idade_minima): método construtor para a inicialização dos atributos.

void imprimir_info(): imprime as informações do produto no seguinte formato: 'ID Brinquedo NOME IDADE_MINIMA R$ VV.VV'. O valor unitário deve ser impresso com duas casas decimais. Utilize tab (\t) para separar os elementos.

Livro (herda de Produto):

Atributos: string _titulo, string _autor, int _ano.

Livro(int id, float valor, string titulo, string autor, int ano): método construtor para a inicialização dos atributos.

void imprimir_info(): imprime as informações do produto no seguinte formato: 'ID Livro TITULO AUTOR ANO R$ VV.VV'. O valor unitário deve ser impresso com duas casas decimais. Utilize tab (\t) para separar os elementos.

Eletronico (herda de Produto):

Atributos: string _marca, string _modelo.

Eletronico(int id, float valor, string marca, string modelo): método construtor para a inicialização dos atributos.

void imprimir_info(): imprime as informações do produto no seguinte formato: 'ID Eletronico MARCA MODELO R$ VV.VV'. O valor unitário deve ser impresso com duas casas decimais. Utilize tab (\t) para separar os elementos.

Catalogo:

Atributos: vector<Produto*> _produtos, int _id.

void adicionar_produto(string nome, int idade_minima, float valor): adiciona um novo produto do tipo 'Brinquedo' na coleção e incrementa o 'id'. O id é único e sequencial para todos os produtos, onde o primeiro valor deve ser 1.

void adicionar_produto(string titulo, string autor, int ano, float valor): adiciona um novo produto do tipo 'Livro' na coleção e incrementa o 'id'.

void adicionar_produto(string marca, string modelo, float valor): adiciona um novo produto do tipo 'Eletronico' na coleção e incrementa o 'id'.

Produto* buscar_produto(int id): busca um produto pelo id informado e retorna um ponteiro. Se o id não existir na coleção o método deve imprimir "Produto não encontrado!" (seguido de quebra de linha) e retornar 'nullptr'.

void imprimir(): percorre a coleção e imprime a informação de todos os produtos cadastrados.

Atenção, todos os atributos devem ser privados e acessados/manipulados fora das classes apenas através de métodos. Você é livre para adicionar quaisquer outros atributos ou métodos auxiliares que julgar necessário. Além disso, lembre-se de fazer a correta manipulação da memória ao utilizar ponteiros (o destrutor é um bom lugar para isso!). Faça também a correta modularização utilizando os arquivos .hpp e .cpp.


Por fim, você deve implementar o arquivo main.cpp e adicionar toda a parte de entrada/saída que será responsável por manipular os seguintes comandos:

'q nome idade valor': comando para adicionar um brinquedo no catálogo.

'l titulo autor ano valor': comando para adicionar um livro no catálogo. 

'e marca modelo valor': comando para adicionar um eletrônico no catálogo. 

'c': comando para imprimir o catálogo.

'p id quantidade': comando para adicionar um pedido no carrinho. O produto que fará parte do pedido deve ser recuperado pelo id informado. Se não existir um produto com o id nada deve ser feito (além da impressão da mensagem).

'r': comando para imprimir o resumo do carrinho.

'b': deve chamar a função 'avaliacao_basica()' implementada no arquivo "avaliacao_basica_ecommerce.hpp" (já incluído no main.cpp). Essa função faz uma avaliação complementar do código (não apenas dos resultados).

Você pode assumir que todas as strings que serão informadas *não* possuem espaço, ou seja, são palavras únicas. 


Para ilustrar, abaixo é apresentado um exemplo de entrada/saída:

input =

q Bola 3 5.50

l LordOfTheRings JRRTolkien 1954 29.90

e LG TV50P 1250.0

c

p 1 3

p 2 2

r

output = 

1       Brinquedo       Bola    3       R$ 5.50

2       Livro   LordOfTheRings  JRRTolkien      1954    R$ 29.90

3       Eletronico      LG      TV50P   R$ 1250.00

1       Brinquedo       Bola    3       R$ 5.50

Qtde: 3 Total produto: R$ 16.50

2       Livro   LordOfTheRings  JRRTolkien      1954    R$ 29.90

Qtde: 2 Total produto: R$ 59.80

Total carrinho: R$ 76.30
