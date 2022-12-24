O objetivo desse VPL é avançar na prática dos comandos de entrada e saída específicos de C++ (inserção/cout e extração/cin) e também a utilização do tipo string.

Você deve escrever um programa capaz de ocultar letras em uma frase. Será informada uma lista de letras que devem ser substituídas por '#' (hash) em toda a frase. A frase será composta por um número não conhecido anteriormente de palavras. Ao final, o programa deve imprimir a frase com as devidas alterações e o número de vezes que cada letra foi substituída na frase.

Para facilitar, você pode assumir que todas as palavras terão apenas letras minúsculas e que no máximo 10 letras serão informadas para substituição (também todas minúsculas). Além disso, o primeiro caractere da entrada informa o número de letras a serem informadas em seguida.

Exemplos de entrada e saída:

input = 
3 a u z
uruguai
output = 
#r#g##i 
a 1
u 3
z 0

input = 
5 a e i o u
eu e meus colegas de turma vamos nos dedicar muito em pds2!
output = 
## # m##s c#l#g#s d# t#rm# v#m#s n#s d#d#c#r m##t# #m pds2! 
a 4
e 7
i 2
o 4
u 4
