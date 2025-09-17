#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura que representa cada item da mochila
typedef struct {
    char nome[30];   // Nome do item
    char tipo[20];   // Tipo do item
    int quantidade;
} Item;

// Capacidade máxima da mochila
#define MAX_ITENS 10

// Vetor global que vai armazenar os itens da mochila
Item mochila[MAX_ITENS];
int totalItens = 0; // Contador de quantos itens estão na mochila

// Função para adicionar um novo item
void inserirItem() {
    if (totalItens >= MAX_ITENS) { // Se a mochila estiver cheia
        printf("\nMochila cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    Item novo;

    printf("\nDigite o nome do item: ");
    scanf(" %[^\n]", novo.nome); // Lê a string até ENTER

    printf("Digite o tipo do item (arma, munição, cura, etc): ");
    scanf(" %[^\n]", novo.tipo); // Lê a string até ENTER

    printf("Digite a quantidade: ");
    scanf("%d", &novo.quantidade);

    mochila[totalItens] = novo;
    totalItens++;

    printf("\n✅ Item adicionado com sucesso!\n");
}

// Função para remover item pelo nome
void removerItem() {
    if (totalItens == 0) { // Se a mochila estiver vazia
        printf("\n⚠️ Mochila vazia, nada para remover!\n");
        return;
    }

    char nomeRemover[30];
    printf("\nDigite o nome do item que deseja remover: ");
    scanf(" %[^\n]", nomeRemover);

    int encontrado = -1;

    // Busca sequencial para localizar o item
    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("\n❌ Item não encontrado na mochila.\n");
    } else {
        for (int i = encontrado; i < totalItens - 1; i++) {
            mochila[i] = mochila[i + 1];
        }
        totalItens--;
        printf("\n🗑️ Item removido com sucesso!\n");
    }
}

// Função para listar todos os itens cadastrados
void listarItens() {
    if (totalItens == 0) {
        printf("\n📦 Sua mochila está vazia.\n");
        return;
    }

    printf("\n--- Itens na Mochila ---\n");
    for (int i = 0; i < totalItens; i++) {
        printf("Nome: %s | Tipo: %s | Quantidade: %d\n",
               mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
    printf("-------------------------\n");
}

// Função para buscar item pelo nome
void buscarItem() {
    if (totalItens == 0) {
        printf("\n⚠️ Mochila vazia, nada para buscar.\n");
        return;
    }

    char nomeBusca[30];
    printf("\nDigite o nome do item que deseja buscar: ");
    scanf(" %[^\n]", nomeBusca);

    int encontrado = -1;

    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("\n❌ Item não encontrado.\n");
    } else {
        printf("\n🔎 Item encontrado:\n");
        printf("Nome: %s | Tipo: %s | Quantidade: %d\n",
               mochila[encontrado].nome,
               mochila[encontrado].tipo,
               mochila[encontrado].quantidade);
    }
}

// Função principal com o menu do sistema
int main() {
    int opcao;

    do {
        printf("\n===== Sistema de Inventário - Mochila Inicial =====\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: inserirItem(); break;
            case 2: removerItem(); break;
            case 3: listarItens(); break;
            case 4: buscarItem(); break;
            case 0: printf("\n🚪 Saindo do inventário...\n"); break;
            default: printf("\n⚠️ Opção inválida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
