**03 de março de 2025**
# Declaração das estruturas:
```c
1typedef struct
{
  2 int chave;
  3 char nome[20];
4} TipoItem;
```
Em 1 declara-se uma `struct` com o nome `TipoItem`, como pode ser observado em 4.
Em 2 e 3, essa struct armazenara uma chave int e um nome char.

```c
1 typedef struct celula *apontador;
 
2typedef struct celula
{
  3 TipoItem item;
  4 apontador prox;
5} Celula;
```
Em 2 declara-se uma struct com nome `celula`, e um alias chamado `Celula` como pode ser visto em 5. 
Em 3 e 4, essa struct vai armazenar um `TipoItem` chamado item e um apontador (que é um ponteiro para struct celula) chamado prox.
Em 1, é criado um alias para o ponteiro de celula que é chamado apontador. Dessa forma toda vez que usarmos apontador; equivale a: `struct celula *p; ou Celula *p;` etc. 
```c
1typedef struct
{
  2 apontador primeiro, ultimo;
}3 TipoLista;
```
Em 1 declara-se umas struct chamada `TipoLista`, como pode ser visto em 3. 
Em 2, essa struct vai armazenar dois apontadores, um `primeiro` e um `ultimo`. Lembre-se que toda que vez que apontador é usado, estamos no referindo a um ponteiro para a struct celula.

# Main e o menu:
```c
int main()
{
  1 TipoLista minhaLista;
  2 TipoItem itemAux;
  3 apontador apontadorAux;
  4 int op, codigo;
 
  5 criar(&minhaLista);

6do
    {
      7 system("cls");
      8 printf(" 1 - Inserir \n 2 - Consultar \n 3 - Imprimir \n 4 - Excluir \n-1 - Sair \n\n Sua opcao: ");
        scanf("%d", &op);
        
 
      9 switch (op)
        {
        /*Opção de Inserir*/
        case 1:
		//Aqui tem o código do case
                 break;
        /*Opção de Consultar*/
        case 2:
		//Aqui tem o código do case
                        break;
        /*Opção de imprimir*/
        case 3:
		//Aqui tem o código do case
                        break;
        /*Opção de Excluir*/
        case 4:
		//Aqui tem o código do case
                        break;
        } //SWTICH
    }
  10 while (op != -1);  //DO .. WHILE
 
  11 system("PAUSE");
  12 return 0;
} //FINALIZANDO O MAIN
```

Em 1 declara-se `minhaLista` do `TipolLista`.
Em 2 o `itemAux` do `TipoItem`.
Em 3 um `apontador` chamado `ApontadorAux`.
Em 4 duas variáveis `op, codigo`.

Em 5 chama a função `criar`, para fazer a minhaLista se tornar uma lista vazia.

Em 6 e 10 existe um `do.. While`, que irá executar enquanto `op` for diferente de -1, dentro desse do.. While existe a seguinte estrutura. 

Em 7 o comando system("cls") é utilizado para limpar a tela do console.

Em 8 mostra as opções do menu, e armazena o número da opção digitada em op. 

Em 9, tem o switch case.

Em 11 é utilizado  comando `system("PAUSE")`, que mostra uma mensagem para o usuário pressionar qualquer tecla para fechar o programa.

# Função para criar lista vazia:
```c
/*Função para criar Lista Vazia*/
1void criar(TipoLista *lista)
{
  2 lista->primeiro = (apontador) malloc(sizeof(Celula));
  3 lista->primeiro->prox = NULL;
  4 lista->ultimo = lista->primeiro;
}
```
Em 1 define a função `criar`, que tem como parâmetro um  ponteiro TipoLista chamado lista.

Em 2, o `malloc` faz uma alocação de memória do tamanho de uma `Celula`, com isso o `malloc` retorna um ponteiro genérico (void*), e o trecho `(apontador)` faz a conversão desse tipo genérico para o tipo apontador (que é um apontador para struct celula). 
Com isso acessa o campo primeiro da lista (por meio de lista->primeiro), e ele  passa a armazenar um apontador para a nova célula criada. Criando assim uma célula cabeça vazia.
Essa linha cria a célula cabeça e define o primeiro ponteiro da lista para apontar para essa célula.

Em 3, acessa o campo prox da célula cabeça, e diz que ele não deve armazenar nada ainda, por meio do comando `NULL`.
`NULL` é o valor usado em ponteiros para indicar que não há próximo nó.

Em 4 acessa o campo último da lista que passa a assumir o valor de primeiro, ou seja, o último é igual ao primeiro, isso é uma forma de indicar que a lista está vazia. 

# Função para checar se a lista está vazia:
```c
/*Função que retorna 1 se a lista estiver vazia*/
1int vazia(TipoLista lista)
{
  2 if(lista.primeiro == lista.ultimo)
    {
  3     return 1;
    }
  4 return 0;
}
```
Em 1 declara-se a função `vazia` que tem como parâmetro um `TipoLista` chamado lista. 

Em 2 se o primeiro item da lista for igual ao último item da lista, significa que ela está vazia,
E em 3 faz com que retorne 1 (verdadeiro).

Em 4, caso 2 seja falso, o primeiro item da lista é diferente do último, ou seja, a lista não está vazia, retorna 0 (falso).

# Função Insere:
```c
1void Insere (TipoLista *lista, TipoItem item)
{
  2 lista->ultimo->prox = (apontador) malloc(sizeof(Celula));
  3 lista->ultimo = lista->ultimo->prox;
  4 lista->ultimo->prox = NULL;
  5 lista->ultimo->item = item;
}
```
Em 1 define-se a função chamada `Insere`, que tem como parâmetros um ponteiro `lista`, e um `TipoItem` chamado `item`. 

Em 2 ocorre o seguinte, o `malloc` aloca um espaço na memória do tamanho de `Celula`, e então devolve um ponteiro genérico, o trecho `(apontador)` é responsável por converter esse ponteiro genérico em um ponteiro do tipo apontador. Lembre-se o apontador, é um ponteiro para struct celula, com isso o ponteiro genérico devolvido por `malloc` é convertido para um ponteiro para uma nova célula alocada na memória, que podemos chamar de nó. Em 2 também acessa o apontador `ultimo` da lista e acessa o seu campo `prox`, o campo `prox` então passa a apontar para esse novo nó.

Em 3, acessa-se o campo `prox` de último, que como foi dito em 2, agora é um apontador para o no (celula) recém criado. Com isso acessa o campo último da lista e faz com que ele passe a ser o apontador para esse novo nó.
**Obs.**: Lembre-se quando digo nó, estou me referindo a struct celula.

Em 4, depois de passar o apontador do próximo nó para último, em 3, o campo prox de último passa a assumir o valor `NULL`, para indicar assim que não há próximo nó.

Em 5 acessa o campo` item` de `ultimo`, lembrando que `ultimo` é um apontador, apontador é um ponteiro para a struct celula, que tem em sua composição um `TipoItem` chamado `item`, então está acessando esse `item`. Com isso armazena o `item` (da entrada da função) no campo `item` do apontador ultimo.

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
Em 3 utiliza o `fflush(stdin);` para limpar o buffer. 
O mesmo processo é feito para o `Nome` em 4 a 6.

Em 7 chama a função `Insere` e passa para ela, como argumentos, a `minhaLista` e o `itemAux`, para que essa função insira `itemAux` na minhaLista.

# Função Imprime:
```c
1void Imprime (TipoLista lista)
{
  2 apontador aux;
  3 aux = lista.primeiro->prox;
  4 while (aux != NULL)
    {
      5 printf("Id: %d\n", aux->item.chave);
      6 printf("Nome: %s\n", aux->item.nome);
      7 aux = aux->prox;
    }
}
```
Em 1 define-se a função `Imprime` que tem como parâmetro um `TipoLista` chamado `lista`. 

Em 2 cria um `apontador` chamado `aux`. E em 3 faz com esse apontador receba o apontador `prox`, do campo primeiro da lista. 

Em 4, no laço `while`, enquanto `aux` for diferente de `NULL`, ou seja, enquanto o apontador `aux` não chegar no último elemento da lista, ele executa o resto do código. 

Lembrando que o `apontador` é a mesma coisa que `Celula *p`, ou seja, um ponteiro para struct celula. Ou seja `aux` é um ponteiro para a struct Celula referente a posição em que ele estiver no laço while.

Em 5, acessa o campo `item` da struct Celula apontada por `aux`, então acessa o campo `chave` da struct TipoItem e mostra esse valor na tela.

Em 6, acessa o campo `item` da struct Celula apontada por `aux`, então acessa o campo `nome` da strcut TipoItem e mostra esse valor na tela.

Em 7 o apontador `aux` recebe  o valor armazenado no seu campo `prox` (que é um apontador), isso faz com que `aux` passe para próximo elemento da lista. 

Demonstração do uso da função em main:
```c
int main()
{
    TipoLista minhaLista;
    TipoItem itemAux;
    apontador apontadorAux;
    int op, codigo;
 
    criar(&minhaLista);

/*Opção de imprimir*/
        case 3:
      2     if (vazia(minhaLista))
      3         printf("\nLista vazia!");
      4     else
            {
      5         printf("\nElementos da Lista\n");
      6         Imprime(minhaLista);
      7         system("Pause");
            }
            break;
```
Em 2, dentro do if chama a função `vazia`, se a mesma retorna 1 (verdadeiro), indica que a `minhaLista` está vazia, mostrando uma mensagem informando isso, em 3.

Em 4, caso o if 2 seja falso, ou seja, a lista não está vazia, executa o seguinte código:
Em 6, chama a função `Imprime`, e coloca `minhaLista` como argumento, mostrando assim os itens da lista. 

Em 7 chama o comando `pause`, para "pausar" o terminal até que o usuário digite alguma tecla.

# Função Consulta:
```c
1int Consulta (TipoLista lista, int chave)
{
  2 apontador aux;
  3 aux = lista.primeiro->prox;
  4 while (aux != NULL)
    {
      5 if (aux->item.chave == chave)
          6 return 1;
      7 aux = aux->prox;
    }
  8 return 0;
}
```
Em 1, define a função `Consulta`, que tem como parâmetros uma `lista` do TipoLista e uma `chave`. 
Em 2 cria um apontador chamado `aux`. E em 3 faz com esse apontador receba o apontador `prox`, do campo primeiro da lista.

Em 4, no laço `while`, enquanto `aux` for diferente de `NULL`, ou seja, enquanto o apontador `aux` não chegar no último elemento da lista, ele executa o resto do código.

Em 5, se, o campo` chave` do item da celula apontada por `aux`, for igual a `chave`, retorna 1, ou seja, o item em que `aux` se encontra for igual a `chave` digitada, significa que o item foi encontrado e retorna verdadeiro.

Em 7 o apontador `aux` recebe  o valor armazenado no seu campo `prox` (que é um apontador), isso faz com que `aux` passe para próximo elemento da lista.

Em 8 caso o campo `chave` do item da celula apontada por `aux `não for igual a `chave`, retorna 0, ou seja, se nenhum item que `aux` percorrer for igual a `chave` digitada, significa que nenhum item correspondente foi encontrado, retornado falso.

## Demonstração do uso da função em main:
```c
int main()
{
    TipoLista minhaLista;
    TipoItem itemAux;
    apontador apontadorAux;
    int op, codigo;
 
    criar(&minhaLista);

 /*Opção de Consultar*/
        case 2:
          1 printf("\nChave a ser consultada: ");
          2 scanf("%d", &codigo);
          3 if (Consulta(minhaLista,codigo)==0)
              4 printf("\nNao existe elemento com o codigo informado.\n");
          5 else
              6 printf("\nCodigo encontrado.\n");
          7 system("Pause");
            break;
```
Em 1 e 2 pergunta a `chave` a ser consultada, e armazena o valor digitado em `codigo`.

Em 3, dentro do if chama a função `Consulta`, caso o valor retornado por ela seja igual a 0, ou seja, ela não encontrou nenhum elemento com o código informado, mostra uma mensagem informando isso, em 4. 

Em 5, caso o if de 3 seja falso, ou seja, diferente de zero, indica que o código foi encontrado, e mostra uma mensagem informando isso em 6.

Em 7 chama o comando `pause`, para "pausar" o terminal até que o usuário digite alguma tecla.

# Função ConsultaR (Consultar para Remoção):
```c
1apontador ConsultaR (TipoLista lista, int chave)
{
  2 apontador aux, anterior;
  3 anterior = lista.primeiro;
  4 aux = lista.primeiro->prox;
  5 while (aux != NULL)
    {
      6 if (aux->item.chave == chave)
      7     return anterior;
      8 anterior = aux;
      9 aux = aux->prox;
    }
  10 return NULL;
}
```
Em 1 declara a função `ColsutarR`, que tem como parâmetros `lista` do TipoLista, e `chave`. Essa função retorna valores do tipo apontador, ou seja, um ponteiro para alguma Celula.

Em 2 cria dois apontadores `aux e anterior`. 

Em 3 o apontador `anterior`, recebe o apontador `primeiro` da lista. 

Em 4 o apontador `aux` recebe o apontador `prox` que é um campo do apontador `primeiro` da lista. Ou seja, o ponteiro para alguma Celula recebe o ponteiro que indica a próxima Celula do primeiro elemento da lista.

Em 5, no laço `while`, enquanto `aux` for diferente de `NULL`, ou seja, enquanto o apontador `aux` não chegar no último elemento da lista, ele executa o resto do código.

Em 6 se a chave do `item` da Celula apontada por `aux` for igual a chave, retorna o apontador `anterior`, ou seja, retorna o ponteiro da Celula anterior, em 7.

Com isso em 8 o apontador `anterior` fica igual ao apontador `aux`, isso faz com que anterior agora se torne o antigo apontador `aux`.

Em 9 o apontador `aux` recebe o valor do seu apontador `prox`, isso faz com que aux passe para próximo elemento da lista. 

Em 10 se toda a lista for percorrida e o elemento com a `chave` correspondente a chave da entrada da função não for encontrado, vai retornar `NULL`. 

# Função Retira:
```c
1void Retira (apontador p, TipoLista *lista, TipoItem *item)
{
  2 /*o item a ser retirado é o seguinte apontado por p*/
  3 apontador q;
  4 if (vazia(*lista) || p==NULL || p->prox==NULL)
    {
      5 printf("Erro: Lista vazia ou posicao nao existe");
      6 return;
    }
  7 q = p->prox;
  8 *item = q->item;
  9 p->prox = q->prox;
  10 if (p->prox == NULL)
      11 lista->ultimo = p;
  12 free(q);
}
```
Em 1 declara-se a função `Retira`, que tem como parâmetros um apontador `p`, um ponteiro *lista do TipoLista, e um ponteiro `*item` do TipoItem.

Em 3 declara-se uma apontador chamado `q`. 

Em 4, existe a verificação de várias condições:
-`vazia(*lista)` Chama a função `vazia` para o ponteiro da lista, se ele retorna 1 (Verdadeiro), ou seja, a lista está vazia, mostra uma mensagem informando isso.
**OU**
-`p==NULL` Se `p` for igual a `NULL`, ou seja, se a posição de `p` não estiver dentro do intervalo, retorna verdadeiro, ou seja, a posição é inválida, então mostra uma mensagem informando isso.
**OU**
-`p->prox==NULL` Se o apontador `prox` de `p` for igual a `NULL`, ou seja, não existe nenhum item válido depois de `p`, retorna Verdadeiro, com isso mostra uma mensagem informando isso.

Caso nenhuma das condições de 4 tenham sido satisfeitas, executa o código fora das chaves do if, que é.

Em 7, o apontador `q` recebe o apontador `prox` de `p`. Ou seja, a Celula apontada por q recebe a Celula que está sendo apontada por `prox` do apontador `p`, que é o item a ser retirado.

Em 8 o ponteiro de `item` recebe o `item` da Celula que está sendo apontada por `q`. 

Em 9, o campo `prox` do apontador `p` vai receber o campo `prox` do apontador `q`. Como o apontador p é um ponteiro para Celula, o que ocorre é que o campo da Celula `p` passa a apontar para o mesmo nó que vem depois da Celula `q`. Isso permite remover a referência de `q`, quebrando-a, podendo assim remover efetivamente o apontador `q` da lista, sem prejudicar a lista.

Em 10, se o o apontador prox de `p` for igual a `NULL`, ou seja, não existir nenhum nó após `p`, irá ocorrer o seguinte.

&emsp;&emsp;Em 11, caso a condição de 10 seja verdadeira, o apontador último passa a apontar para o apontador `p`, que é o novo último.

Em 12 a memória alocada para o apontador `q` é liberada, ou seja, a memória alocada para a Celula apontada por `q` é liberada.

#### Demonstração do uso da função em main:
```c
int main()
{
    TipoLista minhaLista;
    TipoItem itemAux;
    apontador apontadorAux;
    int op, codigo;
 
    criar(&minhaLista);

/*Opção de Excluir*/
        case 4:
         1  printf("\nChave a ser excluida: ");
         2  scanf("%d", &codigo);
         3  apontadorAux = ConsultaR(minhaLista,codigo);
         4  if (apontadorAux == NULL)
              5 printf("\nNao existe elemento com o codigo informado.\n");
          6 else
            {
             7  Retira(apontadorAux, &minhaLista, &itemAux);
             8  printf("\nCodigo encontrado.\n");
            }
          9 system("Pause");
            break;
```
Em 1 e 2, pede para que informe a chave a ser excluída, e armazena o valor em `codigo`. 

Em 3 chama a função `ConsultarR` que recebe como argumentos a lista `minhaLista`, e `codigo` informado pelo usuarío, a informação que `ConsultarR`` retornar vai ser armazenada em `apontadorAux`. 

Em 4 caso `apontadorAux` seja igual a `NULL`, ou seja, `ConsultarR` não encontrou o código informado, mostra uma mensagem informando isso, em 5.

Em 6, caso contrário a 4, ou seja, o `apontadorAux` é diferente de `NULL`, com a função `ConsultarR` tendo encontrado um valor válido, vai executar o seguinte código.
&emsp;&emsp;Em 7 chama a função `Retira` e define os argumentos dela como o `apontadorAux`, a lista `minhaLista` e o TipoItem `itemAux`, e mostra a mensagem código encontrado, em 8.

Em 9 chama o comando `pause`, para "pausar" o terminal até que o usuário digite alguma tecla.


