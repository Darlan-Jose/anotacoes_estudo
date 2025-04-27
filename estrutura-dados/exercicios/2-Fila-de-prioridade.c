#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {
    int id;
    char nome[20];
    int senha;
} TipoItem;

typedef struct celula *apontador;

typedef struct celula {
    TipoItem item;
    apontador prox;
} celula;

typedef struct {
    apontador primeiro;
} TipoFila;

/* Declarações das Funções */
void criar(TipoFila *fila);
int vazia(TipoFila fila);
void Fila_Enfileira_Normal(TipoFila *fila, TipoItem item);
void Fila_Enfileira_Preferencial(TipoFila *fila, TipoItem item);
void imprimir(TipoFila fila);
int buscar(TipoFila fila, int id);
apontador desenfileirar(TipoFila *filaNormal, TipoFila *filaPreferencial, int *contadorPreferencial);
int verificarID(TipoFila fila, int id);
void zerar(TipoFila *fila);

/* Implementação das Funções */
void criar(TipoFila *fila) {
    fila->primeiro = (apontador)malloc(sizeof(celula));
    if (fila->primeiro == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }
    fila->primeiro->prox = NULL;
}

int vazia(TipoFila fila){
    if(fila.primeiro->prox == NULL){
        return 1;
    }
    return 0;
}

void Fila_Enfileira_Normal(TipoFila *fila, TipoItem item) {
    if (verificarID(*fila, item.id)) {
        printf("O id do item já está na lista\n");
        return;
    }else{
        apontador aux = fila->primeiro;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }

        apontador novo = (apontador)malloc(sizeof(celula));
        if (novo == NULL) {
            printf("Erro ao alocar memória\n");
            exit(1);
        }
        novo->item = item;
        novo->prox = NULL;
        aux->prox = novo;
    }
}

void Fila_Enfileira_Preferencial(TipoFila *fila, TipoItem item) {
    if (verificarID(*fila, item.id)) {
        printf("O id do item já está na lista\n");
        return;
    }else{
        apontador aux = fila->primeiro;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }

        apontador novo = (apontador)malloc(sizeof(celula));
        if (novo == NULL) {
            printf("Erro ao alocar memória\n");
            exit(1);
        }
        novo->item = item;
        novo->prox = NULL;
        aux->prox = novo;
    }
}

void imprimir(TipoFila fila) {
    if (vazia(fila)==1) {
        printf("A fila está vazia!!!\n");
        return;
    }else{
        apontador aux = fila.primeiro->prox;
        while (aux != NULL) {
            printf("Id: %d\n", aux->item.id);
            printf("Nome: %s\n", aux->item.nome);
            printf("Senha: %d\n", aux->item.senha);
            printf("\n");
            aux = aux->prox;
        }
    }
}

// Retorna: 1 se encontrar; 0 se não encontrar; -1 se estiver vazia
int buscar(TipoFila fila, int id) {
    if (vazia(fila)==1) {
        printf("A fila está vazia\n");
        return -1;
    }else{
        apontador aux = fila.primeiro->prox;
        while (aux != NULL) {
            if (aux->item.id == id) {
                return 1;
            }
            aux = aux->prox;
        }
        return 0;
    }
}

apontador desenfileirar(TipoFila *filaNormal, TipoFila *filaPreferencial, int *contadorPreferencial) {
    apontador removido = NULL;

    if (!vazia(*filaPreferencial) && *contadorPreferencial < 2) {
        removido = filaPreferencial->primeiro->prox;
        filaPreferencial->primeiro->prox = removido->prox;
        (*contadorPreferencial)++;
        return removido;
    }

    if (*contadorPreferencial >= 2) {
        if (!vazia(*filaNormal)) {
            removido = filaNormal->primeiro->prox;
            filaNormal->primeiro->prox = removido->prox;
            *contadorPreferencial = 0;
            return removido;
        } else {
            printf("A fila normal está vazia!\n");
        }
    }

    if (vazia(*filaPreferencial) && !vazia(*filaNormal)) {
        removido = filaNormal->primeiro->prox;
        filaNormal->primeiro->prox = removido->prox;
        return removido;
    }

    if (!vazia(*filaPreferencial)) {
        removido = filaPreferencial->primeiro->prox;
        filaPreferencial->primeiro->prox = removido->prox;
        (*contadorPreferencial)++;
        return removido;
    } else if (!vazia(*filaNormal)) {
        removido = filaNormal->primeiro->prox;
        filaNormal->primeiro->prox = removido->prox;
        return removido;
    }

    printf("Ambas as filas estão vazias!\n");
    return NULL;
}

int verificarID(TipoFila fila, int id) {
    apontador aux;
    aux = fila.primeiro->prox;
    while (aux != NULL) {
        if (aux->item.id == id) {
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

void zerar(TipoFila *fila){
    apontador excluir, aux;
    aux = fila->primeiro;
    while(fila->primeiro->prox!=NULL){
        desenfileirar(fila, fila, NULL);
        free(aux);
    }
    criar(fila);
}

int main() {
    setlocale(LC_ALL, "portuguese");
    TipoFila filaNormal, filaPreferencial;
    TipoItem item;
    int op, senha_normal = 0, senha_preferencial = 1;
    int contadorPreferencial = 0;

    criar(&filaNormal);
    criar(&filaPreferencial);

    do {
        system("cls");
        printf(" 1 - Inserir na fila normal\n 2 - Inserir na fila preferencial\n 3 - Desenfileirar\n 4 - Imprimir filas\n -1 - Sair\n\n Sua opcao: ");
        scanf("%d", &op);

        switch (op) {
        case 1:
            senha_normal++;
            printf("Digite o ID: ");
            scanf("%d", &item.id);
            printf("Digite o nome: ");
            scanf("%s", item.nome);
            item.senha= senha_normal;
            Fila_Enfileira_Normal(&filaNormal, item);
            system("pause");
            break;
        case 2:
            senha_preferencial++;
            printf("Digite o ID: ");
            scanf("%d", &item.id);
            printf("Digite o nome: ");
            scanf("%s", item.nome);
            item.senha= senha_preferencial;
            Fila_Enfileira_Preferencial(&filaPreferencial, item);
            system("pause");
            break;
        case 3:
            {
                apontador removido = desenfileirar(&filaNormal, &filaPreferencial, &contadorPreferencial);
                if (removido != NULL) {
                    printf("Desenfileirado: %d - %s\n", removido->item.id, removido->item.nome);
                    free(removido);
                }
                system("pause");
            }
            break;
        case 4:
            printf("Fila normal:\n");
            imprimir(filaNormal);
            printf("\nFila preferencial:\n");
            imprimir(filaPreferencial);
            system("pause");
            break;
        }

    } while (op != -1);

    system("PAUSE");
    return 0;
}
