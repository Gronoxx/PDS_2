#include "avaliacao_basica_cinereview.hpp"
#include "RegistroAvaliacoes.hpp"

int main()
{
    RegistroAvaliacoes R_A;
    char comando;
    string nome,login,genero,comentario;
    float duracao,nota;
    int id;

    while (cin>>comando)
    {

        switch (comando)
        {
            case 'u':
                cin>>login>>nome;
                R_A.adicionar_usuario(login,nome);
                break;
            case 'f':
                cin>>nome>>genero>>duracao;
                R_A.adicionar_filme(nome,genero,duracao);
                break;
            case 'r':
                cin>>id>>login>>comentario>>nota;
                R_A.adicionar_review(id,login,comentario,nota);
                break;
            case 'p':
                R_A.imprimir_registro_geral();
                break;
            case 's':
                R_A.imprimir_estatisticas_usuarios();
                break;
            case 'l':
                cin>>login;
                R_A.imprimir_reviews_usuario(login);
                break;
            case 'b':
                 avaliacao_basica();
                break;


            default:
                cout<<endl;
                break;
        }

    }


}
