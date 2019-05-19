#include "DISO.h"



void CADASTRO(void)				 //ESTA É A FUNÇÃO QUE GERENCIA O CADASTRO DOS FUNCIONÁRIOS.
{
    FILE *arq;
    arq = fopen("dados.txt", "ab");

    cabecalho();
    printf("|              CADASTRAR FUNCIONÁRIOS             |\n");
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf("|           Digite o nome do:         |\n");
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf(" ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n\n");

    scanf(" %[^\n]", funcionario.nome);


        cabecalho();
    printf("|              CADASTRAR FUNCIONÁRIOS             |\n");
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf("|             Digite o CPF funcionário:           |\n");
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf(" ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n\n");

    scanf(" %[^\n]", funcionario.CPF);

    cabecalho();
    printf("|              CADASTRAR FUNCIONÁRIOS             |\n");
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf("|           Digite a quantidade de faltas:        |\n");
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf(" ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n\n");

    scanf("%d", &funcionario.faltas);

    cabecalho();
    printf("|              CADASTRAR FUNCIONÁRIOS             |\n");
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf("|         Digite horas extras trabalhadas:        |\n");
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf(" ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n\n");

    scanf("%f", &funcionario.horasExtras);


    cabecalho();
    printf("|              CADASTRAR FUNCIONÁRIOS             |\n");
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf("|          Digite o salário do funcionário:       |\n");
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf(" ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n\n");

    scanf("%f", &funcionario.salario);

     cabecalho();
    printf("|              CADASTRAR FUNCIONÁRIOS             |\n");
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf("|            Digite o número de filhos:           |\n");
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf(" ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n\n");

    scanf("%d", &funcionario.Nfilhos);

    funcionario.NLfilhos = 0;

    if((funcionario.Nfilhos > 0)&&(funcionario.salario > 1300)){

         cabecalho();
    printf("|              CADASTRAR FUNCIONÁRIOS             |\n");
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf("|   Quantos dependentes são menores de 14 anos?   |\n");
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf(" ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n\n");

    scanf("%d", &funcionario.NLfilhos);

    }

    calculos();
    fwrite(&funcionario, sizeof(FUNCIONARIO), 1, arq);

    fclose(arq);
    submenu3();
}



void faltas(int B)		          // Esta função tem a função de armazenar as faltas.
{
    FILE *arq;
    arq = fopen("dados.txt", "w+b");

    fseek(arq, (B-1)*sizeof(FUNCIONARIO), SEEK_SET);
    fread(&funcionario, sizeof(FUNCIONARIO), 1, arq);

    cabecalho();
    printf("|                     FALTAS                      |\n");
    printf("|                                                 |\n");
    printf("| QUANTAS FALTAS %s TEVE NESTE MÊS?                \n", funcionario.nome);
    printf("|                                                 |\n");
    printf("| QUANTIDADE DE FALTAS: %d                         \n", funcionario.faltas);
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf(" ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n\n");

    scanf("%d", &funcionario.faltas);

    calculos();
    fwrite(&funcionario, sizeof(FUNCIONARIO), 1, arq);

    fclose(arq);
    SITUACAO(B);
}

void horasExtras(int B)		          // Esta função tem a função de armazenar as horas extras.
{
    FILE *arq;
    arq = fopen("dados.txt", "w+b");

    fseek(arq, (B-1)*sizeof(FUNCIONARIO), SEEK_SET);
    fread(&funcionario, sizeof(FUNCIONARIO), 1, arq);

    cabecalho();
    printf("|            TOTAL DE HORA(S) EXTRA(S)            |\n");
    printf("|                                                 |\n");
    printf("| QUANTAS HORAS EXTRAS %s TRABALHOU NESTE MÊS?     \n", funcionario.nome);
    printf("|                                                 |\n");
    printf("| QUANTIDADE DE HORAS EXTRAS: %g                   \n", funcionario.horasExtras);
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf(" ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n\n");

    scanf("%f", &funcionario.horasExtras);

    calculos();
    fwrite(&funcionario, sizeof(FUNCIONARIO), 1, arq);

    fclose(arq);
    SITUACAO(B);
}

void Nfilhos(int B)		          // Esta função tem a função de armazenar o número de filhos.
{
    FILE *arq;
    arq = fopen("dados.txt", "w+b");

    fseek(arq, (B-1)*sizeof(FUNCIONARIO), SEEK_SET);
    fread(&funcionario, sizeof(FUNCIONARIO), 1, arq);

    cabecalho();
    printf("|       FILHO(S) ATÉ 14 ANOS OU INCAPAZ(ES)       |\n");
    printf("|                                                 |\n");
    printf("| QUANTOS FILHOS ATENDEM AO QUESITO?              |\n");
    printf("|                                                 |\n");
    printf("| TOTAL DE FILHO(S) ATÉ 14 ANOS OU INCAPAZ(ES): %d \n", funcionario.NLfilhos);
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf(" ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n\n");

    scanf("%d", &funcionario.NLfilhos);

    calculos();
    fwrite(&funcionario, sizeof(FUNCIONARIO), 1, arq);

    fclose(arq);
    SITUACAO(B);
}

void salario(int B)  			 // Esta função tem a função de armazenar o salário.
{
    FILE *arq;
    arq = fopen("dados.txt", "w+b");

    fseek(arq, (B-1)*sizeof(FUNCIONARIO), SEEK_SET);
    fread(&funcionario, sizeof(FUNCIONARIO), 1, arq);


    cabecalho();
    printf("|                     SALÁRIO                     |\n");
    printf("|                                                 |\n");
    printf("| QUAL O SALÁRIO ATUAL DE %s?                      \n", funcionario.nome);
    printf("|                                                 |\n");
    printf("| VALOR ATUAL: %g                                  \n", funcionario.salario);
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf(" ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n\n");

    scanf("%f", &funcionario.salario);

    calculos();
    fwrite(&funcionario, sizeof(FUNCIONARIO), 1, arq);

    fclose(arq);
    SITUACAO(B);
}

void menufuncionario(void)			    //ESTA É A FUNÇÃO MENU FUNCIONÁRIO.
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


        fseek(arq, (B-1)*sizeof(FUNCIONARIO), SEEK_SET);
        fread(&funcionario, sizeof(FUNCIONARIO), 1, arq);


        cabecalho();
        printf("|               SITUAÇÃO DO FUNCIONÁRIO           |\n");
        printf("|                                                 |\n");
        printf("|                                                 |\n");
        printf("|     Parabéns, você escolheu %s!                  \n", funcionario.nome); //Informa o usuário escolhido.
        printf("|                                                 |\n");
        printf("|                                                 |\n");
        printf("|                                                 |\n");
        printf(" ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n\n");
        pause();

        fclose(arq);
        SITUACAO(B);         //chama a função SITUAÇÃO.
    }
}


void SITUACAO (int B)				//função menu situação dos funcionários
{
    FILE *arq;
    arq = fopen("dados.txt", "rb");

    fseek(arq, (B-1)*sizeof(FUNCIONARIO), SEEK_SET);
    fread(&funcionario, sizeof(FUNCIONARIO), 1, arq);

    cabecalho();
    printf("|               SITUAÇÃO DE %s                     \n", funcionario.nome);
    printf("|                                                 |\n");
    printf("| 1-    FALTAS                                    |\n");
    printf("| 2-    HORAS EXTRAS                              |\n");
    printf("| 3-    NUMERO DE FILHOS                          |\n");
    printf("| 4-    SALÁRIO                                   |\n");
    printf("| 0     Menu Principal                            |\n");
    printf(" ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n\n");
    fclose(arq);
    char A[3];

    *A = tratarErro(4);

    if(*A=='1')
        faltas(B);
    if(*A=='2')
        horasExtras(B);
    if(*A=='3')
        Nfilhos(B);
    if(*A=='4')
        salario(B);
    if(*A=='0')
        menuprincipal();

}
