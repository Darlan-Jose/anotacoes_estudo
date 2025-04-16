**11 de março de 2025**

**Implementação da lista duplamente encadeada em C, o mesmo código é bastante parecido com código da lista encadeada, então serão descritos somente os blocos de códigos que forem diferentes.**

#  Declaração das estruturas:
```c
1typedef struct celula *apontador;
 
2typedef struct celula
{
  3 TipoItem item;
  4 apontador prox;
  5 apontador ant;
6} Celula;
```
Em 2 declara-se uma struct com nome `celula`, e um alias chamado `Celula` como pode ser visto em 6.

Em 3 essa struct vai armazenar um `TipoItem` chamado `item`. E em 4 e 5, vai armazenar dois apontadores (que é um ponteiro para struct celula), chamados, respectivamente, `` prox e ant`.

Em 1, é criado um alias para o ponteiro de celula que é chamado apontador. Dessa forma toda vez que usarmos apontador; equivale a: struct celula *p; ou Celula *p; etc.

As outras estruturas são as mesmas do outro código, então estão aqui: [Declaração da estruturas](https://github.com/Darlan-Jose/anotacoes_estudo/blob/main/estrutura-dados/conteudo-teorico/ParteII-ListasEncadeadasPorPonteiro.md#declara%C3%A7%C3%A3o-das-estruturas)

# Main e o menu:
[Main e o menu](https://github.com/Darlan-Jose/anotacoes_estudo/blob/main/estrutura-dados/conteudo-teorico/ParteII-ListasEncadeadasPorPonteiro.md#main-e-o-menu)

# Função para criar lista vazia:
```c
/*Função para criar Lista Vazia*/
1void criar(TipoLista *lista)
{
  2 lista->primeiro = (apontador) malloc(sizeof(Celula));
  3 lista->primeiro->prox = NULL;
  4 lista->primeiro->ant = NULL;
  5 lista->ultimo = lista->primeiro;
}
```

Em 1 define a função `criar`, que tem como parâmetro um  ponteiro `TipoLista` chamado `lista`.

Em 2, o `malloc` faz uma alocação de memória do tamanho de uma `Celula`, com isso o `malloc` retorna um ponteiro genérico (void*), e o trecho `(apontador)` faz a conversão desse tipo genérico para o tipo apontador (que é um apontador para struct celula). 
Com isso acessa o campo primeiro da lista (por meio de lista->primeiro), e ele  passa a armazenar um apontador para a nova célula criada. Criando assim uma célula cabeça vazia.
Essa linha cria a célula cabeça e define o primeiro ponteiro da lista para apontar para essa célula.

Em 3, acessa o campo `prox` da célula cabeça, e diz que ele não deve armazenar nada ainda, por meio do comando `NULL`.
`NULL` é o valor usado em ponteiros para indicar que não há próximo nó.

Em 4, acessa o campo `ant` da célula cabeça, e também diz que ele não deve armazenar nada ainda, por meio do comando `NULL`.

Em 5 acessa o campo `último` da lista que passa a assumir o valor de `primeiro`, ou seja, o último é igual ao primeiro, isso é uma forma de indicar que a lista está vazia.

# Função para verificar se a lista está vazia:
[Função para checar se a lista está vazia](https://github.com/Darlan-Jose/anotacoes_estudo/blob/main/estrutura-dados/conteudo-teorico/ParteII-ListasEncadeadasPorPonteiro.md#fun%C3%A7%C3%A3o-para-checar-se-a-lista-est%C3%A1-vazia)

# Função Insere:
```c
1void Insere (TipoLista *lista, TipoItem item)
{
  2 lista->ultimo->prox = (apontador) malloc(sizeof(Celula));
  3 lista->ultimo->prox->ant = lista->ultimo;
  4 lista->ultimo = lista->ultimo->prox;
  5 lista->ultimo->prox = NULL;
  6 lista->ultimo->item = item;
}
```
Em 1 define-se a função chamada `Insere`, que tem como parâmetros um ponteiro `lista`, e um `TipoItem` chamado `item`. 

Em 2 ocorre o seguinte, o `malloc` aloca um espaço na memória do tamanho de `Celula`, e então devolve um ponteiro genérico, o trecho `(apontador)` é responsável por converter esse ponteiro genérico em um ponteiro do tipo apontador. Lembre-se o apontador, é um ponteiro para struct celula, com isso o ponteiro genérico devolvido por malloc é convertido para um ponteiro para uma nova célula alocada na memória, que podemos chamar de nó. Em 2 também acessa o apontador `ultimo` da lista e acessa o seu campo `prox`, o campo `prox` então passa a apontar para esse novo nó. Que é  nó seguinte. 
**Obs.**: Agora, a struct celula possui um apontador prox e um apontador ant.

Em 3, em `lista->ultimo->prox->ant` acessa o apontador `ant`, do campo `prox` do apontador último da lista, e então armazena nele o apontador último da lista (lista->ultimo). 

**Primeira explicação:** Ou seja, acessa o campo `ant` da celula seguinte a último, que foi a nova celula alocada em 2, e faz com que ela aponte para o seu antecessor que é último, isso é feito para que a nova celula saiba quem é o seu antecessor, que é o apontador `ultimo` antes da inserção ocorrer. 

**Segunda Explicação:** Essa linha faz com que o apontador `ant` do campo `prox` passe a apontar para o nó que está antes dele, ou seja, o que era a última celula (que estava no apontador ultimo) antes da criação desse novo nó (celula), já que esse novo nó (celula) passa a ser o último nó (celula) da lista.

Em 4, acessa-se o campo `prox` de `último`, que como foi dito em 2, agora é um apontador para o nó (celula) recém criado. Com isso acessa o campo último da lista, e faz com que ele passe a ser o apontador para esse novo nó.

Em 5, depois de passar o apontador do próximo nó para último, em 4, o campo `prox` de `último` passa a assumir o valor `NULL`, para indicar assim que não há próximo nó.

Em 6 acessa o campo `item` de `ultimo`, lembrando que `ultimo` é um apontador, apontador é um ponteiro para a struct celula, que tem em sua composição um `TipoItem` chamado `item`, então está acessando esse `item`. Com isso armazena o `item` (da entrada da função) no campo item do apontador `ultimo`.

## Demonstração do uso da função em main:
```c
int main()
{
    TipoLista minhaLista;
    TipoItem itemAux;
    apontador apontadorAux;
    int op, codigo;
 
    criar(&minhaLista);

/*Opção de Inserir*/
        case 1:
          1 printf("\nChave: ");
          2 scanf(" %d", &itemAux.chave);
          3 fflush(stdin);
          4 printf("\nNome: ");
          5 scanf(" %s", &itemAux.nome);
          6 fflush(stdin);
          7 Insere(&minhaLista, itemAux);
            break;
```
Em 1 e 2 pede o valor da chave, com o valor digitado sendo armazenado no campo `chave` de `itemAux`. 
Em 3 utiliza o `fflush(stdin)`; para limpar o buffer. 
O mesmo processo é feito para o `Nome` em 4 a 6.

Em 7 chama a função `Insere` e passa para ela, como argumentos, a `minhaLista` e o `itemAux`, para que essa função insira `itemAux` na minhaLista.

As outras funções continuam a mesma coisa e apresentam o mesmo funcionamento, [Parte II – Lista Encadeada por Ponteiro](https://github.com/Darlan-Jose/anotacoes_estudo/blob/main/estrutura-dados/conteudo-teorico/ParteII-ListasEncadeadasPorPonteiro.md#fun%C3%A7%C3%A3o-imprime) ler a partir da função Imprime. 



