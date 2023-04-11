#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VEICULOS 10

struct veiculo {
    char marca[20];
    char modelo[20];
    int ano;
    int km_rodados;
    int disponivel;
};

void cadastrar_veiculo(struct veiculo veiculos[], int *indice) {
    printf("Digite a marca do veiculo: ");
    scanf("%s", veiculos[*indice].marca);

    printf("Digite o modelo do veiculo: ");
    scanf("%s", veiculos[*indice].modelo);

    printf("Digite o ano do veiculo: ");
    scanf("%d", &veiculos[*indice].ano);

    printf("Digite o km rodados do veiculo: ");
    scanf("%d", &veiculos[*indice].km_rodados);

    veiculos[*indice].disponivel = 1;

    printf("Veiculo cadastrado com sucesso!\n\n");

    (*indice)++;
}

void listar_veiculos_disponiveis(struct veiculo veiculos[], int indice) {
    int i, count = 0;

    printf("Veiculos disponiveis para reserva:\n");
    for (i = 0; i < indice; i++) {
        if (veiculos[i].disponivel == 1) {
            printf("%d - %s %s, ano %d, %d km rodados\n", count+1, veiculos[i].marca, veiculos[i].modelo, veiculos[i].ano, veiculos[i].km_rodados);
            count++;
        }
    }

    if (count == 0) {
        printf("Nao ha veiculos disponiveis para reserva!\n\n");
    }
}

void reservar_veiculo(struct veiculo veiculos[], int indice) {
    int i, escolha;

    listar_veiculos_disponiveis(veiculos, indice);

    if (veiculos[0].disponivel == 0) {
        return;
    }

    printf("Digite o numero do veiculo que deseja reservar: ");
    scanf("%d", &escolha);

    for (i = 0; i < indice; i++) {
        if (veiculos[i].disponivel == 1) {
            escolha--;

            if (escolha == 0) {
                printf("veiculo %s %s, ano %d, %d km rodados, reservado com sucesso!\n\n", veiculos[i].marca, veiculos[i].modelo, veiculos[i].ano, veiculos[i].km_rodados);
                veiculos[i].disponivel = 0;
                return;
            }
        }
    }

    printf("Opcao invalida!\n\n");
}

int main() {
    struct veiculo veiculos[MAX_VEICULOS];
    int num_veiculos = 0, opcao;

    do {
        printf("Escolha uma opcao:\n");
        printf("1 - Cadastrar veiculo\n");
        printf("2 - Listar veiculos disponiveis para reserva\n");
        printf("3 - Reservar veiculo\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);
        system("cls");

        switch (opcao) {
            case 1:
                if (num_veiculos < MAX_VEICULOS) {
                    cadastrar_veiculo(veiculos, &num_veiculos);
                } else {
                    printf("Numero maximo de veiculos cadastrados atingido!\n\n");
                }
            break;
        case 2:
            listar_veiculos_disponiveis(veiculos, num_veiculos);
            break;
        case 3:
            reservar_veiculo(veiculos, num_veiculos);
            break;
        case 0:
            printf("Saindo...\n\n");
            break;
        default:
            printf("Opcao invalida!\n\n");
            break;
    }
} while (opcao != 0);

return 0;
}