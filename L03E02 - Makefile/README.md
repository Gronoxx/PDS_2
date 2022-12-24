Você possui um programa bem simples. Nele, Herói e Vilão herdam de Personagem. Cada Herói possui um Vilão como inimigo (atributo do tipo Vilão) e cada Vilão possui um objetivo. No main são instanciados heróis e vilões e chamado um método específico de cada um que é sobrescrito da classe Personagem para cada um deles.

O projeto está estruturado de acordo com a hierarquia de diretórios abaixo:


. programa

├── Makefile

├── build/

│  └── [arquivos.o]

├── include/

│  └── Heroi.hpp

│  └── Personagem.hpp

│  └── Vilao.hpp

└── src/

│  └── entidades/

│    └── Heroi.cpp

│    └── Personagem.cpp

│    └── Vilao.cpp

│  └── main.cpp

O seu objetivo é unicamente escrever um arquivo Makefile para esse programa, seguindo as seguintes orientações:

Todas as entidades e o arquivo main devem ser compilados individualmente e os arquivos *.o resultantes devem ser salvos no diretório /build/

Em seguida, os arquivos compilados devem ser linkados em um executável resultante chamado vpl_execution, que deve ser salvo no diretório raiz da aplicação.
Você pode copiar o arquivo zipado do projeto aqui para poder fazer o desenvolvimento localmente.

Atenção, a formatação (tabs, espaços, etc) do arquivo Makefile impacta no funcionamento. Uma sugestão é fazer as regras no VSCode/Notepad e copiar para o Moodle.
