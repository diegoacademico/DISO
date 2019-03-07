#include "DISO.h"


void escolherFuncionario(void)			    //ESTA É A FUNÇÃO APAGAR FUNCIONÁRIO.
{

    FILE *arq;
    arq = fopen("dados.txt", "rb");

    if(totalCadastro() == 0)
    {

        cabecalho();
        printf("|              SITUAÇÃO DO FUNCIONÁRIO            |\n");		//Verifica se o funcionário está cadastrado.
        printf("|                                                 |\n");
        printf("|                                                 |\n");
        printf("|     Não há funcionário cadastrado, por favor    |\n");
        printf("|           realize o cadastramento.              |\n");
        printf("|                                                 |\n");
        printf("|                                                 |\n");
        printf(" ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n\n");
        fclose(arq);
        pause();
        menuprincipal();

    }

    else
    {

        cabecalho();
        printf("|               SITUAÇÃO DO FUNCIONÁRIO           |\n");			//Escolhe o funcionário.
        printf("|                                                 |\n");
        printf("|                                                 |\n");
        printf("|     Digite de 1 a %d o número do funcionário:    \n", totalCadastro());
        printf("|                                                 |\n");
        printf("|                                                 |\n");
        printf("|                                                 |\n");
        printf(" ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n\n");
        int B;

        do
        {
            scanf("%d", &B);
        }
        while((B<1)||(B>totalCadastro()));


        fclose(arq);
        apagarFuncionario(B);         //chama a função escolherFuncionario.
    }
}


void apagarFuncionario(int B)
{

    FILE *arq, *arqAlterado;

    arq = fopen("dados.txt", "rb");
    arqAlterado = fopen("dadosAlterados.txt", "ab");

    int i;

    fread(&funcionario, sizeof(FUNCIONARIO), 1, arq);

    for(i=0; (i+1)<B; i++)                                         //Preciso tentar entender esse código mais tarde
    {
        //Foi feito por experimentação.

        fwrite(&funcionario, sizeof(FUNCIONARIO), 1, arqAlterado); //Armazena um registro no arquivo.
        fread(&funcionario, sizeof(FUNCIONARIO), 1, arq);

    }

    fread(&funcionario, sizeof(FUNCIONARIO), 1, arq);

    while(!feof(arq))
    {

        fwrite(&funcionario, sizeof(FUNCIONARIO), 1, arqAlterado); //Armazena um registro no arquivo.
        fread(&funcionario, sizeof(FUNCIONARIO), 1, arq);

    }

    fclose(arq);
    fclose(arqAlterado);

    remove("dados.txt");
    rename("dadosAlterados.txt", "dados.txt");

system("pause");
    cabecalho();
    printf("|              SITUAÇÃO DO FUNCIONÁRIO            |\n");
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf("|        Funcionário %d apagado com sucesso!       \n", B); //Informa o usuário escolhido.
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf(" ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n\n");
    pause();



    menuprincipal();
}
