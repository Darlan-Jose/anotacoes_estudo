#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct
{
    int chave;
    char nome[20];
} TipoItem;

typedef struct celula *apontador;

typedef struct celula
{
    TipoItem item;
    apontador prox;
    apontador ant;
} Celula;

typedef struct
{
    apontador primeiro, ultimo;
} TipoLista;

/*Função para criar Lista Vazia*/
void criar(TipoLista *lista)
{
    lista->primeiro = (apontador) malloc(sizeof(Celula));
    lista->primeiro->prox = NULL;
    lista->primeiro->ant = NULL;
    lista->ultimo = lista->primeiro;
}

/*Função que retorna 1 se a lista estiver vazia*/
int vazia(TipoLista lista)
{
    if(lista.primeiro == lista.ultimo)
    {
        return 1;
    }
    return 0;
}

void Insere (TipoLista *lista, TipoItem item)
{
    lista->ultimo->prox = (apontador) malloc(sizeof(Celula));
    lista->ultimo->prox->ant = lista->ultimo;
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->prox = NULL;
    lista->ultimo->item = item;
}

void Imprime (TipoLista lista)
{
    apontador aux;
    aux = lista.primeiro->prox;
    while (aux != NULL)
    {
        printf("Id: %d\n", aux->item.chave);
        printf("Nome: %s\n", aux->item.nome);
        aux = aux->prox;
    }
}

int Consulta (TipoLista lista, int chave)
{
    apontador aux;
    aux = lista.primeiro->prox;
    while (aux != NULL)
    {
        if (aux->item.chave == chave)
            return 1;
        aux = aux->prox;
    }
    return 0;
}

apontador ConsultaR (TipoLista lista, int chave)
{
    apontador aux, anterior;
    anterior = lista.primeiro;
    aux = lista.primeiro->prox;
    while (aux != NULL)
    {
        if (aux->item.chave == chave)
            return anterior;
        anterior = aux;
        aux = aux->prox;
    }
    return NULL;
}

void Retira (apontador p, TipoLista *lista, TipoItem *item)
{
    /*o item a ser retirado é o seguinte apontado por p*/
    apontador q;
    if (vazia(*lista) || p==NULL || p->prox==NULL)
    {
        printf("Erro: Lista vazia ou posicao nao existe");
        return;
    }
    q = p->prox;
    *item = q->item;
    p->prox = q->prox;
    if (p->prox == NULL)
        lista->ultimo = p;
    free(q);
}

int main()
{
    TipoLista minhaLista;
    TipoItem itemAux;
    apontador apontadorAux;
    int op, codigo;

    criar(&minhaLista);

    do
    {
        system("cls");
        printf(" 1 - Inserir \n 2 - Consultar \n 3 - Imprimir \n 4 - Excluir \n-1 - Sair \n\n Sua opcao: ");
        scanf("%d", &op);


        switch (op)
        {
        /*Opção de Inserir*/
        case 1:
            printf("\nChave: ");
            scanf(" %d", &itemAux.chave);
            fflush(stdin);
            printf("\nNome: ");
            scanf(" %s", &itemAux.nome);
            fflush(stdin);
            Insere(&minhaLista, itemAux);
            break;
        /*Opção de Consultar*/
        case 2:
            printf("\nChave a ser consultada: ");
            scanf("%d", &codigo);
            if (Consulta(minhaLista,codigo)==0)
                printf("\nNao existe elemento com o codigo informado.\n");
            else
                printf("\nCodigo encontrado.\n");
            system("Pause");
            break;
        /*Opção de imprimir*/
        case 3:
            if (vazia(minhaLista))
                printf("\nLista vazia!");
            else
            {
                printf("\nElementos da Lista\n");
                Imprime(minhaLista);
                system("Pause");
            }
            break;
        /*Opção de Excluir*/
        case 4:
            printf("\nChave a ser excluida: ");
            scanf("%d", &codigo);
            apontadorAux = ConsultaR(minhaLista,codigo);
            if (apontadorAux == NULL)
                printf("\nNao existe elemento com o codigo informado.\n");
            else
            {
                Retira(apontadorAux, &minhaLista, &itemAux);
                printf("\nCodigo encontrado.\n");
            }
            system("Pause");
            break;
        } //SWTICH
    }
    while (op != -1);  //DO .. WHILE

    system("PAUSE");
    return 0;
} //FINALIZANDO O MAIN

