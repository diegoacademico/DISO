/*
Bem vindo a biblioteca DISO.h, ela foi desenvolvida para facilitar o desenvolvimento do software "DISO SOLUÇÕES CONTÁBEIS" de modo que
linhas que comumente repetem ou funções que ocupavam uma quantidade considerável de espaço foram inseridas aqui, trazendo uma boa prática
e melhorando a compreensão do código-fonte como um todo.

por: Diego Martins
     Solon Vasconcelos

*/


//  todas as bibliotecas externas utilizadas no programa foram adicionadas a DISO.h, abaixo estão todas elas.



#include <string.h>         // Biblioteca para manipulação de strings.


#include <stdio.h>          // Biblioteca para utilizar funções básicas de input e output.


#include <stdlib.h>         // Biblioteca para acessar comandos básicos do CMD/Terminal.


#include <locale.h>         // Biblioteca para colocar o idioma como português.


/*
** Estrutura do tipo FUNCIONARIO, ela é composta por um char; nome, dois inteiros; faltas e Nfilhos e dois floats
** salario e horasExtras. É nesse tipo de estrutura que é armazenado todos os dados referentes aos funcionários.
*/

typedef struct
{
    char nome[35], CPF[20];
    int Nfilhos, NLfilhos, faltas;
    float acrescimoHORASextra, descontoFaltas;
    float descontoINSS, IRRF;
    float salario, horasExtras, salarioFamilia, salarioLiquido;
} FUNCIONARIO;

FUNCIONARIO funcionario;     // Declaração de uma estrutura de nome funcionario do tipo FUNCIONARIO.



/*
** Estrutura do tipo USUARIO, ela é composta por dois char; nome e senha. É nesse tipo de estrutura que é
** armazenado todos os dados referentes ao login do usuário, o administrador do software.
*/

typedef struct
{
    char nome[20];
    char senha[20];
} USUARIO;

USUARIO usuario;            // Declaração de uma estrutura de nome usuario do tipo USUARIO.


/*
** A função calculo é de grande importância, ela está contida em relatorio.c, o seu objetivo é efetuar todos os cálculos
** que serão printados na folha de relatório individual dos funcionários no menu 4.
*/

void calculos(void);


/*
** A função folha está contida em relatorio.c, nela se encontram todos os printfs da folha de relatório individual
** dos funcionários, sempre que se desejar mostrar esses dados a função folha deverá ser chamada.
*/

void folha(int B);


/*
** A função menuFolha é a responsável pela movimentação do ponteiro que seleciona o funcionário que escolhemos para
** ler os dados. Após a escolha ela chama a função folha.
*/


void menuFolha(void);



/*
** A função usuarioInexistente é uma void e está contida em usuario.c, ela é chamada caso o sistema detecte
** que não há nenhum usuário cadastrado, após ser chamada a única coisa que faz é printar na tela que
** não há usuário cadastrado. Em seguida, chama a função cadastrarUsuario.
*/

void usuarioInexistente(void);



/*
** A função cadastrarUsuario é uma void e está contida em usuario.c, ela só entraráem operação se for chamada
** tanto pela função usuarioInexistente, atualizarUsuario ou for de desejo do usuário do software. Ela gera um
** ponteiro para arquivo e escreve no arquivo "login.txt", fazendo uso também da estrutura "usuario".
*/

void cadastrarUsuario (void);



/*
** A função atualizarUsuario é umz void e está contida em usuario.c, ela entra em operação sempre que o usuário
** do software desejar atualizar seus dados. Sua operação se dá do seguinte modo: atualizarUsuario gera uma
** estrutura de nome "verifica", também utiliza um ponteiro para arquivo a fim de verificar "login.txt", após,
** ele faz a comparação entre strings, caso "verifica" (que será digitado), for igual a o que já estava em
** "login.txt" o usuário acertou a entrada. Assim a função automaticamente chama a função cadastrarUsuario.
*/

void atualizarUsuario (void);



/*
** Sua operação se dá do seguinte modo: login gera uma estrutura de nome "verifica", também utiliza um ponteiro
** para arquivo a fim de verificar "login.txt", após, ele faz a comparação entre strings, caso "verifica" (que será digitado),
** for igual a o que já estava em "login.txt" o usuário acertou a entrada.
*/

void login(void);



void pause(void);   // Função genérica contida em DISO.c para efetuar pausas no Linux e no Windows.



void limpaTela(void);    // Função genérica contida em DISO.c para limpar a tela no Linux e no Windows.



void menuprincipal(void);   // Apenas o Menu Principal contido na main.c, com as opções de escolha que redirecionam para outras áreas.



void cabecalho(void);   // Cabeçalho do programa, está contido em DISO.c.



void agradecimentos(void);	 // agradecimentos trata-se de uma série de printfs que aparecem sempre ao encerrar o programa, está contido em DISO.c.



/*
** A função tratarErro está contida em DISO.c, ela recebe como parâmetro um inteiro "k" e retorna um char "B". O char "B" recebe
** dados do usuário enquanto não for maior que '0' + k. Satisfeita a condição, retorna "B". Após, é necessário que o
** programador insira uma série de ifs para indicar o caminho que será percorrido nos menus. (ver função menuPrincipal em main.c).
*/

char *tratarErro(int k);



/*
** Função com o objetivo de verificar de há funcionários cadastrados e retornar a quantidade, ela está contida em DISO.c
** e funcionamento dela vê-se a seguir. Ela gera um ponteiro para arquivo para a leitura de "dados.txt", utilizando depois
** a função FSEEK ele posiciona oponteiro para o último caractere de "dados.txt", em seguida, utiliza mais uma operação.
** utilizando a função ftell ele conta os bytes que "dados.txt" ocupa e utilizando a função "sizeof(FUNCIONARIO)" ele
** verifica quantos bytes FUNCIONARIO ocupa. Realizando a divisão de "ftell" por "sizeof" se obtém a quantidade de funcionários cadastrados.
*/

int totalCadastro(void);



/*
** SITUACAO recebe um inteiro B, ela tem a função de, por meio de arquivos, analizar a situação de um determinado
** funcionário de posição (B -1) e efetuar a transferência para outras funções da escolha do usuário.
** (ver SITUACAO em funcionarios.c).
*/

void SITUACAO (int B);



/*
** Em menufuncionario, disponível em funcionarios.c. Se totalCadastro for maior que zero escolhemos uma posição.
** A posição do ponteiro é selecionada a partir da função fseek e printa na tela o nome do funcionário escolhido,
** após, chama a função SITUACAO com a posição escolhida em menufuncionario.
*/

void menufuncionario(void);



/*
** A função salario está contida em funcionarios.c. Ela gera um ponteiro para arquivo de leitura e escrita para poder
** manipular o arquivo "dados.txt", a partir do inteiro que ela recebe, posiciona o ponteiro para o local correto através
** da função fseek. Efetua a leitura e o usuário poderá editar o valor que aparece, caso não queira modificar deve digitar
** o mesmo valor que estava antes e precionar enter. Retornando para a função SITUACAO (int "posição de salario").
*/

void salario(int B);



/*
** A função Nfilhos está contida em funcionarios.c. Ela gera um ponteiro para arquivo de leitura e escrita para poder
** manipular o arquivo "dados.txt", a partir do inteiro que ela recebe, posiciona o ponteiro para o local correto através
** da função fseek. Efetua a leitura e o usuário poderá editar o valor que aparece, caso não queira modificar deve digitar
** o mesmo valor que estava antes e precionar enter. Retornando para a função SITUACAO (int "posição de Nfilhos").
*/

void Nfilhos(int B);



/*
** A função horasExtras está contida em funcionarios.c. Ela gera um ponteiro para arquivo de leitura e escrita para poder
** manipular o arquivo "dados.txt", a partir do inteiro que ela recebe, posiciona o ponteiro para o local correto através
** da função fseek. Efetua a leitura e o usuário poderá editar o valor que aparece, caso não queira modificar deve digitar
** o mesmo valor que estava antes e precionar enter. Retornando para a função SITUACAO (int "posição de horasExtras").
*/

void horasExtras(int B);



/*
** A função faltas está contida em funcionarios.c. Ela gera um ponteiro para arquivo de leitura e escrita para poder
** manipular o arquivo "dados.txt", a partir do inteiro que ela recebe, posiciona o ponteiro para o local correto através
** da função fseek. Efetua a leitura e o usuário poderá editar o valor que aparece, caso não queira modificar deve digitar
** o mesmo valor que estava antes e precionar enter. Retornando para a função SITUACAO (int "posição de faltas").
*/

void faltas(int B);



/*
** Função onde é feito o cadastro de todos os funcionários, diferente da função falta, horasExtras e afins, que são utilizadas
** apenas para modificar dados que já foram, em algum momento, cadastrados aqui. Todos os dados são gravados em "dados.txt".
** Encerrando a operação da função ela chama a função submenu3.
*/

void CADASTRO(void);


void apagarFuncionario(int B);

void escolherFuncionario(void);

