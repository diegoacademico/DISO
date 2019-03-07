#include "DISO.h"



void usuarioInexistente(void)
{
    cabecalho();
    printf("|                     USUÁRIO                     |\n");
    printf("|                                                 |\n");
    printf("|  Olá, nós verificamos que você ainda não possui |\n");
    printf("|  um usuário cadastrado, por favor, realize o    |\n");
    printf("|  cadastramento para desfrutar de tudo o que a   |\n");
    printf("|  DISO SOLUÇÕES CONTÁBEIS pode oferecer para a   |\n");
    printf("|  sua empresa.                                   |\n");
    printf("|                                                 |\n");
    printf(" ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n\n");
    pause();

    cadastrarUsuario();
}


void cadastrarUsuario (void)
{
    FILE *lg;
    lg = fopen("login.txt", "wb");

    cabecalho();
    printf("|                     USUÁRIO                     |\n");
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf("|           Digite um novo nome de usuário:       |\n");
    printf("|                                                 |\n");
    printf(" ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n\n");

    scanf(" %[^\n]", usuario.nome);

    cabecalho();
    printf("|                     USUÁRIO                     |\n");
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf("|         Digite uma nova senha de usuário:       |\n");
    printf("|                                                 |\n");
    printf(" ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n\n");

    scanf(" %[^\n]", usuario.senha);

    fwrite(&usuario, sizeof(USUARIO), 1, lg);

    fclose(lg);

    cabecalho();
    printf("|                     USUÁRIO                     |\n");
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf("|        Usuário cadastrado com sucesso!          |\n");
    printf("|                                                 |\n");
    printf(" ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n\n");
    pause();

    menuprincipal();

}

void atualizarUsuario (void)
{
    USUARIO verifica;

    FILE *lg;
    lg = fopen("login.txt", "rb");

    fread(&usuario, sizeof(USUARIO), 1, lg);

    cabecalho();
    printf("|                     USUÁRIO                     |\n");
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf("|        Digite o nome de usuário atual:          |\n");
    printf("|                                                 |\n");
    printf(" ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n\n");

    scanf(" %[^\n]", verifica.nome);

    while(strstr(verifica.nome, usuario.nome) == NULL)
    {

        cabecalho();
        printf("|                     USUÁRIO                     |\n");
        printf("|                                                 |\n");
        printf("|    Usuário não encontrado, digite novamente.    |\n");
        printf("|                                                 |\n");
        printf("|    Digite SAIR para voltar ao Menu Principal.   |\n");
        printf(" ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n\n");

        scanf(" %[^\n]", verifica.nome);

        if(strstr(verifica.nome, "SAIR") != NULL)
        {
            fclose(lg);
            menuprincipal();
        }
    }

    cabecalho();
    printf("|                     USUÁRIO                     |\n");
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf("|        Digite a senha do usuário atual:         |\n");
    printf("|                                                 |\n");
    printf(" ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n\n");

    scanf(" %[^\n]", verifica.senha);

    while(strstr(verifica.senha, usuario.senha) == NULL)
    {

        cabecalho();
        printf("|                     USUÁRIO                     |\n");
        printf("|                                                 |\n");
        printf("|    Senha não encontrada, digite novamente.      |\n");
        printf("|                                                 |\n");
        printf("|    Digite SAIR para voltar ao Menu principal.   |\n");
        printf(" ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n\n");

        scanf(" %[^\n]", verifica.senha);
        if(strstr(verifica.senha, "SAIR") != NULL)
        {
            fclose(lg);
            menuprincipal();
        }
    }

    fclose(lg);

    cadastrarUsuario();
}

void login (void)
{

    USUARIO verifica;

    FILE *lg;
    lg = fopen("login.txt", "rb");

    fread(&usuario, sizeof(USUARIO), 1, lg);

    cabecalho();
    printf("|                     USUÁRIO                     |\n");
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf("|        Digite o nome de usuário atual:          |\n");
    printf("|                                                 |\n");
    printf(" ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n\n");

    scanf(" %[^\n]", verifica.nome);

    while(strstr(verifica.nome, usuario.nome) == NULL)
    {

        cabecalho();
        printf("|                     USUÁRIO                     |\n");
        printf("|                                                 |\n");
        printf("|    Usuário não encontrado, digite novamente.    |\n");
        printf("|                                                 |\n");
        printf("|                                                 |\n");
        printf(" ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n\n");

        scanf(" %[^\n]", verifica.nome);

    }

    cabecalho();
    printf("|                     USUÁRIO                     |\n");
    printf("|                                                 |\n");
    printf("|                                                 |\n");
    printf("|        Digite a senha do usuário atual:         |\n");
    printf("|                                                 |\n");
    printf(" ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n\n");

    scanf(" %[^\n]", verifica.senha);

    while(strstr(verifica.senha, usuario.senha) == NULL)
    {

        cabecalho();
        printf("|                     USUÁRIO                     |\n");
        printf("|                                                 |\n");
        printf("|    Senha não encontrada, digite novamente.      |\n");
        printf("|                                                 |\n");
        printf("|                                                 |\n");
        printf(" ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n\n");

        scanf(" %[^\n]", verifica.senha);

    }

    fclose(lg);

    menuprincipal();
}
