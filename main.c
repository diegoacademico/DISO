#include "DISO.h"  //Biblioteca própria com materiais úteis


void main(void)
{
    setlocale (LC_ALL, "Portuguese");

    FILE *lg, *arq;
    lg = fopen("login.txt", "rb");
    arq = fopen("dados.txt", "ab");


    fread(&usuario, sizeof(USUARIO), 1, lg);
    fclose(lg);
    fclose(arq);

    if(strlen(usuario.nome) == 0)   usuarioInexistente();

    else
    {
        login();
        agradecimentos();
    }

    return 0;
}



void menuprincipal(void)
{
    cabecalho();
    printf("|                 MENU PRINCIPAL                  |\n");
    printf("|                                                 |\n");
    printf("| 1-    Usuários                                  |\n");
    printf("| 2-    Apagar Funcionário                        |\n");
    printf("| 3-    Atualizar Situação de Funcionários        |\n");
    printf("| 4-    Relatórios                                |\n");
    printf("| 0     Sair                                      |\n");
    printf(" ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n\n");

    char A[3];

    *A = tratarErro(4);

    if(*A=='1')
        submenu1();
    if(*A=='2')
        escolherFuncionario();
    if(*A=='3')
        submenu3();
    if(*A=='4')
        submenu4();
    if(*A=='0')
        agradecimentos();

}



