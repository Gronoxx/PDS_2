O objetivo deste exercício é praticar o uso de diferentes estruturas da STL e a parte básica de Orientação à Objetos.

Você deve fazer um programa para ajudar na gestão de avaliações de filmes (similar ao IMDB). Para isso, deve-se implementar quatro Classes: Usuario, Filme, Review e RegistroAvaliacoes. Cada classe deve seguir as especificações abaixo:

Usuario: 

Atributos: string _login, string _nome; _reviews (que guarda uma coleção de elementos do tipo Review, você deve escolher a estrutura que julgar mais adequada para usar). 

Usuario(string login, string nome): Método construtor para a inicialização dos atributos. 

void associar_review(Review* review): Método que adiciona a avaliação passada como parâmetro na coleção de elementos.

void imprimir_info(): Método que imprime informações básicas do usuário no formato: "NOME Reviews: X" (onde X é o número de reviews feitos pelo usuário). Utilize tab (\t) para separar os elementos.

void imprimir_reviews(): Método que imprime todas as avaliações feitas pelo usuário. Caso o usuário ainda não tenha feito nenhuma, deve imprimir: "Usuario NOME não possui reviews!", seguido de quebra de linha. Caso possua reviews a impressão segue o formato:

NOME Reviews: X

NOME_FILME COMENTARIO NOTA

A nota deve ser impressa com apenas uma casa decimal (veja o último link indicado abaixo). Utilize tab (\t) para separar os elementos.

Filme: 

Atributos: int _id, string _nome, string _genero, int _duracao,  _reviews (que guarda uma coleção de elementos do tipo Review, você deve escolher a estrutura que julgar mais adequada para usar). 

Filme(int id, string nome, string genero, int duracao): Método construtor para a inicialização dos atributos. O id é um número sequencial iniciado com valor 1 e incrementado sempre que um novo filme é adicionado.

Review* adicionar_review(string comentario, float nota): Método que cria um novo review com os dados informados e o adiciona na coleção. Deve-se retornar um ponteiro para o review criado.

void imprimir_nota_consolidada(): Método que imprime uma consolidação das avaliações do filme no formato: "NOME Reviews: X Nota media: F.F". A nota média deve ser impressa com apenas uma casa decimal (veja o último link indicado abaixo). Utilize tab (\t) para separar os elementos.

Review: 

Atributos: Filme* _filme, string _comentario, float _nota. Atenção, veja a Dica 3!

Review(Filme* filme, string comentario, float nota): Método construtor para a inicialização dos atributos. 

RegistroAvaliacoes:

Atributos: crie coleções _usuarios e _filmes para guardar as informações. Você deve escolher a estrutura que julgar mais adequada para usar, lembrando que deve ser fácil acessar cada time. Dica: um map é bem útil!

void adicionar_usuario(string login, string nome): Método que cria um novo usuário com os parâmetros informados e adiciona na coleção.

void adicionar_filme(string nome, string genero, int duracao): Método que cria um novo filme com os parâmetros informados e adiciona na coleção. 

void adicionar_review(int id_filme, string login_usuario, string comentario, float nota): Método que adiciona um novo review considerando os parâmetros informados. Observe que você deve usar o id do filme e o login do usuário para recuperá-los antes de fazer as devidas associações.

void imprimir_estatisticas_usuarios(): percorre a coleção de usuários e imprime as informações gerais de cada um (chamar imprimir_info()). Os usuários devem ser impressos em ordem alfabética dos logins.

void imprimir_registro_geral(): percorre a coleção de filmes e imprime a consolidação das avaliações para cada um (chamar imprimir_nota_consolidada()).

void imprimir_reviews_usuario(string login): imprime todas as avaliações feitas pelo usuário com o login informado (chamar imprimir_reviews()).

Atenção, todos os atributos devem ser privados e acessados/manipulados fora das classes apenas através de métodos. Você é livre para adicionar quaisquer outros atributos ou métodos auxiliares que julgar necessário. Além disso, lembre-se de fazer a correta manipulação da memória ao utilizar ponteiros (o destrutor é um bom lugar para isso!). Faça também a modularização utilizando os arquivos .hpp e .cpp.

Por fim, você deve implementar o arquivo main.cpp e adicionar toda a parte de entrada/saída que será responsável por manipular os seguintes comandos:

'u login nome': comando para adicionar um usuário (o login é único para cada usuário, o nome pode não ser!).

'f nome genero duracao': comando para adicionar um filme.

'r id login comentario nota': comando para adicionar um review.

'p': comando para imprimir todo o registro de avaliações.

's': comando para imprimir as estatísticas dos usuários.

'l login': comando para imprimir as avaliações de um determinado usuário.

'b': deve chamar a função 'avaliacao_basica()' implementada no arquivo "avaliacao_basica_cinereview.hpp" (já incluído no main.cpp). Essa função faz uma avaliação complementar do código (não apenas dos resultados).

Você pode assumir que todas as strings que serão informadas *não* possuem espaço, ou seja, são palavras únicas. 


Para ilustrar, abaixo é apresentado um exemplo de entrada/saída:

input = 

u joao JoaoSilva

u maria MariaClara

f StarWars Ficcao 94

f Avengers Acao 140

r 1 joao Legal! 8

p

s

l joao

l maria

output = 

StarWars        Reviews: 1      Nota media: 8.0

Avengers        Reviews: 0      Nota media: 0.0

JoaoSilva       Reviews: 1

MariaClara      Reviews: 0

JoaoSilva       Reviews: 1

StarWars        Legal!  8.0

Usuario MariaClara nao possui reviews!


Dica 1:
O código da avaliação básica pode ser copiado aqui, caso você queira depurar algo localmente.

Dica 2:
Você pode usar os códigos dos exercícios anteriores e o da avaliação básica para lhe ajudar a fazer toda a parte de entrada/saída.

Dica 3:
Cuidado para não criar uma dependência circular (Review <-> Filme). Como alternativa, você pode apenas fazer a declaração do tipo Filme em Review.hpp sem especificar o contrato.
