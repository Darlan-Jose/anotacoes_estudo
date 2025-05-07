**28 de março de 2025**

# Enunciado:
Modifique a fila dinâmica que você implementou em exercícios anteriores para armazenar as informações desses processos. 
```c
{
    id = 104,
    name = "Firefox",
    priority = 4,
    wait = 20
}
```
Seu programa deverá permitir através do menu:
- Incluir novos processos na fila de processo:
- Incrementar o tempo de todos os processos em 1 a cada novo processo incluído na fila;           
- Matar o processo com o maior tempo de espera;
- Executar um processo (remover da fila):
- Deduzir o tempo de todos os processos em 1 a cada novo processo executado, tratar para não ficar abaixo de 1;    
- Imprimir o conteúdo da fila de processos.

# Declaração das estruturas:
```c
1typedef struct {
2   int id;
3   char name[20];
4   int priority;
5   int wait;
6} TipoItem;
```
Em 1 declara-se uma struct com o nome TipoItem, como pode ser observado em 6.

Em 2, 3, 4 e 5 essa struct armazenara uma id (int), nome (char), uma priority (int) e um wait (int).
```c
1typedef struct celula *apontador;
 
2typedef struct celula {
3   TipoItem item;
4   apontador prox;
5} celula;
```
 
Em 2 declara-se uma struct com nome celula, e um alias  chamado celula como pode ser visto em 5. Em caso de dúvida: Por que isso funciona?
Em 3 e 4, essa struct vai armazenar um TipoItem chamado item e um apontador (que é um ponteiro para struct celula) chamado prox.

Em 1, é criado um alias para o ponteiro de celula que é chamado apontador. Dessa forma toda vez que usarmos apontador; equivale a: struct celula *p;. 

```c
1typedef struct {
2    apontador primeiro;
3} TipoFila;
```

# [Main e o Menu:](https://github.com/Darlan-Jose/anotacoes_estudo/blob/main/estrutura-dados/conteudo-teorico/1-ParteII-Listas-Encadeadas-Por-Ponteiro.md#main-e-o-menu)
O menu continua basicamente o mesmo do citado acima, com a adição de mais opções no printf, que são:
Obs.: As particularidades de alguns cases serão citados juntos com suas respectivas funções:
```c
printf(" 1 - Incluir novo processo\n 2 - Executar um processo\n 3 - Matar um processo com maior tempo\n"
               " 4 - Imprimir filas\n -1 - Sair\n\n Sua opcao: ");
```
# [Função criar](https://github.com/Darlan-Jose/anotacoes_estudo/blob/main/estrutura-dados/exercicios/2-Fila-de-prioridade.md#fun%C3%A7%C3%A3o-criar)

# Função vazia:
```c
1int vazia(TipoFila fila) {
2   return (fila.primeiro->prox == NULL);
}
```
1 declaração da função e dos seus parâmetros. 
Em 2, verifica se a fila está vazia, ou seja, se o apontador prox de ponteiro é igual a NULL. Se sim, vai retornar 1 (verdadeiro), indicando que a fila está vazia, se não retorna 0 (falso) indicando que a fila não está vazia.

# Função enfileirar:
```c
1void enfileirar(TipoFila *fila, TipoItem item) {
2   if (verificarID(*fila, item.id)) {
3       printf("O id do item já está na lista\n");
4       return;
5   } else {
        // Incrementa o tempo de todos os processos já na fila
6       apontador aux = fila->primeiro->prox;
7       while (aux != NULL) {
8           aux->item.wait += 1;  // Incrementa o tempo de espera de cada processo
9           aux = aux->prox;
        }
 
10      // Enfileira o novo processo
11      apontador novo = (apontador)malloc(sizeof(celula));
12      if (novo == NULL) {
13          printf("Erro ao alocar memoria\n");
14          exit(1);
        }
15      novo->item = item;
16      novo->prox = NULL;
 
        // Vai até o final da fila e insere o novo processo
17      aux = fila->primeiro;
18      while (aux->prox != NULL) {
19          aux = aux->prox;
        }
20      aux->prox = novo;
21      printf("Processo inserido com sucesso!\n");
    }
}
```

Em 1, define a assinatura da enfileirar, que recebe como parâmetros um ponteiro para uma estrutura do tipo TipoFila e uma estrutura do tipo TipoItem. O propósito dessa função é adicionar um novo item na fila.

Em 2, a função verificarID é chamada para verificar se o id do item que está sendo enfileirado já existe na fila.

Em 3, caso o id do item já exista na fila, a mensagem será impressa, indicando que o id já está na lista.

Em 4, se o id já estiver na fila (caso em que a função verificarID retornaria um valor verdadeiro), a função enfileirar retorna sem enfileirar o item.

Em 5, caso o id não exista na fila (ou seja, a verificação retornou falso), o bloco de código dentro do else será executado para adicionar o item à fila.

Em 6 é criado o apontador aux, que é responsável por receber o primeiro elemento da fila, ou seja, aux recebe o campo prox do apontador primeiro da fila.

No while em 7, enquanto aux for diferente de NULL, ou seja, enquanto aux não chegar no final da fila, executa os seguintes códigos.

Enquanto  7 for verdadeiro, em 8, incrementa o tempo de espera (wait) de todos os processos, ou seja, acessa o campo wait de item do apontador aux e soma-se 1.
E em 9, aux recebe o ponteiro seguinte a ele, ou seja, aux recebe o apontador prox dele mesmo.

Em 11, é alocada dinamicamente memória para um novo elemento da fila, e o apontador novo recebe esse novo elemento.

Das linhas de 12 a 14, verifica se a alocação de memória falhou, se sim, mostra uma mensagem informando esse erro, em 13, e encerra o programa com o comando exit, em 14.

Em 15, se a alocação tiver ocorrido de forma normal, armazena o item inserido pelo usuário no novo apontador, ou seja, acessa o campo item do apontador novo e armazena item nele.

Em 16, atualiza o apontador prox do novo item para NULL, indicando que não há item depois dele, ou seja, acessa o campo prox do apontador novo e iguala ele a NULL.

 Em 17, o apontador aux recebe o primeiro item da fila. 
No while em 18, verifica se o campo prox de aux é diferente de NULL, ou seja, enquanto aux não chegar no último elemento da fila.
Enquanto 18 for executado, aux recebe o item seguinte a ele, ou seja, aux recebe o apontador prox dele mesmo. 

Em 20, depois de aux estar no final da fila, coloca o novo elemento no final da fila, ou seja, o campo prox de aux recebe novo.
E em 21 mostra uma mensagem dizendo que o item foi inserido com sucesso.

# Função imprimir:
Possui o mesmo princípio de funcionamento de: [Função imprimir](https://github.com/Darlan-Jose/anotacoes_estudo/blob/main/estrutura-dados/exercicios/2-Fila-de-prioridade.md#fun%C3%A7%C3%A3o-imprimir), com a mudança do conteúdo que vai ser impresso. 

# Função desenfileirar:
```c
1apontador desenfileirar(TipoFila *fila) {
2   if (vazia(*fila)) {
3       printf("A fila esta vazia!!!\n");
4       return NULL;
    }
 
5   apontador aux = fila->primeiro->prox;
6   fila->primeiro->prox = aux->prox;
7   return aux;
}
```

1 ocorre a declaração da função e dos seus respectivos parâmetros.

De 2 a 4 checa se a fila está vazia, se sim mostra uma mensagem informando isso em 3, e encerra a execução da função em 4.

Em 5 cria-se o apontador aux, que vai receber o primeiro item válido da fila, ou seja, vai receber o campo prox do apontador primeiro da fila.

Em 6, o novo primeiro item da fila passa agora a ser o item que vinha depois do antigo primeiro, o antigo segundo, ou seja, o campo prox do apontador primeiro da fila recebe o campo prox do apontador aux. 

Em 7 retorna aux para que ele seja liberado (free) dentro do case da chamada dessa função.

# Função verificarID:
Funciona como a [Função buscar](https://github.com/Darlan-Jose/anotacoes_estudo/blob/main/estrutura-dados/exercicios/2-Fila-de-prioridade.md#fun%C3%A7%C3%A3o-buscar), mas sem o tratamento se a fila está vazia.

# [Função zerar](https://github.com/Darlan-Jose/anotacoes_estudo/blob/main/estrutura-dados/exercicios/2-Fila-de-prioridade.md#fun%C3%A7%C3%A3o-zerar)

# Função matarProcessoMaiorWait:
```c
1apontador matarProcessoMaiorWait(TipoFila *fila) {
2   if (vazia(*fila)) {
3       printf("A fila esta vazia!\n");
4       return NULL;
    }
 
5   apontador aux = fila->primeiro->prox;
6   apontador maiorWait = aux;
7   apontador anterior = fila->primeiro;
 
    // Percorre a fila para encontrar o processo com maior tempo de espera
8   while (aux != NULL) {
9       if (aux->item.wait > maiorWait->item.wait) {
10          maiorWait = aux;
11          anterior = fila->primeiro;
12          while (anterior->prox != maiorWait) {
13              anterior = anterior->prox;
            }
        }
14      aux = aux->prox;
    } 

    // Remove o processo com maior tempo de espera da fila
15  anterior->prox = maiorWait->prox;
 
    // Retorna o processo removido
16  return maiorWait;
}
```

1 declaração da função e o seu respectivo parâmetro.

De 2 a 4 chega se a fila está vazia, se sim mostra uma mensagem informando isso em 3, e encerra a execução da função em 4.

Em 5 cria-se o apontador aux que vai receber o primeiro item válido da fila, ou seja,  o campo prox do apontador primeiro da fila.

Em 6 cria-se o apontador maiorWait vai receber o maior valore conhecido até o momento, o primeiro item, que no momento é aux, ou seja, maiorWait vai receber aux.

Em 7 cria-se o apontador anterior, que no momento receber o apontador primeiro da fila.

No while em 8, aux vai percorrer a fila até chegar no final, ou seja, enquanto aux for diferente de NULL.

Enquanto o while é executado em 8, em 9 verifica se o wait do item em que aux se encontra é maior que o wait armazenado em maiorWait, ou seja, verifica se o campo wait do campo item do apontador aux é maior que o campo wait do campo item do apontador maiorWait.

Se 9 for verdadeiro, ou seja, wait de aux for maior que MaiorWait:
Em 10, maiorWait passa a assumir o valor da aux.

Em 11, fazemos com que o anterior receba o primeiro elemento da fila, ou seja, anterior recebe o apontador primeiro da fila. Isso é feito para preparar para percorrer a fila de novo e encontrar o item que antecede o item com o maiorWait,  já que em alguma momento vamos excluir esse item com o maiorWait.

No while em 12 e 13, vai percorrer novamente toda a fila para encontrar o item anterior ao item que tem maiorWait, ou seja, enquanto o apontador prox de anterior for diferente de maiorWait.
Na linhas 13 ocorre a troca de valores para o percorrimento da fila, ou seja, anterior recebe o seu campo prox.

Na linha 14, é a lógica responsável por percorrer a fila, caso o item com maiorWait não tenha sido encontrado ainda, aux vai receber o seu próximo, ou seja, aux recebe o seu campo prox. 

Em 15, ocorre o remoção do item com o maiorWait da fila, da seguinte forma, o item anterior a ele passa a apontar para o item seguinte a ele, ou seja, o campo prox do apontador anterior recebe  o campo prox de maiorWait

Em 16 retorna maiorWait, que o item a ser removido da fila, ele será liberado (free) dentro do case em main.

# Função executarProcesso:
```c
// Função para executar um processo (FIFO) e reduzir o tempo de espera
1void executarProcesso(TipoFila *fila) {
2   if (vazia(*fila)) {
3       printf("A fila está vazia! Não há processos para executar.\n");
4       return;
    }
 
5   apontador aux = desenfileirar(fila);  // Remove o primeiro processo da fila
 
    // Reduz o tempo de espera de todos os processos na fila (nao permitindo que o wait fique menor que 0)
6   apontador auxProcesso = fila->primeiro->prox;
7   while (auxProcesso != NULL) {
8       if (auxProcesso->item.wait > 1) {
9           auxProcesso->item.wait -= 1;
        }
10      auxProcesso = auxProcesso->prox;
    }
 
    // Exibe o processo que foi executado
11  printf("Processo com ID %d executado. Nome: %s\n", aux->item.id, aux->item.name);
 
    // Libera a memória do processo removido
12  free(aux);
}
```

1 ocorre a declaração da função e do seu parâmetro. 

De 2 a 4 chega se a fila está vazia, se sim mostra uma mensagem informando isso em 3, e encerra a execução da função em 4.

Em 5 cria-se o apontador aux, que vai chamar a função desenfileirar para remover o 1° processo da fila, desenfileirar então vai retornar o item a ser removido, esse processo então será armazenado em aux. 

Em 6 criasse o apontador auxProcesso que vai receber o primeiro item válido da fila, ou seja, vai receber o campo prox do apontador primeiro da fila.

Em 7, enquanto auxProcesso não chegar no final da fila executa os códigos seguintes, ou seja, enquanto auxProcesso for diferente de NULL.

Em 8, verifica se o campo wait de item do auxProcesso é maior que 1, se sim, decrementa esse mesmo campo em 1.

Em 10, é a lógica responsável por percorrer a fila, ou seja, auxProcesso recebe o apontador próximo dele mesmo.

Em 11, mostra uma mensagem informando o processo que foi "executado".

Em 12 libera (free) aux, que foi o item que foi retirado da fila usando a função desenfileirar.
