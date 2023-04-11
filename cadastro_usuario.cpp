#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USUARIOS 10

struct usuario {
    char nome[30];
    char nome_usuario[20];
    char email[60];
    char senha[20];
};


void cadastrar_usuario(struct usuario usuarios[], int *indice) {
    printf("Digite seu nome completo: ");
    scanf("%s", usuarios[*indice].nome);

    printf("Digite seu nome de usuario: ");
    scanf("%s", usuarios[*indice].nome_usuario);

    printf("Digite seu email: ");
    scanf("%s", usuarios[*indice].email);

    printf("Digite sua senha: ");
    scanf("%s", usuarios[*indice].senha);

    printf("Usuario cadastrado com sucesso!\n\n");

    (*indice)++;
}

void fazer_login(struct usuario usuarios[], int indice) {
    char nome_usuario[20], senha[20];
    int i;

    printf("Digite seu nome de usuario: ");
    scanf("%s", nome_usuario);

    printf("Digite sua senha: ");
    scanf("%s", senha);


    for (i = 0; i < indice; i++) {
        if (strcmp(nome_usuario, usuarios[i].nome_usuario) == 0 &&
            strcmp(senha, usuarios[i].senha) == 0) {
            printf("Login realizado com sucesso!\n");
            return;
        }
    }

    printf("Nome de usuario e/ou senha incorretos!\n");
}

int main() {
    struct usuario usuarios[MAX_USUARIOS];
    int num_usuarios = 0, escolha;

    do {
        printf("MENU\n\n");
        printf("O que voce deseja fazer?:\n");
        printf("1 - Cadastrar usuario\n");
        printf("2 - Fazer login\n");
        printf("0 - Sair\n\n");
        scanf("%d", &escolha);
        system("cls");

        switch (escolha) {
            case 1:
                printf("1 - Cadastrar usuario\n");
                if (num_usuarios < MAX_USUARIOS) {
                    cadastrar_usuario(usuarios, &num_usuarios);
                } else {
                    printf("Numero maximo de usuarios cadastrados atingido!\n");
                }
                break;

            case 2:
                printf("2 - Fazer login\n");
                fazer_login(usuarios, num_usuarios);
                break;

            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (escolha!= 0);

    return 0;
}
