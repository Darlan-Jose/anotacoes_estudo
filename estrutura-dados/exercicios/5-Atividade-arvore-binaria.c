#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
// Código criado com base no seguinte código de árvore binária: https://gist.github.com/marcoscastro/3e4abc13dec4eddb7894
#define N 1000

/* Cada nó armazena três informações:
   nesse caso, um número (prioridade),
   id do paciente,
   nome do paciente,
   ponteiro para subárvore à direita (sad)
   e ponteiro para subárvore à esquerda (sae). */
typedef struct tree{
    int prioridade;
    int id;
    char nome[30];
    struct tree* sad;
    struct tree* sae;
}Tree;

/* A estrutura da árvore é representada por um ponteiro
   para o nó raiz. Com esse ponteiro, temos acesso aos
   demais nós. */

/* Função que cria uma árvore */
Tree* createTree(){
    return NULL; // Retorna NULL para árvore vazia
}

/* Função que verifica se uma árvore é vazia */
int treeIsEmpty(Tree* t){
    return t == NULL;
}

void showTree(Tree* t){
    if(!treeIsEmpty(t)) {
        showTree(t->sae);
        printf("Id: %d\n", t->id);
        printf("Nome: %s\n", t->nome);
        printf("Prioridade: %d\n", t->prioridade);
        printf("\n");
        showTree(t->sad);
    }
}

void insertTree(Tree** t, int prioridade, int id, char* nome){
    if (*t == NULL) {
        *t = (Tree*)malloc(sizeof(Tree));
        (*t)->sae = NULL;
        (*t)->sad = NULL;
        (*t)->prioridade = prioridade;
        (*t)->id = id;
        strcpy((*t)->nome, nome);
    } else {
        if (prioridade < (*t)->prioridade) {
            insertTree(&(*t)->sae, prioridade, id, nome);
        } else if (prioridade > (*t)->prioridade) {
            insertTree(&(*t)->sad, prioridade, id, nome);
        } else {
            if (id < (*t)->id) {
                insertTree(&(*t)->sae, prioridade, id, nome);
            } else {
                insertTree(&(*t)->sad, prioridade, id, nome);
            }
        }
    }
}

// Função para embaralhar o vetor de IDs
void embaralhar(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Função para obter um novo ID único
int obter_id_unico(int *arr, int *index) {
    if (*index < N) {
        return arr[(*index)++];
    }
    return -1;
}

Tree* busca(Tree* t, int id) {
    if (t == NULL)
        return NULL;

    if (t->id == id)
        return t;

    Tree* resultado = busca(t->sae, id);
    if (resultado != NULL)
        return resultado;

    return busca(t->sad, id);
}

void calcular_media_prioridade(Tree* t, int* soma, int* contagem) {
    if (t != NULL) {
        *soma += t->prioridade;  // Acumula a prioridade do nó
        (*contagem)++;           // Conta o nó

        calcular_media_prioridade(t->sae, soma, contagem);
        calcular_media_prioridade(t->sad, soma, contagem);
    }
}

float media_prioridade(Tree* t) {
    int soma = 0, contagem = 0;
    calcular_media_prioridade(t, &soma, &contagem);

    if (contagem == 0) {
        return 0;  // Evita divisão por zero se a árvore estiver vazia
    }

    return (float)soma / contagem;
}

int contar_pacientes(Tree* t) {
    if (t == NULL) {
        return 0;
    }

    return 1 + contar_pacientes(t->sae) + contar_pacientes(t->sad);
}

void encontrar_maior_menor_prioridade(Tree* t, int* maior, int* menor) {
    if (t == NULL) {
        return;
    }

    if (t->prioridade > *maior) {
        *maior = t->prioridade;
    }

    if (t->prioridade < *menor) {
        *menor = t->prioridade;
    }

    encontrar_maior_menor_prioridade(t->sae, maior, menor);
    encontrar_maior_menor_prioridade(t->sad, maior, menor);
}

void maior_menor_prioridade(Tree* t, int* maior, int* menor) {
    if (t == NULL) {
        printf("A árvore está vazia.\n");
        return;
    }

    *maior = t->prioridade;
    *menor = t->prioridade;

    encontrar_maior_menor_prioridade(t, maior, menor);
}

// Função auxiliar para encontrar o menor nó da subárvore
Tree* encontrar_minimo(Tree* t) {
    while (t && t->sae != NULL) {
        t = t->sae;
    }
    return t;
}

Tree* removeTree(Tree* t, int prioridade, int id) {
    if (t == NULL){
        return NULL;
    }

    if (prioridade < t->prioridade || (prioridade == t->prioridade && id < t->id)) {
        t->sae = removeTree(t->sae, prioridade, id);
    } else if (prioridade > t->prioridade || (prioridade == t->prioridade && id > t->id)) {
        t->sad = removeTree(t->sad, prioridade, id);
    } else {

        if (t->sae == NULL && t->sad == NULL) {
            free(t);
            return NULL;
        }

        else if (t->sae == NULL) {
            Tree* temp = t->sad;
            free(t);
            return temp;
        } else if (t->sad == NULL) {
            Tree* temp = t->sae;
            free(t);
            return temp;
        }

        Tree* temp = encontrar_minimo(t->sad);
        t->prioridade = temp->prioridade;
        t->id = temp->id;
        strcpy(t->nome, temp->nome);
        t->sad = removeTree(t->sad, temp->prioridade, temp->id);
    }

    return t;
}

int main(){
    setlocale(LC_ALL, "portuguese");
    int op, prioridade, id, total_pacientes, maior, menor;
    char nome[30];
    float media;

    srand(time(NULL));
    int numeros[N];
    int index = 0;

    for (int i = 0; i < N; i++) {
        numeros[i] = i + 1;
    }

    embaralhar(numeros, N);

    Tree* t = createTree();

    do {
        system("cls");
        printf("1 - Inserir um paciente\n2 - Buscar um paciente pelo id\n3 - Listar pacientes em ordem de prioridade\n"
               "4 - Calcular estatísticas\n5 - Remover um paciente\n-1 - Sair\n\nSua opcao: ");
        scanf("%d", &op);

        switch (op) {
        case 1:
                id = obter_id_unico(numeros, &index);
                if (id == -1) {
                    printf("Todos os IDs já foram usados.\n");
                    system("pause");
                    break;
                }

            do {
                printf("Digite a prioridade do paciente (entre 0 e 100): ");
                scanf("%d", &prioridade);
                if (prioridade < 0 || prioridade > 100) {
                    printf("Prioridade inválida! Deve ser um número entre 0 e 100.\n");
                }
            } while (prioridade < 0 || prioridade > 100);

            printf("Digite o nome do paciente: ");
            scanf("%s", nome);
            fflush(stdin);

            insertTree(&t, prioridade, id, nome);
            printf("Paciente inserido na árvore com ID: %d\n", id);
            system("pause");
            break;

        case 2:
            if (treeIsEmpty(t)) {
                printf("A árvore está vazia. Nenhum paciente para buscar.\n");
                system("pause");
                break;
            }

            printf("Digite o id do paciente que deseja buscar: ");
            scanf("%d", &id);
            Tree* result = busca(t, id);

            if (result != NULL) {
                printf("Paciente encontrado:\n");
                printf("Id: %d\n", result->id);
                printf("Nome: %s\n", result->nome);
                printf("Prioridade: %d\n", result->prioridade);
            } else {
                printf("Paciente com o id %d não encontrado.\n", id);
            }
            system("pause");
            break;

        case 3:
            if (treeIsEmpty(t)) {
                printf("A arvore esta vazia.\n");
                system("pause");
                break;
            }

            showTree(t);  // Exibe os pacientes em ordem de prioridade
            system("pause");
            break;

        case 4:
            if (treeIsEmpty(t)) {
                printf("A árvore está vazia. Nenhuma estatística pode ser calculada.\n");
                system("pause");
                break;
            }

            media= media_prioridade(t);
            printf("O valor da média dos nós da árvore é: %f\n", media);

            total_pacientes= contar_pacientes(t);
            printf("O número total de pacientes é: %d\n", total_pacientes);

            maior_menor_prioridade(t, &maior, &menor);
            printf("A maior prioridade registrada é: %d\n", maior);
            printf("A menor prioridade registrada é: %d\n", menor);
            system("pause");
            break;

        case 5:

            if (treeIsEmpty(t)) {
                printf("A árvore está vazia. Nenhum paciente para remover.\n");
                system("pause");
                break;
            }

            printf("Digite a prioridade do paciente a remover: ");
            scanf("%d", &prioridade);
            printf("Digite o ID do paciente a remover: ");
            scanf("%d", &id);

            Tree* temp = busca(t, id);
            if (temp == NULL || temp->prioridade != prioridade) {
                printf("Paciente com ID %d e prioridade %d não encontrado.\n", id, prioridade);
            } else {
                t = removeTree(t, prioridade, id);  // Atualiza a raiz da árvore
                printf("Paciente removido com sucesso.\n");
            }
            system("pause");
            break;
        }
    } while (op != -1);

    system("PAUSE");
    return 0;
}
