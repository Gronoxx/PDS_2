Neste exercício você deve fazer um programa para auxiliar no gerenciamento de playlists musicais. Para isso, você deverá usar o conceito de Listas Encadeadas.

Você deverá implementar dois TADs: Musica e Playlist. Cada TAD deve seguir as especificações abaixo:

Musica:

Atributos: int _id; std::string _nome; std::string _artista; std::string _album; float _duracao; bool _favorita; 

Musica(int id, string nome, string artista, string album, float duracao): Método construtor para a inicialização dos atributos. Uma músicas é inicializada com não favorita.

void imprimir_dados(): Método que faz a impressão dos atributos no seguinte formato: "album artista nome duracao favorita", com uma quebra de linha ao final. Atenção, nesse caso utilize tab (\t) para separar os elementos. A duração deve ser formatada de forma que um valor '1.5' (minutos) seja impresso como "01:30" (minutos:segundos). Você pode assumir que nenhuma música terá mais que 60 minutos. Veja os dois últimos links indicados abaixo para ajudar na formatação da saída.

Playlist:

void adicionar_musica(string nome, string artista, string album, float duracao): Método que recebe os dados de uma música e a adiciona ao final da playlist. No momento da inserção cada música deve receber um 'id', que é um número inteiro sequencial único para cada uma na playlist (o primeiro id deve ter valor 1). 

Musica* buscar_musica(string nome, string artista): Método que busca uma música na playlist e retorna um ponteiro para ela. Você pode assumir que um artista não possui músicas com mesmo nome, mas artistas diferentes podem. Caso não seja encontrada uma música deve-se retornar 'nullptr'.

void remover_musica(int id): Remove uma música da playlist baseada no id informado. Você pode assumir que o id sempre será válido, ou seja, de uma música da playlist.

void favoritar_musica(int id): Marca uma música como favorita. Quando uma música se torna favorita ela deve ser deslocada para o início da playlist. Se a música já for favorita nada deve ser feito.


void desfavoritar_musica(int id): Desmarca uma música como favorita. Quando uma música deixa de ser favorita ela deve ser deslocada para o final da playlist. Se a música já não for favorita nada deve ser feito.

void imprimir(): imprime a situação atual da playlist, ou seja, percorre toda a lista (do início para o final) e chama o método 'imprimir_dados()' de cada música. Ao final, deve-se imprimir: "Tempo total: TT", seguido de quebra de linha, onde TT representa o tempo total das músicas no formato hh:mm:ss (horas:minutos:segundos).

Você é livre para adicionar nos TADs quaisquer outros atributos ou métodos auxiliares que julgar necessário. Além disso, você também pode escolher entre utilizar uma Lista Simplesmente ou Duplamente Encadeada.

Por fim, você deve implementar o arquivo main.cpp e adicionar toda a parte de entrada/saída que será responsável por manipular os seguintes comandos:

'a nome artista album duracao': comando para adicionar uma nova música na playlist de acordo com os parâmetros passados. Você pode assumir que nome/artista/album sempre será uma única palavra. A duração é um número de ponto flutuante.

's nome artista': comando para buscar uma música de acordo com os parâmetros passados. Após recuperar deve imprimir os dados da música.

'r nome artista': comando para remover uma música da playlist de acordo com os parâmetros passados.

'f nome artista': comando para favoritar uma música da playlist de acordo com os parâmetros passados.

'd nome artista': comando para desfavoritar uma música da playlist de acordo com os parâmetros passados.

'p': comando para imprimir o estado atual da playlist. 

'b': deve chamar a função 'avaliacao_basica()' implementada no arquivo "avaliacao_basica_playlist.hpp" (já incluído no main.cpp). Essa função faz uma avaliação complementar do código (não apenas dos resultados).

Para ilustrar, abaixo é apresentado um exemplo de entrada/saída:

input = 

a Money TheBeatles ThatsWhatIWant 2.85

a Money PinkFloyd DarkSideOfMoon 4.7

a One Metallica JusticeForAll 7.75

a Calice ChicoBuarque ChicoBuarque 4.5

p

f One Metallica

f Calice ChicoBuarque

p

d One Metallica

p

r Money TheBeatles

p

output =

1       ThatsWhatIWant  TheBeatles      Money   02:51   0

2       DarkSideOfMoon  PinkFloyd       Money   04:42   0

3       JusticeForAll   Metallica       One     07:45   0

4       ChicoBuarque    ChicoBuarque    Calice  04:30   0

Tempo total: 00:19:48

4       ChicoBuarque    ChicoBuarque    Calice  04:30   1

3       JusticeForAll   Metallica       One     07:45   1

1       ThatsWhatIWant  TheBeatles      Money   02:51   0

2       DarkSideOfMoon  PinkFloyd       Money   04:42   0

Tempo total: 00:19:48

4       ChicoBuarque    ChicoBuarque    Calice  04:30   1

1       ThatsWhatIWant  TheBeatles      Money   02:51   0

2       DarkSideOfMoon  PinkFloyd       Money   04:42   0

3       JusticeForAll   Metallica       One     07:45   0

Tempo total: 00:19:48

4       ChicoBuarque    ChicoBuarque    Calice  04:30   1

2       DarkSideOfMoon  PinkFloyd       Money   04:42   0

3       JusticeForAll   Metallica       One     07:45   0

Tempo total: 00:16:57

ATENÇÃO: Lembre-se de fazer a correta modularização utilizando os arquivos .hpp e .cpp.
