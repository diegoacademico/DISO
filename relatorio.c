#include "DISO.h"



void calculos(void)
{
    const float deducao = 189.59;
    float aliquotaINSS, aliquotaIMPOSTOrenda, parcela;

    if (funcionario.salario <= 1800)
    {

        aliquotaINSS =0.08;
        aliquotaIMPOSTOrenda = 0.00;
        parcela = 0.0;
    }

    if ((funcionario.salario > 1800)&&(funcionario.salario <= 2800))
    {

        aliquotaINSS = 0.09 ;
        aliquotaIMPOSTOrenda = 0.075;
        parcela = 142.8;
    }

    if ((funcionario.salario > 2800)&&(funcionario.salario <= 3700))
    {

        aliquotaINSS = 0.11 ;
        aliquotaIMPOSTOrenda = 0.15;
        parcela = 354.8;
    }

    if ((funcionario.salario > 3700)&&(funcionario.salario <= 4600))
    {
        aliquotaINSS = 0.11 ;
        aliquotaIMPOSTOrenda = 0.225;
        parcela = 636.13;
    }


    if (funcionario.salario > 4600)
    {
        aliquotaINSS = 0.11;
        aliquotaIMPOSTOrenda = 0.275;
        parcela = 869.36;

    }



    funcionario.IRRF = ((funcionario.salario - (funcionario.Nfilhos * deducao) - funcionario.descontoINSS) * aliquotaIMPOSTOrenda) - parcela;

    if(funcionario.salario >= 5531.31)  funcionario.descontoINSS = 608.44;

    else  funcionario.descontoINSS = aliquotaINSS * funcionario.salario;

    funcionario.acrescimoHORASextra = ((funcionario.salario / 220) * 1.5 * funcionario.horasExtras) + (funcionario.horasExtras / 25) * 5 * (funcionario.salario / 200) * 1.5;

    funcionario.descontoFaltas = (funcionario.salario/30) * funcionario.faltas + ((funcionario.salario / 30) / 7) * funcionario.faltas;

    if(funcionario.salario>859.88) funcionario.salarioFamilia = 31.07 * funcionario.NLfilhos;

    else funcionario.salarioFamilia = 44.09 * funcionario.NLfilhos;

    funcionario.salarioLiquido = (funcionario.salario + funcionario.salarioFamilia + funcionario.acrescimoHORASextra) - (funcionario.descontoFaltas + funcionario.descontoINSS + funcionario.IRRF);
}



void folha(int B)
{

    FILE *arq;
    arq = fopen("dados.txt", "rb");

    fseek(arq, (B-1)*sizeof(FUNCIONARIO), SEEK_SET);
    fread(&funcionario, sizeof(FUNCIONARIO), 1, arq);


    cabecalho();
    printf("|                  FOLHA DE PAGAMENTO             |\n");
    printf("|                                                 |\n");
    printf("| FUNCIONÁRIO: %s   CPF:%s                         \n", funcionario.nome,funcionario.CPF);
    printf("|                                                 |\n");
    printf("| PROVENTOS                                       |\n");
    printf("|                                                 |\n");
    printf("|SALÁRIO BRUTO:                            R$ %.2f \n",funcionario.salario);
    printf("|SALÁRIO FAMÍLIA:                          R$ %.2f \n", funcionario.salarioFamilia);
    printf("|HORAS EXTRAS:                             R$ %.2f \n", funcionario.acrescimoHORASextra);
    printf("|                                                 |\n");
    printf("|DESCONTOS                                        |\n");
    printf("|                                                 |\n");
    printf("|FALTAS:                                   R$ %.2f \n", funcionario.descontoFaltas);
    printf("|INSS:                                     R$ %.2f \n",funcionario.descontoINSS);
    printf("|IRRF:                                     R$ %.2f \n", funcionario.IRRF);
    printf("|                                                 |\n");
    printf("|SALÁRIO LÍQUIDO:                          R$ %.2f \n", funcionario.salarioLiquido);
    printf("|                                                 |\n");
    printf("| 0     Menu Principal                            |\n");
    printf(" ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n");

    fclose(arq);

    char A[3];

    *A = tratarErro(0);

    if(*A=='0')
        menuprincipal();
}


void menuFolha(void)			    //ESTA É A FUNÇÃO MENU FUNCIONÁRIO2.
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
        folha(B);         //chama a função SITUAÇÃO.
    }
}
