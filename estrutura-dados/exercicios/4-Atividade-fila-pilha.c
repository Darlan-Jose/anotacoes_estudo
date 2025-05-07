#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {
    int id;
    int placa;
    char data_hora[20];
    char latitude[50];
    char longitude[50];
} TipoItem;

typedef struct celula *apontador;

typedef struct celula {
    TipoItem item;
    apontador prox;
} celula;

typedef struct {
    apontador primeiro;
} TipoFilaPilha;

/* Declarações das Funções */
void criar(TipoFilaPilha *fila_pilha);
int vazia(TipoFilaPilha fila_pilha);
void push(TipoFilaPilha *fila_pilha, TipoItem item);
void enfileirar(TipoFilaPilha *fila_pilha, TipoItem item);
int verificarID(TipoFilaPilha fila_pilha, int id);
apontador pop(TipoFilaPilha *fila_pilha);
apontador desenfileirar(TipoFilaPilha *fila_pilha);
void imprimir(TipoFilaPilha fila_pilha, int metodoEscolhido);
void zerar(TipoFilaPilha *fila_pilha);
void escolherMetodo(int *metodoEscolhido);

/* Implementações das Funções */
void criar(TipoFilaPilha *fila_pilha) {
    fila_pilha->primeiro = (apontador)malloc(sizeof(celula));
    if (fila_pilha->primeiro == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }
    fila_pilha->primeiro->prox = NULL;
}

int vazia(TipoFilaPilha fila_pilha){
    if(fila_pilha.primeiro->prox == NULL){
        return 1;
    }
    return 0;
}

void push(TipoFilaPilha *fila_pilha, TipoItem item){
    if(verificarID(*fila_pilha, item.id)==1){
        printf("O id do item ja esta na pilha\n");
        return;
    }else{
        apontador aux = fila_pilha->primeiro;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = (apontador) malloc(sizeof(celula));
        aux = aux->prox;
        aux->prox = NULL;
        aux->item = item;

        printf("Item inserido na pilha.\n");
    }
}

void enfileirar(TipoFilaPilha *fila_pilha, TipoItem item){
    if(verificarID(*fila_pilha, item.id)==1){
        printf("O id do item ja esta na fila\n");
        return;
    }else{
        apontador aux = fila_pilha->primeiro;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = (apontador) malloc(sizeof(celula));
        aux = aux->prox;
        aux->prox = NULL;
        aux->item = item;

        printf("Item inserido na fila.\n");
    }
}

int verificarID(TipoFilaPilha fila_pilha, int id){
    apontador aux;
    aux = fila_pilha.primeiro->prox;
    while(aux != NULL){
        if(aux->item.id == id){
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

apontador pop(TipoFilaPilha *fila_pilha) {
    if (vazia(*fila_pilha) == 1) {
        printf("A pilha esta vazia!!!\n");
        return NULL;
    } else {
        apontador aux = fila_pilha->primeiro->prox;
        apontador anterior = fila_pilha->primeiro;

        while (aux->prox != NULL) {
            anterior = aux;
            aux = aux->prox;
        }

        // A célula removida (aux) é retornada
        anterior->prox = NULL;
        return aux;  // Retorna o ponteiro para a célula removida
    }
}

apontador desenfileirar(TipoFilaPilha *fila_pilha) {
    if (vazia(*fila_pilha)) {
        printf("A fila esta vazia!!!\n");
        return NULL;
    }

    apontador aux = fila_pilha->primeiro->prox;
    fila_pilha->primeiro->prox = aux->prox;
    return aux;
}

void imprimir(TipoFilaPilha fila_pilha, int metodoEscolhido) {
    if (metodoEscolhido == 0) {
        printf("Escolha um metodo primeiro!\n");
        return;
    }

    if (vazia(fila_pilha) == 1) {
        if (metodoEscolhido == 2) {
            printf("A pilha está vazia!!!\n");
        } else {
            printf("A fila está vazia!!!\n");
        }
        return;
    } else {
        apontador aux = fila_pilha.primeiro->prox;
        while (aux != NULL) {
            printf("Id: %d\n", aux->item.id);
            printf("Placa: %d\n", aux->item.placa);
            printf("Data e Hora: %s\n", aux->item.data_hora);
            printf("Latitude: %s, Longitude: %s\n", aux->item.latitude, aux->item.longitude);
            printf("\n");
            aux = aux->prox;
        }
    }
}

void zerar(TipoFilaPilha *fila_pilha){
    apontador aux;
    aux = fila_pilha->primeiro;
    while(fila_pilha->primeiro->prox != NULL){
        desenfileirar(fila_pilha);
        free(aux);
    }
    criar(fila_pilha);
}


void escolherMetodo(int *metodoEscolhido) {
    if (*metodoEscolhido == 0) {
        int opcao;
        printf("Escolha entre Fila (1) ou Pilha (2): ");
        scanf("%d", &opcao);
        if (opcao == 1) {
            printf("Método de Fila escolhido.\n");
            *metodoEscolhido = 1;
        } else if (opcao == 2) {
            printf("Método de Pilha escolhido.\n");
            *metodoEscolhido = 2;
        } else {
            printf("Opção inválida.\n");
            return;
        }
    } else {
        printf("Não é possível alterar o método após a escolha inicial.\n");
    }
}

int main() {
    setlocale(LC_ALL, "portuguese");
    TipoFilaPilha fila_pilha;
    TipoItem item;
    int op;
    int metodoEscolhido = 0;
    apontador removido_f, removido_p;

    criar(&fila_pilha);

    do {
        system("cls");
        printf("1 - Escolher entre fila ou pilha (nao e possivel alterar depois)\n2 - Incluir novas posicoes\n3 - Retirar posicoes\n"
               "4 - Imprimir dados\n-1 - Sair\n\nSua opcao: ");
        scanf("%d", &op);
        switch (op) {
        case 1:
            escolherMetodo(&metodoEscolhido);
            system("pause");
            break;
        case 2:
            if (metodoEscolhido == 0) {
                printf("Escolha um método primeiro!\n");
            } else {
                printf("Informe os dados para o novo item:\n");
                printf("ID: ");
                scanf("%d", &item.id);
                printf("Placa: ");
                scanf("%d", &item.placa);
                printf("Data e Hora: ");
                scanf("%s", item.data_hora);
                printf("Latitude: ");
                scanf("%s", item.latitude);
                printf("Longitude: ");
                scanf("%s", item.longitude);

                if (metodoEscolhido == 1) {
                    enfileirar(&fila_pilha, item);
                } else if (metodoEscolhido == 2) {
                    push(&fila_pilha, item);
                }
            }
            system("pause");
            break;
        case 3:
            if (metodoEscolhido == 1) {
                removido_f = desenfileirar(&fila_pilha);
                if (removido_f != NULL) {
                    printf("Item retirado da fila:\n");
                    printf("Id: %d\n", removido_f->item.id);
                    printf("Placa: %d\n", removido_f->item.placa);
                    printf("Data e Hora: %s\n", removido_f->item.data_hora);
                    printf("Latitude: %s, Longitude: %s\n", removido_f->item.latitude, removido_f->item.longitude);
                    free(removido_f);
                }
            } else if (metodoEscolhido == 2) {
                 removido_p = pop(&fila_pilha);
                if (removido_p != NULL) {
                    printf("Item retirado da pilha:\n");
                    printf("Id: %d\n", removido_p->item.id);
                    printf("Placa: %d\n", removido_p->item.placa);
                    printf("Data e Hora: %s\n", removido_p->item.data_hora);
                    printf("Latitude: %s, Longitude: %s\n", removido_p->item.latitude, removido_p->item.longitude);
                    free(removido_p);  // Liberar a célula removida
                }
            } else {
                printf("Escolha um método primeiro!\n");
            }
            system("pause");
            break;
        case 4:
            imprimir(fila_pilha, metodoEscolhido);
            system("pause");
            break;
        }

    } while (op != -1);

    system("PAUSE");
    return 0;
}
