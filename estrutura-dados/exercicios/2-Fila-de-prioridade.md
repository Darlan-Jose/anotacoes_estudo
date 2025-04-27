18 de março de 2025

# Enunciado:
**Atividade sobre Fila de Prioridade**

As instituições financeiras geralmente utilizam dois tipos de fila, uma normal e uma chamada de preferencial. Dessa forma, foi solicitado a você que implementasse um algoritmo para controlar a chamada de pessoas da fila. Assim, a implementação de FILA Encadeada deve ser modificada para possuir duas filas e haverá duas funções para inserção na fila.

- Fila_Enfileira_Normal(Fila, x): insere o item x no final da fila normal
- Fila_Enfileira_Preferencial(Fila, x): insere o item x no final da fila preferencial
- No entanto, deverá existir apenas uma função para desenfileirar e seu funcionamento deve ser da seguinte forma:
  A cada 2 pessoas desenfileiradas da fila preferencial, a próxima deve ser desenfileirada da normal.
Se uma das filas estiver vazia, deve-se chamar da fila que ainda possuir elementos.

- Inclua uma nova informação na fila para guardar as senhas dos clientes.
- O programa deverá ter um menu com as opções:
1. Enfileirar na fila normal (senha gerada automaticamente pelo algoritmo)
2. Enfileirar na fila prioritária (senha gerada automaticamente pelo algoritmo)
3. Desenfileirar
4. Imprimir as filas
5. Sair

# Declaração das estruturas:
```c
1typedef struct {
 2  int id;
 3  char nome[20];
 4  int senha;
5} TipoItem;
```
Em 1 declara-se uma `struct` com o nome `TipoItem`, como pode ser observado em 5.

Em 2, 3 e 4, essa `struct` armazenara uma `id (int)`, `nome (char)` e uma `senha (int)`.

```c
1typedef struct celula *apontador;
 
2typedef struct celula {
 3  TipoItem item;
 4  apontador prox;
5} celula;
```
Em 2 declara-se uma `struct` com nome `celula`, e um alias  chamado `celula` como pode ser visto em 5.
Em 3 e 4, essa `struct` vai armazenar um `TipoItem` chamado item e um apontador (que é um ponteiro para `struct celula`) chamado `prox`.

Em 1, é criado um alias para o ponteiro de celula que é chamado `apontador`. Dessa forma toda vez que usarmos apontador; equivale a: `struct celula *p;`. 
```c
1typedef struct {
 2  apontador primeiro;
3} TipoFila;
```

Em 1 declara-se umas `struct` chamada `TipoFila`, como pode ser visto em 3. 
Em 2, essa `struct` vai armazenar um apontador chamado `primeiro`. Lembre-se que toda que vez que apontador é usado, estamos nos referindo a um ponteiro para a `struct celula`.

# Função criar:
```c
1void criar(TipoFila *fila) {
  2 fila->primeiro = (apontador)malloc(sizeof(celula));
  3 if (fila->primeiro == NULL) {
  4     printf("Erro ao alocar memória\n");
  5     exit(1);
    }
  6 fila->primeiro->prox = NULL;
}
```
Em 1, define uma função chamada `criar`, que recebe um parâmetro `fila`, do `TipoFila`, em forma de ponteiro.
O propósito dessa função é inicializar uma  fila encadeada alocando memória para a primeira célula.

Em 2, função `malloc` aloca dinamicamente memória para um objeto do tipo `celula`. A alocação é feita para o tamanho de uma célula (`sizeof(celula)`).
O ponteiro `fila->primeiro` é então atualizado para apontar para o espaço de memória alocado.


Em 3, é feita uma verificação para saber se a alocação de memória foi bem-sucedida. Se `malloc` não conseguir alocar a memória, ele retornará `NULL`.
Se fila->primeiro for `NULL`, significa que a alocação falhou.

Em 4, se a verificação em 3 for verdadeira (ou seja, a alocação falhou), a mensagem "Erro ao alocar memória" é impressa no console.

Em 5 a função `exit(1)` termina a execução do programa com um código de erro 1. Isso indica que algo deu errado (neste caso, a alocação de memória falhou) e o programa não pode continuar.

Em 6, estamos inicializando o campo `prox` (de uma célula fila) com `NULL`.
O campo  representa o próximo nó da fila (ou seja, o ponteiro para o próximo elemento). Inicializá-lo com `NULL` indica que a fila está vazia no momento em que a estrutura foi criada, pois não há outros elementos após o primeiro.

# Função vazia:
```c
1int vazia(TipoFila fila){
2   if(fila.primeiro->prox == NULL){
3       return 1;
    }
4   return 0;
}
```

Em 1 declara-se a função `vazia`, que tem como parâmetros um `TipoFila` chamado `fila`.

No `if`, em 2, verifica se o campo `prox` de primeiro da lista é igual a `NULL`, ou seja, se não existe nenhum elemento na lista, se for verdadeiro retorna 1 (verdadeiro), em 3, indicando que a lista está vazia.

Em 4, caso 2 seja falso, ou seja, `prox` de primeiro é diferente de `NULL`, indicando que a lista não está vazia, retorna 0 (falso), indicando que a lista não está vazia.

# Função Fila_Enfileira_Normal:
```c
1void Fila_Enfileira_Normal(TipoFila *fila, TipoItem item) {
2   if (verificarID(*fila, item.id)) {
3       printf("O id do item já está na lista\n");
4       return;
5   }else{
      6 apontador aux = fila->primeiro;
      7 while (aux->prox != NULL) {
      8     aux = aux->prox;
        }
 
      9 apontador novo = (apontador)malloc(sizeof(celula));
      10 if (novo == NULL) {
      11     printf("Erro ao alocar memória\n");
      12     exit(1);
        }
     13 novo->item = item;
     14 novo->prox = NULL;
     15 aux->prox = novo;
    }
}
```
Em 1, define a assinatura da função `Fila_Enfileira_Normal`, que recebe como parâmetros um ponteiro para uma estrutura do tipo `TipoFila` e uma estrutura do tipo `TipoItem`. O propósito dessa função é adicionar um novo item na fila.

Em 2, a função `verificarID` é chamada para verificar se o id do item que está sendo enfileirado já existe na fila.

Em 3, caso o id do item já exista na fila, a mensagem será impressa, indicando que o id já está na lista.

Em 4, se o id já estiver na fila (caso em que a função `verificarID` retornaria um valor verdadeiro), a função `Fila_Enfileira_Normal` retorna sem enfileirar o item.

Em 5, caso o id não exista na fila (ou seja, a verificação retornou falso), o bloco de código dentro do `else` será executado para adicionar o item à fila.

Em 6, é criado um ponteiro `aux` que inicialmente aponta para o primeiro elemento da fila, acessado via `fila->primeiro`. Esse ponteiro será usado para percorrer a fila até o final.

Esse `while`, em 7, percorre a fila até encontrar o último elemento. A condição `aux->prox != NULL` verifica se o próximo elemento na fila (`aux->prox`) é nulo, ou seja, se o próximo elemento a `aux` não é válido.

Em 8, dentro do laço `while`, o ponteiro `aux` é movido para o próximo elemento da fila (ou seja, vai "andando" pela fila até chegar no último item).

Em 9, é alocada dinamicamente memória para um novo elemento da fila, e o ponteiro `novo` recebe esse novo elemento.

Das linhas de 10 a 12, verifica se a alocação de memória falhou, se sim, mostra uma mensagem informando esse erro, em 11, e encerra o programa com o comando `exit`, em 12.


Em 13, o item que foi passado para a função (via parâmetro item) é copiado para o campo item da célula novo. Isso significa que o novo item será inserido na fila.

Em 14, como o novo item será o último da fila, o ponteiro `prox` da célula novo é configurado para `NULL`, indicando que não há mais elementos após este.

Em 15, o ponteiro `prox` do último elemento da fila (`aux`) é ajustado para apontar para o novo elemento (`novo`). Isso adiciona o novo item no final da fila, e atualiza a referência do elemento que antes era o último da fila (`aux`) para apontar para o novo último, que é `novo`.

# Função Fila_Enfileira_Preferencial:
```c
1void Fila_Enfileira_Preferencial(TipoFila *fila, TipoItem item) {
2    if (verificarID(*fila, item.id)) {
3        printf("O id do item já está na lista\n");
4        return;
5    }else{
6        apontador aux = fila->primeiro;
7        while (aux->prox != NULL) {
8            aux = aux->prox;
        }
 
9        apontador novo = (apontador)malloc(sizeof(celula));
10        if (novo == NULL) {
11            printf("Erro ao alocar memória\n");
12            exit(1);
        }
13        novo->item = item;
14        novo->prox = NULL;
15        aux->prox = novo;
    }
}
```

O mesmo processo de [Função Fila_Enfileira_Normal](https://github.com/Darlan-Jose/anotacoes_estudo/edit/main/README.md#fun%C3%A7%C3%A3o-fila_enfileira_normal) só que para a Fila_Preferencial.

# Função imprimir:
```c
1void imprimir(TipoFila fila) {
2   if (vazia(fila)==1) {
3       printf("A fila está vazia!!!\n");
4       return;
5   }else{
6       apontador aux = fila.primeiro->prox;
7       while (aux != NULL) {
8           printf("Id: %d\n", aux->item.id);
            printf("Nome: %s\n", aux->item.nome);
            printf("Senha: %d\n", aux->item.senha);
10           printf("\n");
11           aux = aux->prox;
        }
    }
}
```

1 declaração da função.

Em 2 a 4 checa-se a fila está vazia, se for verdadeiro informa isso e encerra a execução da função.

Em 5, se 2 for positivo, executa o restante do código.

Em 6 cria um apontador `aux` que recebe o nome da fila.
No `while` em 7, enquanto `aux` não chegar no final da fila, executa os seguintes comandos. 

De 8 a 10 mostra as informações do item em que `aux` se encontra na fila.

Em 11, faz com que `aux` fique passando para o próximo elemento, percorrendo assim a fila. 

# Função buscar:
```c
// Retorna: 1 se encontrar; 0 se não encontrar; -1 se estiver vazia
1int buscar(TipoFila fila, int id) {
2   if (vazia(fila)==1) {
3       printf("A fila está vazia\n");
4       return -1;
5   }else{
6       apontador aux = fila.primeiro->prox;
7       while (aux != NULL) {
8           if (aux->item.id == id) {
9               return 1;
            }
11           aux = aux->prox;
        }
12       return 0;
    }
}
```

1 declaração da função.

Em 2 a 4 checa-se a fila está vazia, se for verdadeiro informa isso e retorna -1, para indicar que a lista está vazia.

Em 5, se o 2 indicar que a fila não está vazia, executa o restante do código.

Em 6, `aux` recebe o começo da fila.
Em 7, enquanto `aux` não chegar no final da fila executa os seguintes comandos. 
Em 8 verifica se o id de `aux` é igual ao id procurado, se sim retorna 1.

Em 11, `aux` recebe o próximo elemento depois dele.

Em 12, caso `aux` chegue no final da fila sem encontrar o item, retorna 0.

# Função desenfileirar:
```c
1apontador desenfileirar(TipoFila *filaNormal, TipoFila *filaPreferencial, int *contadorPreferencial) {
2   apontador removido = NULL;
 
    // Primeiro, tente desenfileirar da fila preferencial
3   if (!vazia(*filaPreferencial) && *contadorPreferencial < 2) {
4       removido = filaPreferencial->primeiro->prox;
5       filaPreferencial->primeiro->prox = removido->prox;
6       (*contadorPreferencial)++;
7       return removido;
    }
 
    // Se 2 itens foram desenfileirados da fila preferencial, desenfileire da fila normal
8   if (*contadorPreferencial >= 2) {
9       if (!vazia(*filaNormal)) {
10           removido = filaNormal->primeiro->prox;
11           filaNormal->primeiro->prox = removido->prox;
12           *contadorPreferencial = 0;  // Resetar o contador de preferencial após desenfileirar da normal
13           return removido;
14       } else {
15           printf("A fila normal está vazia!\n");
        }
    }
 
    // Caso a fila preferencial tenha 2 itens desenfileirados, mas nao tenha mais itens
16   if (vazia(*filaPreferencial) && !vazia(*filaNormal)) {
17       removido = filaNormal->primeiro->prox;
18       filaNormal->primeiro->prox = removido->prox;
19       return removido;
    }
 
    // Caso uma das filas esteja vazia, desenfileire da fila que ainda possui itens
20   if (!vazia(*filaPreferencial)) {
21       removido = filaPreferencial->primeiro->prox;
22       filaPreferencial->primeiro->prox = removido->prox;
23       (*contadorPreferencial)++;
24       return removido;
25   } else if (!vazia(*filaNormal)) {
26       removido = filaNormal->primeiro->prox;
27       filaNormal->primeiro->prox = removido->prox;
28       return removido;
    }
 
    // Caso ambas as filas estejam vazias
29   printf("Ambas as filas estão vazias!\n");
30   return NULL;
}
```

Em 1 declaração da função.

Em 3, `!vazia(*filaPreferencial)`: Esta expressão verifica se a fila preferencial não está vazia. A função `vazia()` retorna 1 se a fila estiver vazia e 0 caso contrário, mas a negação ! inverte esse valor. Ou seja, se a fila não estiver vazia, o teste será verdadeiro.
`*contadorPreferencial < 2`: Verifica se o contador da fila preferencial é menor que 2, se sim (verdadeiro), e a outra condição  também for verdadeira executa o resto da porção de código. 
O `if`, em 3, garante que o código dentro do bloco só será executado se a fila preferencial não estiver vazia e se o contador for menor que 2.

Em 4, o ponteiro `removido` (declarado em 2) vai receber o primeiro item válido da fila, ou seja, vai receber o campo `prox` do apontador primeiro da `filaPreferencial`.

Em 5, o item seguinte a removido passa agora a ser o item seguinte a primeiro da fila, ou seja, o campo `prox` do apontador `primeiro` da fila recebe o apontado `prox` de `removido`. Com isso `removido` agora realmente estará sendo "removido" da fila, com isso é necessário que o apontador `primeiro` seja atualizado para apontador para o novo próximo item da fila (o que vem depois de removido). 

Em 6 incrementa em 1 o `contadorPreferencial`, já que ele é responsável por armazenar quantos itens da preferencial foram tirados, se ele chegar em 2 tira da fila normal.

Em 7 retorna `removido` (que está apontado para o item que foi removido da fila), retorna ele pois ele será liberado em main, por meio do comando `free`.

No `if` em 8, checa se dois itens já foram desenfileirados da fila preferencial, ou seja, se `contadorPreferencial` é maior ou igual 2.

No `if` em 9, verifica se a `filaNormal` não está vazia, por meio da negação do retorno da função vazia, se ela não estiver vazia executa a seguinte porção de código.

Em 10, 11 e 13 é o mesmo processo das linhas 4, 5 e 7.

Em 12 reseta o `contadorPreferencial` para indicar que pode retirar itens da `filaPreferencial` novamente, ou seja, iguala o valor de `contadorPreferencial` a 0.

Em 14 e 15, caso a condição de 9 seja falsa, ou seja, a fila está vazia, mostra uma mensagem informando isso.

Em 16, primeiro verifica se a `filaPreferencial` está vazia, na segunda parte (depois do `&&`) verifica se a `filaNormal` não está vazia, com isso o código dentro do if só será executado se a `filaPreferencial` estiver vazia e a `filaNormal` ainda tiver itens.

Em 17, 18 e 19 segue o mesmo processo de remoção das linhas 4, 5 e 7, para a `filaNormal`.

No `if` em 20, checa se a `filaPreferencial` não está vazia. Se ela não estiver vazia executa o código dentro do `if`.

Se 20 for verdadeira, Em 21, 22, 23, e 24, segue o mesmo processo das linhas 4, 5, 6 e 7.

No `else if` em 25, caso em 20 a `filaPreferencial` esteja vazia, ou seja, a condição do `if` não foi satisfeita, em 25 verifica se a `filaNormal` não está vazia.
Caso a fila normal ainda possui itens, nas linhas 26, 27 e 28 executa o código para remoção de itens, que é o mesmo processo de 10, 11 e 13.

Em 29 e 30, caso a `filaPreferencial` e a `filaNormal` esteja vazias, ou seja, as condições de 20 e 25 não foram satisfeitas, mostra uma mensagem informando isso em 29, e retorna `NULL` em 30.

# Função verificarID:
```c
1int verificarID(TipoFila fila, int id) {
2   apontador aux;
3   aux = fila.primeiro->prox;
4   while (aux != NULL) {
5       if (aux->item.id == id) {
6           return 1;
        }
7       aux = aux->prox;
    }
8   return 0;
}
```

1 declaração da função.

Funciona como a função buscar, sem o tratamento para fila vazia.
[Função buscar](https://github.com/Darlan-Jose/anotacoes_estudo/edit/main/README.md#fun%C3%A7%C3%A3o-buscar)

# Função zerar:
```c
1void zerar(TipoFila *fila){
2   apontador excluir, aux;
3   aux = fila->primeiro;
4   while(fila->primeiro->prox!=NULL){
5       desenfileirar(fila, fila, NULL);
6       free(aux);
    }
7   criar(fila);
}
```

1 declaração da função.

Em 2 cria-se o apontador `aux`.

Em 3 `aux` vai receber o apontador `primeiro` da fila.

Em 4, enquanto não chegar no final da fila, ou seja, o campo `prox` do apontador `primeiro` da fila for diferente de `NULL`, executa os seguintes comandos.

Em 5 chama a função `desenfileirar`, e passa os argumentos fila e `NULL` para ela.
E em 6 libera o apontador `aux`, por meio do comando `free`, realmente excluindo o elemento da memória.

Em 7 chama-se a função `criar`, para ela criar uma nova fila, que por padrão será uma fila zerada.

