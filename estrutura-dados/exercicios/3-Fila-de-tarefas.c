#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {
    int id;
    char name[20];
    int priority;
    int wait;
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
void enfileirar(TipoFila *fila, TipoItem item);
void imprimir(TipoFila fila);
int buscar(TipoFila fila, int id);
apontador desenfileirar(TipoFila *fila);
int verificarID(TipoFila fila, int id);
void zerar(TipoFila *fila);
apontador matarProcessoMaiorWait(TipoFila *fila);
void executarProcesso(TipoFila *fila);

/* Implementação das Funções */
void criar(TipoFila *fila) {
    fila->primeiro = (apontador)malloc(sizeof(celula));
    if (fila->primeiro == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }
    fila->primeiro->prox = NULL;
}

int vazia(TipoFila fila) {
    return (fila.primeiro->prox == NULL);
}

void enfileirar(TipoFila *fila, TipoItem item) {
    if (verificarID(*fila, item.id)) {
        printf("O id do item já está na lista\n");
        return;
    } else {
        // Incrementa o tempo de todos os processos já na fila
        apontador aux = fila->primeiro->prox;
        while (aux != NULL) {
            aux->item.wait += 1;  // Incrementa o tempo de espera de cada processo
            aux = aux->prox;
        }

        // Enfileira o novo processo
        apontador novo = (apontador)malloc(sizeof(celula));
        if (novo == NULL) {
            printf("Erro ao alocar memória\n");
            exit(1);
        }
        novo->item = item;
        novo->prox = NULL;

        // Vai até o final da fila e insere o novo processo
        aux = fila->primeiro;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
        printf("Processo inserido com sucesso!\n");
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
            printf("Name: %s\n", aux->item.name);
            printf("Priority: %d\n", aux->item.priority);
            printf("Wait: %d\n", aux->item.wait);
            printf("\n");
            aux = aux->prox;
        }
    }
}

// Retorna: 1 se encontrar; 0 se não encontrar; -1 se estiver vazia
int buscar(TipoFila fila, int id) {
    if (vazia(fila)) {
        printf("A fila está vazia\n");
        return -1;
    }

    apontador aux = fila.primeiro->prox;
    while (aux != NULL) {
        if (aux->item.id == id) {
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

apontador desenfileirar(TipoFila *fila) {
    if (vazia(*fila)) {
        printf("A fila está vazia!!!\n");
        return NULL;
    }

    apontador aux = fila->primeiro->prox;
    fila->primeiro->prox = aux->prox;
    return aux;
}

int verificarID(TipoFila fila, int id) {
    apontador aux = fila.primeiro->prox;
    while (aux != NULL) {
        if (aux->item.id == id) {
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

void zerar(TipoFila *fila){
    apontador aux;
    aux = fila->primeiro;
    while(fila->primeiro->prox!=NULL){
        desenfileirar(fila);
        free(aux);
    }
    criar(fila);
}

apontador matarProcessoMaiorWait(TipoFila *fila) {
    if (vazia(*fila)) {
        printf("A fila está vazia!\n");
        return NULL;
    }

    apontador aux = fila->primeiro->prox;
    apontador maiorWait = aux;
    apontador anterior = fila->primeiro;

    while (aux != NULL) {
        if (aux->item.wait > maiorWait->item.wait) {
            maiorWait = aux;
            anterior = fila->primeiro;
            while (anterior->prox != maiorWait) {
                anterior = anterior->prox;
            }
        }
        aux = aux->prox;
    }

    anterior->prox = maiorWait->prox;

    return maiorWait;
}


void executarProcesso(TipoFila *fila) {
    if (vazia(*fila)) {
        printf("A fila está vazia! Não há processos para executar.\n");
        return;
    }

    apontador aux = desenfileirar(fila);

    apontador auxProcesso = fila->primeiro->prox;
    while (auxProcesso != NULL) {
        if (auxProcesso->item.wait > 1) {
            auxProcesso->item.wait -= 1;
        }
        auxProcesso = auxProcesso->prox;
    }

    printf("Processo com ID %d executado. Nome: %s\n", aux->item.id, aux->item.name);

    free(aux);
}

int main() {
    setlocale(LC_ALL, "portuguese");
    TipoFila fila;
    TipoItem item;
    int op;

    criar(&fila);

    do {
        system("cls");
        printf(" 1 - Incluir novo processo\n 2 - Executar um processo\n 3 - Matar um processo com maior tempo\n"
               " 4 - Imprimir filas\n -1 - Sair\n\n Sua opcao: ");
        scanf("%d", &op);

        switch (op) {
        case 1:
            printf("\nDigite os dados do novo processo:\n");
            printf("ID: ");
            scanf("%d", &item.id);
            printf("Nome: ");
            scanf("%s", item.name);
            printf("Prioridade: ");
            scanf("%d", &item.priority);
            item.wait = 1;

            enfileirar(&fila, item);
            system("pause");
            break;
        case 2:
            executarProcesso(&fila);
            system("pause");
            break;
        case 3:
            apontador morto = matarProcessoMaiorWait(&fila);
            if (morto != NULL) {
                printf("Processo com ID %d foi removido da fila. Nome: %s, Wait: %d\n", morto->item.id, morto->item.name, morto->item.wait);
                free(morto);
            }
            system("pause");
            break;
        case 4:
            printf("Fila de processos:\n");
            imprimir(fila);
            system("pause");
            break;
        }

    } while (op != -1);

    system("PAUSE");
    return 0;
}
