#include "DISO.h"


void cabecalho(void)
{
    limpaTela();
    printf("¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n");
    printf("|                                                 |\n");
    printf("|   >>>>>>>    DISO SOLUÇÕES CONTÁBEIS    <<<<<<  |\n");
    printf("|                                                 |\n");
    printf("|¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨|\n");
    printf("|                                                 |\n");
}

void agradecimentos(void)
{
    cabecalho();
    printf("|                 AGRADECIMENTOS                  |\n");
    printf("|                                                 |\n");
    printf("| A DISO SOLUÇÕES CONTÁBEIS agradece a preferência|\n");
    printf("| Nosso muito obrigado!                           |\n");
    printf("|                                                 |\n");
    printf("| Volte sempre!                                   |\n");
    printf(" ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n\n");
}



char *tratarErro(int k) 						//função tratarErro.
{
    char B;
    do
    {

    #ifdef WIN32
        B = getch();
    #else
        B = getchar();
    #endif

    }
    while((B <'0')||(B > '0'+k));

    return B;
}

int totalCadastro(void)       					//indica o total de funcionários cadastrados.
{
    FILE *arq;
    arq = fopen("dados.txt", "rb");

    fseek(arq, 0, SEEK_END);
    int total = ftell(arq)/sizeof(FUNCIONARIO);

    fclose(arq);
    return total;
}

void pause(void)
{
#ifdef WIN32
    system ("pause");
#else
    system("read -p \"Pressione enter para continuar...\" saindo");
#endif
}

void limpaTela(void){
#ifdef WIN32
    system ("cls");
#else
    system("clear");
#endif
}
