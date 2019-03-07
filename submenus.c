#include "DISO.h"


void submenu1(void)
{

    cabecalho();
    printf("|                     USUÁRIO                     |\n");
    printf("|                                                 |\n");
    printf("| 1-    Atualizar Usuário                         |\n");
    printf("| 0     Menu Principal                            |\n");
    printf(" ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n\n");


    char A[3];

    *A = tratarErro(1);

    if(*A=='1')
        atualizarUsuario();
    if(*A=='0')
        menuprincipal();
}


void submenu3(void)
{

    cabecalho();
    printf("|                 MENU SECUNDÁRIO 3               |\n");
    printf("|                                                 |\n");
    printf("| 1-    Cadastrar funcionários                    |\n");
    printf("| 2-    Atualizar Situação do Funcionário         |\n");
    printf("| 0     Menu Principal                            |\n");
    printf(" ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n\n");

    char A[3];

    *A = tratarErro(2);

    if(*A=='1')
        CADASTRO();
    if(*A=='2')
        menufuncionario();
    if(*A=='0')
        menuprincipal();
}

void submenu4(void)
{


    cabecalho();
    printf("|                    MENU SECUNDÁRIO 4            |\n");
    printf("|                                                 |\n");
    printf("| 1-    Resumo Geral do mês                       |\n");
    printf("| 2-    Folha de Pagamento Individual             |\n");
    printf("| 0     Menu Principal                            |\n");
    printf(" ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n\n");
    char A[3];

    *A = tratarErro(3);

    if(*A=='1');
    if(*A=='2') menuFolha();
    if(*A=='0')
        menuprincipal();
}
