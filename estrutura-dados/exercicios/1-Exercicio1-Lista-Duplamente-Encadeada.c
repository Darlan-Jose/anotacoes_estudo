#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <locale.h>

typedef struct
{
    int chave;
    char nome[20];
    int pontos;
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

/*Funcao para criar Lista Vazia*/
void criar(TipoLista *lista)
{
    lista->primeiro = (apontador) malloc(sizeof(Celula));
    lista->primeiro->prox = NULL;
    lista->primeiro->ant = NULL;
    lista->ultimo = lista->primeiro;
}

/*Funcao que retorna 1 se a lista estiver vazia*/
int vazia(TipoLista lista)
{
    if(lista.primeiro == lista.ultimo)
    {
        return 1;
    }
    return 0;
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

void Insere(TipoLista *lista, TipoItem item)
{
    if (Consulta(*lista, item.chave))
    {
        printf("\nErro: Chave duplicada nao permitida!\n");
        return;
    }

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
        printf("Pontos: %d\n", aux->item.pontos);
        aux = aux->prox;
    }
}

/*Tive que trocar para essas duas funções recursivas
porque a outra função não funcionava direito depois
de utilizar a função de trocar elementos.
Essa funciona*/

void ImprimeReversoAux(apontador aux)
{
    if (aux == NULL)
        return; // Condição de parada

    ImprimeReversoAux(aux->prox);

    printf("Id: %d\n", aux->item.chave);
    printf("Nome: %s\n", aux->item.nome);
    printf("Pontos: %d\n", aux->item.pontos);
}

void ImprimeReverso(TipoLista lista)
{
    ImprimeReversoAux(lista.primeiro->prox);
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

apontador BuscaElemento(TipoLista lista, int chave)
{
    apontador aux = lista.primeiro->prox;

    while (aux != NULL)
    {
        if (aux->item.chave == chave)
            return aux;
        aux = aux->prox;
    }
    return NULL;
}

void InsereApos(TipoLista *lista, TipoItem item, int chaveAntecessor)
{
    if (Consulta(*lista, item.chave))
    {
        printf("\nErro: Chave duplicada nao permitida!\n");
        return;
    }

    apontador antecessor = BuscaElemento(*lista, chaveAntecessor);

    if (antecessor == NULL)
    {
        printf("\nErro: Chave do antecessor nao encontrada!\n");
        return;
    }

    apontador novo = (apontador) malloc(sizeof(Celula));
    novo->item = item;

    novo->prox = antecessor->prox;
    novo->ant = antecessor;

    if (antecessor->prox != NULL)
        antecessor->prox->ant = novo;

    antecessor->prox = novo;

    if (antecessor == lista->ultimo)
        lista->ultimo = novo;
}

void TrocarElementos(TipoLista *lista, int chave1, int chave2)
{
    if (chave1 == chave2)
    {
        printf("\nErro: As chaves sao iguais, nenhuma troca realizada.\n");
        return;
    }

    // Buscar os nós correspondentes às chaves
    apontador anterior1 = ConsultaR(*lista, chave1);
    apontador anterior2 = ConsultaR(*lista, chave2);

    if (anterior1 == NULL || anterior1->prox == NULL || anterior2 == NULL || anterior2->prox == NULL)
    {
        printf("\nErro: Uma ou ambas as chaves nao foram encontradas.\n");
        return;
    }

    apontador no1 = anterior1->prox;
    apontador no2 = anterior2->prox;

    if (no1->prox == no2) // no1 antes de no2
    {
        no1->prox = no2->prox;
        no2->ant = no1->ant;

        if (no2->prox != NULL)
            no2->prox->ant = no1;

        no2->prox = no1;
        no1->ant = no2;

        anterior1->prox = no2;
    }
    else if (no2->prox == no1) // no2 antes de no1
    {
        no2->prox = no1->prox;
        no1->ant = no2->ant;

        if (no1->prox != NULL)
            no1->prox->ant = no2;

        no1->prox = no2;
        no2->ant = no1;

        anterior2->prox = no1;
    }
    else // Não são consecutivos
    {
        apontador tempProx = no1->prox;
        apontador tempAnt = no1->ant;

        no1->prox = no2->prox;
        no1->ant = no2->ant;

        no2->prox = tempProx;
        no2->ant = tempAnt;

        if (no1->prox != NULL)
            no1->prox->ant = no1;

        if (no2->prox != NULL)
            no2->prox->ant = no2;

        anterior1->prox = no2;
        anterior2->prox = no1;
    }

    if (no1->prox == NULL)
        lista->ultimo = no1;
    if (no2->prox == NULL)
        lista->ultimo = no2;
}

void ZerarLista(TipoLista *lista)
{
    apontador aux = lista->primeiro->prox;
    apontador temp;

    while (aux != NULL)
    {
        temp = aux;
        aux = aux->prox;
        free(temp);
    }

    lista->ultimo = lista->primeiro;
    lista->primeiro->prox = NULL;
    lista->primeiro->ant = NULL;

    printf("\nLista zerada com sucesso!\n");
}

void ConsultarTimePorId(TipoLista lista, int chave)
{
    apontador aux = lista.primeiro->prox;

    while (aux != NULL)
    {
        if (aux->item.chave == chave)
        {
            printf("\nTime encontrado!\n");
            printf("Id: %d\n", aux->item.chave);
            printf("Nome: %s\n", aux->item.nome);
            printf("Pontos: %d\n", aux->item.pontos);
            return;
        }
        aux = aux->prox;
    }

    printf("\nErro: Time com ID %d nao encontrado!\n", chave);
}

void AlterarPontos(TipoLista *lista, int chave, int novosPontos)
{
    apontador no = BuscaElemento(*lista, chave);

    if (no == NULL)
    {
        printf("\nErro: Time com a chave %d nao encontrado.\n", chave);
        return;
    }

    no->item.pontos = novosPontos;

    printf("\nPontuacao do time com chave %d foi alterada para %d.\n", chave, novosPontos);
}


int main()
{
    setlocale(LC_ALL, "portuguese");
    TipoLista minhaLista;
    TipoItem itemAux;
    apontador apontadorAux;
    int op, codigo;

    criar(&minhaLista);

    do
    {
        system("cls");
        printf(" 1 - Inserir \n 2 - Consultar \n 3 - Imprimir \n 4 - Excluir \n"
             " 5 - Inserir em qualquer posicao \n 6 - Trocar Elementos \n 7 - Zerar a lista \n"
             " 8 - Imprimir Inversa \n 9 - Alterar a pontuacao de um time \n 10 - Checar se a lista esta vazia \n -1 - Sair \n\n Sua opcao: ");
        scanf("%d", &op);


        switch (op)
        {
        /*Opcao de Inserir*/
        case 1:
            printf("\nId: ");
            scanf(" %d", &itemAux.chave);
            fflush(stdin);
            printf("\nNome: ");
            scanf(" %s", &itemAux.nome);
            fflush(stdin);
            printf("\nPontuacao: ");
            scanf(" %d", &itemAux.pontos);
            Insere(&minhaLista, itemAux);
            system("Pause");
            break;
        /*Opcao de Consultar*/
        case 2:
            printf("\nInforme a chave do time a ser consultado: ");
            scanf("%d", &codigo);
            ConsultarTimePorId(minhaLista, codigo);
            system("Pause");
            break;
        /*Opcao de imprimir*/
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
        /*Opcao de Excluir*/
        case 4:
            printf("\nChave a ser excluida: ");
            scanf("%d", &codigo);
            apontadorAux = ConsultaR(minhaLista,codigo);
            if (apontadorAux == NULL)
                printf("\nNao existe elemento com o codigo informado.\n");
            else
            {
                Retira(apontadorAux, &minhaLista, &itemAux);
                printf("\nCodigo encontrado e excluido.\n");
            }
            system("Pause");
            break;
        /*Opcao inserir em qualquer posicao*/
        case 5:
            printf("\nId do antecessor: ");
            scanf("%d", &codigo);

            printf("\Id do novo item: ");
            scanf("%d", &itemAux.chave);

            fflush(stdin);
            printf("\nNome do novo item: ");
            scanf("%s", itemAux.nome);

            printf("\nPontuacao do novo item: ");
            scanf(" %d", &itemAux.pontos);

            InsereApos(&minhaLista, itemAux, codigo);
            system("Pause");
            break;
        /*Opcao para Trocar dois elementos de posição*/
        case 6:
            printf("\nInforme a chave do primeiro elemento: ");
            scanf("%d", &codigo);

            int codigo2;
            printf("\nInforme a chave do segundo elemento: ");
            scanf("%d", &codigo2);

            TrocarElementos(&minhaLista, codigo, codigo2);
            system("Pause");
            break;
        /*Opcao para Zerar a lista*/
        case 7:
            ZerarLista(&minhaLista);
            system("Pause");
            break;
        /*Opcao para imprimir a lista em ordem inversa*/
        case 8:
            if (vazia(minhaLista))
                printf("\nLista vazia!");
            else
            {
                printf("\nElementos da Lista\n");
                ImprimeReverso(minhaLista);
                system("Pause");
            }
            break;
        /*Opcao para alterar a pontuacao de um time*/
        case 9:
            printf("\nInforme a chave do time: ");
            scanf("%d", &codigo);

            printf("\nInforme a nova pontuacao: ");
            scanf("%d", &itemAux.pontos);

            AlterarPontos(&minhaLista, codigo, itemAux.pontos);
            system("Pause");
            break;
        /*Opcao para checar se a lista está vazia*/
        case 10:
            if (vazia(minhaLista)){
                printf("A lista esta vazia!\n");
            }
            else{
                printf("A lista nao esta vazia!\n");
            }
            system("Pause");
            break;

        } //SWTICH
    }
    while (op != -1);  //DO .. WHILE


    system("PAUSE");
    return 0;
} //FINALIZANDO O MAIN
