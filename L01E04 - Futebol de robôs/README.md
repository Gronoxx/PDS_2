Neste exercício você deverá implementar dois Tipos Abstratos de Dados (TADs) para uma equipe de robótica. Utilizando Structs, você deve criar os seguintes TADs: Ponto2D e Robo. Cada TAD deve seguir as especificações abaixo:

Ponto2D: 
Ponto2D(double, double): método construtor que recebe dois parâmetros do tipo double que representam as coordenadas (x, y) e devem ser armazenados internamente. Atenção: veja a Dica 1.
double calcular_distancia(Ponto2D* ponto): método que calcula a distância euclidiana para outro ponto no plano.

Robo: 
Atributos: Além de outros atributos que você irá definir, o TAD deve ter os atributos: 
  - '_energia', do tipo double, que é sempre inicializado com valor 100. 
  - '_com_bola', do tipo booleano.
Robo(int, Ponto2D, bool): método construtor que recebe três parâmetros: (i) um inteiro que é o id único do robo, (ii) uma variável do tipo Ponto2D (atenção, a variável deve ficar na stack, ou seja, não deve ser usado ponteiro!), e (iii) um booleano, que representa se o robô possui a bola inicialmente. 
void mover(double v, double th, double t): método que atualiza a posição do robo nos eixos x e y de acordo com os parâmetros passados: v (magnitude do vetor velocidade), th (orientação, em radianos, do vetor velocidade), t (o tempo que a velocidade foi aplicada). Após o deslocamento, a distância percorrida deve ser deduzida do atributo '_energia'. Dica: faça uma decomposição vetorial simples e use a equação de cinemática da física. 
double calcular_distancia(Robo* robo): método que calcula e retorna a distância euclidiana para outro robo passado como parâmetro. Dica: o método já implementado em Ponto2D pode ajudar aqui!
Robo* determinar_robo_mais_proximo(Robo** naves, int n): método que recebe um array de ponteiros para robos (ou seja, o time) e um parâmetro que informa a quantidade de elementos nesse array. Deve determinar qual o robô mais próximo do robô que invocou o método e retornar um ponteiro para ele.
void passar_bola(Robo** time, int n): método que recebe um array de ponteiros para robos (ou seja, o time) e um parâmetro que informa a quantidade de elementos nesse array. Deve passar a bola do robô que invocou o método para o robô mais próximo dele. Passar a bola significa apenas modificar os valores do atributo '_com_bola'. Se o robô que invocou o método não estiver com a bola deve-se imprimir: "Estou sem a bola!", com uma quebra de linha ao final.
void imprimir_status(): imprime o estado atual do robô no seguinte formato: "id x y com_bola energia". Utilize tab (\t) para separar os elementos.
Como entrada serão fornecidas a posição (x, y) dos robôs que formam o time e qual robô está inicialmente com a bola. Em seguida, o sistema é executado considerando os comandos informados e algumas informações devem ser impressas na tela.

ATENÇÃO: Nesse exercício você não precisa implementar a função main! O objetivo é simular o caso em que você está implementando um TAD que será utilizado por outra pessoa (que conhece apenas o contrato). Dessa forma, a leitura dos dados de entrada e jogadas já estão implementadas, e você deve apenas implementar os TADs (Ponto2D e Robo). Você é livre para implementar nos TADS quaisquer outros métodos não mencionados que julgar necessário.

Para ilustrar, abaixo são apresentados exemplos de entrada/saída.

Nesse primeiro exemplo, é informado o tamanho do time e as informações dos robôs. O comando 's' é usado para imprimir os estados e o comando 'm' move o Robô '0'.

input =
3
0.0 0.0 1
2.0 0.0 0
4.0 0.0 0
s
m 0 1.0 0.0 1.0
s
output =
0       0.00    0.00    1       100.00
1       2.00    0.00    0       100.00
2       4.00    0.00    0       100.00
0       1.00    0.00    1       99.00
1       2.00    0.00    0       100.00
2       4.00    0.00    0       100.00

Neste segundo exemplo o comando 'b' é usado para informar que o Robô '0' (primeiro informado) deve passar a bola para o robô mais próximo, no caso o Robô '1' (segundo informado).

input =
3
0.0 0.0 1
2.0 0.0 0
4.0 0.0 0
s
b 0
s
output =
0       0.00    0.00    1       100.00
1       2.00    0.00    0       100.00
2       4.00    0.00    0       100.00
0       0.00    0.00    0       100.00
1       2.00    0.00    1       100.00
2       4.00    0.00    0       100.00

ATENÇÃO: Lembre-se de fazer a correta modularização utilizando os arquivos .hpp e .cpp.
