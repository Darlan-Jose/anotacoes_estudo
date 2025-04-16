**15 de março de 2025**

# Enunciado:
Lista Duplamente Encadeada
Você precisa criar uma forma para armazenar os times de um Campeonato de Futebol em um software de computador com: Id, Nome do Time e Total de Pontos que aceite um número indeterminado de times. Você decidiu usar uma lista duplamente encadeada para isso e precisa implementar algumas funções em seu sistema:
- Criar a lista;
- Verificar se a lista está vazia;
- Inserir um time no final da lista verificando antes se o ID já existe;
- Inserir um item em qualquer posição da lista. Usuário informará o Id do item que será o antecessor do novo item, verificar antes se o ID já existe.
- Consultar um time pelo Id;
- Remover um time da lista;
- Trocar um time com outro informando os Ids;
- Imprimir as informações da lista na ordem padrão;
- Imprimir as informações da lista na ordem invertida;
- Alterar a pontuação de um time localizando-o pelo Id;
- Zerar a lista;

# Declaração das estruturas:
```c
1typedef struct
{
2   int chave;
3   char nome[20];
4   int pontos;
5} TipoItem;
 
6typedef struct celula *apontador;
 
7typedef struct celula
{
8   TipoItem item;
9   apontador prox;
10  apontador ant;
11} Celula;
 
12typedef struct
{
13  apontador primeiro, ultimo;
14} TipoLista;
```
As estruturas continuam sendo as mesmas do seguinte código: [Declaração das estruturas](https://github.com/Darlan-Jose/anotacoes_estudo/blob/main/estrutura-dados/conteudo-teorico/2-ParteII-Implementa%C3%A7%C3%A3o-Duplamente-Encadeada.md#declara%C3%A7%C3%A3o-das-estruturas), o mesmo código, com a adição do campo para armazenar pontos (inteiro), na linha 4. 


# [Main e o Menu:](https://github.com/Darlan-Jose/anotacoes_estudo/blob/main/estrutura-dados/conteudo-teorico/1-ParteII-Listas-Encadeadas-Por-Ponteiro.md#main-e-o-menu) 
O menu continua basicamente o mesmo do citado acima, com a adição de mais opções no printf, que são:
```c
printf(" 1 - Inserir \n 2 - Consultar \n 3 - Imprimir \n 4 - Excluir \n"
             " 5 - Inserir em qualquer posicao \n 6 - Trocar Elementos \n 7 - Zerar a lista \n"
             " 8-Imprimir Inversa \n 9 - Alterar a pontua  o de um time \n 10 - Checar se a lista est  vazia \n -1 - Sair \n\n Sua opcao: ");
```
# [Função criar](https://github.com/Darlan-Jose/anotacoes_estudo/blob/main/estrutura-dados/conteudo-teorico/1-ParteII-Listas-Encadeadas-Por-Ponteiro.md#fun%C3%A7%C3%A3o-para-criar-lista-vazia)

**Demonstração do uso da função em main:**
```c
        case 10:
1           if (vazia(minhaLista)){
2               printf("A lista esta vazia!\n");
            }
3           else{
4               printf("A lista nao esta vazia!\n");
            }
5           system("Pause");
            break;
```

No `if` em 1, chama-se a função `vazia` e passa para ela como argumento a lista para checar se está vazia `(minhaLista)`, se a função retorna 1 (verdadeiro), mostra uma mensagem informando que a lista está vazia em 2, se a função retorna 0 (falso), entra no `else` em 3, e mostra uma mensagem informando que a lista não está vazia em 4.

Em 5 chama o comando `pause`, para "pausar" o terminal até que o usuário digite alguma tecla.


# [Função checar se a lista está vazia](https://github.com/Darlan-Jose/anotacoes_estudo/blob/main/estrutura-dados/conteudo-teorico/1-ParteII-Listas-Encadeadas-Por-Ponteiro.md#fun%C3%A7%C3%A3o-para-checar-se-a-lista-est%C3%A1-vazia)

# [Função Consulta](https://github.com/Darlan-Jose/anotacoes_estudo/blob/main/estrutura-dados/conteudo-teorico/1-ParteII-Listas-Encadeadas-Por-Ponteiro.md#fun%C3%A7%C3%A3o-consulta)

# Função Insere:
 ```c
1void Insere(TipoLista *lista, TipoItem item)
{
  2 if (Consulta(*lista, item.chave))
    {
      3 printf("\nErro: Chave duplicada nao permitida!\n");
      4 return;
    }
 
  5 lista->ultimo->prox = (apontador) malloc(sizeof(Celula));
    lista->ultimo->prox->ant = lista->ultimo;
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->prox = NULL;
  9 lista->ultimo->item = item;
}
 ```

Em 2, dentro do `if`, chama-se a função `Consulta` e passa para ela como argumentos o `ponteiro lista`, e o campo `chave` do `item`, a função `Consulta` retorna 1 (verdadeiro) se o item for encontrado e 0 (falso) se o item não for encontrado. Caso a condição em 2 seja verdadeira, ou seja, a função `Consulta` encontrou esse item na lista, imprime uma mensagem dizendo que não permite-se chave duplicada (em 3), e encerra a execução da função, em 4.

Caso contrário, ou seja, o item não foi encontrado na lista, executa o seguinte código: [Função Insere](https://github.com/Darlan-Jose/anotacoes_estudo/blob/main/estrutura-dados/conteudo-teorico/2-ParteII-Implementa%C3%A7%C3%A3o-Duplamente-Encadeada.md#fun%C3%A7%C3%A3o-insere)

# [Função Imprime:](https://github.com/Darlan-Jose/anotacoes_estudo/blob/main/estrutura-dados/conteudo-teorico/1-ParteII-Listas-Encadeadas-Por-Ponteiro.md#fun%C3%A7%C3%A3o-imprime)
Com a alteração para mostrar o campo pontos. 

# Função ImprimeReverso:
```c
1void ImprimeReversoAux(apontador aux)
{
  2 if (aux == NULL)
  3     return; // Condição de parada
 
  4 ImprimeReversoAux(aux->prox); // Chamada recursiva primeiro
 
  5 printf("Id: %d\n", aux->item.chave);
  6 printf("Nome: %s\n", aux->item.nome);
  7 printf("Pontos: %d\n", aux->item.pontos);
}
 
8void ImprimeReverso(TipoLista lista)
{
  9 ImprimeReversoAux(lista.primeiro->prox);
}
```

Em 8 define-se a função `ImprimeReverso` e o seus parâmetros. 

Em 9 chama-se a função `ImprimeReversoAux`, passando para ela como parâmetro o campo `pro`x do apontador `primeiro` da lista, ou seja, passa a primeira celula válida para a função `ImprimeReversoAux`. 

Em 1 define-se a função `ImprimeReversoAux` e o seus parâmetros.
`ImprimeReversoAux` é uma função recursiva.

Em 4, `ImprimeReversoAux` chama a si mesmo, passando como parâmetro o apontador `prox` (próxima celula) de aux (celula atual). 

Em 2 e 3 existe a condição de parada, que quando `aux` for igual a `NULL`, ou seja, quando `aux` não for uma celula válida, a `função ImprimeReversoAux` para de ser chamada. Com essa "parada", pelo fato de ser uma função recursiva, `ImprimeReversoAux` volta a partir do ponto de parada (`NULL`) executando sua função principal, que é imprimir os dados de um time (linhas 5 a 7), com isso ela imprime a lista de trás para frente.

Enquanto a função recursiva é chamada, de 5 a 7 mostra as informações de cada time (id, nome e pontos).

**Demonstração do uso da função em main:**
```c
        /*Opção para imprimir a lista em ordem inversa*/
        case 8:
1           if (vazia(minhaLista))
2               printf("\nLista vazia!");
3           else
            {
4               printf("\nElementos da Lista\n");
5               ImprimeReverso(minhaLista);
6               system("Pause");
            }
            break;
```
No `if` em 1, chama-se a função `vazia` passando como argumento a `minhaLista`, caso `vazia` retorne 1, ou seja a lista está vazia, mostra uma mensagem informando isso, caso contrário, a lista não está vazia, vai para o `else` em 3. 

Dentro do `else` em 3:
Em 4, mostra uma mensagem.
	
No caso em que o 3 for verdadeiro, em 5 chama a função `ImprimeReverso` e passa como argumento `minhaLista`, com essa função então mostrando os elementos da lista em ordem inversa em que foram inseridos. 
	
No caso em que o 3 for verdadeiro, em 6 chama o comando `pause`, para "pausar" o terminal até que o usuário digite alguma tecla.

# [Função ConsultarR](https://github.com/Darlan-Jose/anotacoes_estudo/blob/main/estrutura-dados/conteudo-teorico/1-ParteII-Listas-Encadeadas-Por-Ponteiro.md#fun%C3%A7%C3%A3o-consultar-consultar-para-remo%C3%A7%C3%A3o)

# [Função Retira](https://github.com/Darlan-Jose/anotacoes_estudo/blob/main/estrutura-dados/conteudo-teorico/1-ParteII-Listas-Encadeadas-Por-Ponteiro.md#fun%C3%A7%C3%A3o-retira)

# Função BuscaElemento:
```c
1apontador BuscaElemento(TipoLista lista, int chave)
{
 2  apontador aux = lista.primeiro->prox;
 
 3  while (aux != NULL)
    {
     4  if (aux->item.chave == chave)
     5      return aux; // Retorna o próprio nó
     6  aux = aux->prox;
    }
  7 return NULL;
}
```
Em declara-se a função `BuscaElemento` que tem como parâmetros uma `lista (TipoLista)` e uma `chave (inteiro)`.

Em 2 o apontador `aux` recebe o apontador `prox` do apontador `primeiro` da lista, ou seja, o apontador `aux` passa a apontar para a célula que o apontador `prox` apontava, ou seja, para a celula seguinte. 

No laço while em 3, enquanto aux for diferente de NULL executa o resto do código, ou seja, enquanto aux não chegar na última celula válida executa o resto do código. 

Enquanto o laço while de 3 for executado, em 4 verifica se o campo chave do campo item do apontador aux é igual a chave que foi digitada pelo usuário, se sim, retorna o apontador aux, em 5. Ou seja, quando o apontador aux chegar na celula que está sendo procurada (que é identificada pela chave) vai retorna essa célula que está sendo apontada por aux, com isso para a execução da função.

Em 6, enquanto o laço while tiver sendo executado, e a condição em 4 não tiver sido verdadeira, aux recebe a celula apontada pelo apontador prox de aux, ou seja, aux então assume o valor do apontador seguinte a ele, agora apontando para a celula que vinha depois dele.

Em 7, caso o while tenha sido executado até aux ser igual a NULL, retorna NULL, ou seja, caso o while tenha percorrida toda a lista e o if em 4, não tenha encontrado uma celula com chave de item correspondente, significa que o item com a chave digitada não existe, então retorna-se NULL.

# Função InsereApos:
```c
1void InsereApos(TipoLista *lista, TipoItem item, int chaveAntecessor)
{
 2  if (Consulta(*lista, item.chave)) 
    {
     3  printf("\nErro: Chave duplicada nao permitida!\n");
     4  return;
    }
 
 5  apontador antecessor = BuscaElemento(*lista, chaveAntecessor);
 
 6  if (antecessor == NULL) 
    {
     7  printf("\nErro: Chave do antecessor nao encontrada!\n");
     8  return;
    }
 
 9  apontador novo = (apontador) malloc(sizeof(Celula));
 10  novo->item = item;
 
 11  novo->prox = antecessor->prox;
 12  novo->ant = antecessor;
 
 13  if (antecessor->prox != NULL)
	{
       14 antecessor->prox->ant = novo;
     }
  15 antecessor->prox = novo;
 
  16 if (antecessor == lista->ultimo)
  17     lista->ultimo = novo;
}
```

Em 1 define a função `InsereApos`, que tem como parâmetro um ponteiro para `lista (TipoLista)`, um `item (TipoItem)` e uma `chaveAntecessor (inteiro)`. 

Em 2, dentro do `if`, chama-se a função `Consulta` e passa para ela como argumentos o ponteiro `lista`, e o campo chave do item, a função `Consulta` retorna 1 (verdadeiro) se o item for encontrado e 0 (falso) se o item não for encontrado. Caso a condição em 2 seja verdadeira, ou seja, a função Consulta encontrou esse item na lista, imprime uma mensagem dizendo que não permite-se chave duplicada (em 5),encerra a execução da função, em 4.

Caso a condição de 2 seja falsa, ou seja, a chave não é um duplicata, executa o resto do código abaixo.
  
Em 5 cria o apontador `antecessor` que vai chamar e receber o retorna da função `BuscaElemento`, e passa para ela como argumentos o ponteiro `lista`, e a `chaveAntecessor` (a chave do antecessor).
`BuscaElemento` vai procurar o apontador para celula que tenha chave igual a `chaveAntecessor`, se ela encontrar esse apontador, então vai retornar esse apontador, se ela não encontrar esse apontador, ela vai retorna `NULL`. O apontador que `BuscaElemento` retornar vai ser armazenado em `antecessor (apontador)`.

No `if`, em 6, checa se o `antecessor` tem valor igual a `NULL`, ou seja, `BuscaElemento` procurou o apontador com o item correspondente e não o encontrou, retornando `NULL` para antecessor. Com isso o antecessor informado pelo usuário não existe, e em 7 mostra uma mensagem informando isso, e então encerra a execução da função `InsereApos` em 8. 

Em 9, aloca-se uma celula na memória e cria uma apontador para ela, com esse apontador sendo chamado `novo`.
Em 10 acessa- o campo item do apontador `novo`, e então armazena nele o novo item digitado pelo usuário. 

Em 11, faz com que o campo `prox` do apontador `novo` receba o campo `prox` do apontador `antecessor`. Como o apontador `novo` (a novo celula) vai ficar na frente do apontador `antecessor` (da celula antecessor) o `prox` dele (apontador novo) deve apontar para o item que vinha depois do `antecessor`, antes deste `novo` aparecer. 

Em 12, faz com que o campo `ant` do apontador `novo` receba o apontador `antecessor`, ou seja, o apontador `ant` de `novo` passa a apontar para o `antecessor`.

No `if`, em 13, verifica se o campo `prox` de `antecessor` é diferente de `NULL`, ou seja, verifica se o `antecessor` está apontando para alguma outra celula `válida`. Se sim executa o seguinte código. 

Se a condição de 13 for verdadeira, em 14 acessa o campo `ant` do campo `prox` do apontador `antecessor`, e armazena nesse campo (`ant`) o apontador `novo`. Isso faz com que a celula que era seguinte ao `antecessor`, agora aponte para o seu novo antecessor que é a celula novo (apontador `novo)`.

Em 15 acessa o campo `prox` do `antecessor` e armazena o apontador `novo` nele, ou seja, agora o apontador `prox` de `antecessor` aponta para a nova celula que foi criada (que vem depois do `antecessor`), com isso `antecessor` aponta para seu novo sucessor que é a nova celula.

No `if`, em 16, se o apontador `antecessor` for igual ao campo `ultimo` da lista, ou seja, se o `antecessor` for a última celula da lista, executa o seguinte código. 

Se 16 for verdadeiro, em 17, faz com que o campo `ultimo` da lista receba o apontador `novo`, ou seja, como a nova celula (`novo`) vem depois do `antecessor`, e `antecessor` é o último item da lista, o apontador `novo` tem que se tornar o novo último da lista, e é isso que acontece em 17.

**Demonstração do uso da função em main:**
```c
/*Opção inserir em qualquer posição*/
        case 5:
1           printf("\nChave do antecessor: ");
2           scanf("%d", &codigo);
 
3           printf("\nChave do novo item: ");
4           scanf("%d", &itemAux.chave);
 
5           fflush(stdin);
6           printf("\nNome do novo item: ");
7           scanf("%s", itemAux.nome);
 
8           InsereApos(&minhaLista, itemAux, codigo);
9           system("Pause");
            break;
```

Em 1 e 2 pede para o usuário inserir a chave do item que ele deseja que seja o antecessor do item novo que ele deseja inserir, e armazena na variável `codigo`. 

Em 3 e 4 pede para o usuário digitar a chave do novo item, e armazena no campo `chave` de `itemAux`. 

Em 5, limpa o buffer da entrada do teclado.

Em 6 e 7 pede para o usuário inserir o nome desse novo item, e armazena no campo `nome` de `itemAux`.

Em 8 chama a função `InsereApos` e passa a lista para inserir o novo item `(minhaLista)`, passa o item que vai ser inserido `(itemAux)`, e o código do item antecessor `(codigo)`.

Em 9 chama o comando `pause`, para "pausar" o terminal até que o usuário digite alguma tecla.

# Função TrocarElementos:
```c
1void TrocarElementos(TipoLista *lista, int chave1, int chave2)
{
  2 if (chave1 == chave2)
    {
      3 printf("\nErro: As chaves sao iguais, nenhuma troca realizada.\n");
      4 return;
    }
 
    // Buscar os nós correspondentes às chaves
  5 apontador anterior1 = ConsultaR(*lista, chave1);
  6 apontador anterior2 = ConsultaR(*lista, chave2);
 
  7 if (anterior1 == NULL || anterior1->prox == NULL || anterior2 == NULL || anterior2->prox == NULL)
    {
      8 printf("\nErro: Uma ou ambas as chaves nao foram encontradas.\n");
      9 return;
    }
 
  10 apontador no1 = anterior1->prox;
  11 apontador no2 = anterior2->prox;
 
    // Se os elementos são consecutivos, tratamos separadamente
  12 if (no1->prox == no2) // no1 antes de no2
    {
      13 no1->prox = no2->prox;
      14 no2->ant = no1->ant;
 
      15 if (no2->prox != NULL)
          16 no2->prox->ant = no1;
 
      17 no2->prox = no1;
      18 no1->ant = no2;
 
      19 anterior1->prox = no2;
    }
  20 else if (no2->prox == no1) // no2 antes de no1
    {
      21 no2->prox = no1->prox;
      22 no1->ant = no2->ant;
 
     23  if (no1->prox != NULL)
          24 no1->prox->ant = no2;
 
     25  no1->prox = no2;
     26  no2->ant = no1;
 
      27 anterior2->prox = no1;
    }
  28 else // Não são consecutivos
    {
        // Troca os ponteiros dos nós
      29 apontador tempProx = no1->prox;
      30 apontador tempAnt = no1->ant;
 
      31 no1->prox = no2->prox;
      32 no1->ant = no2->ant;
 
     33 no2->prox = tempProx;
     34  no2->ant = tempAnt;
 
      35 if (no1->prox != NULL)
          36 no1->prox->ant = no1;
 
      37 if (no2->prox != NULL)
          38 no2->prox->ant = no2;
 
      39 anterior1->prox = no2;
      40 anterior2->prox = no1;
    }
 
    // Atualiza a referência do último elemento se necessário
  41 if (no1->prox == NULL)
        lista->ultimo = no1;
  42 if (no2->prox == NULL)
      43 lista->ultimo = no2;
}
```
Em 1 declara-se a função `TrocarElementos`, que tem como parâmetros um ponteiro `lista (TipoLista)`, uma `chave1 (inteiro)` e uma `chave2 (inteiro)`.

No `if`, em 2, verifica se `chave1` é igual a `chave2`, ou seja, se as chaves digitadas são iguais, se sim mostra uma mensagem informando isso, em 3, e interrompe a execução da função em 4. 

Em 5, cria-se o apontador `anterior1`, que vai ser responsável por chamar e armazenar o resultado da função `ConsultaR`, e se passa os argumentos `lista (TipoLista)` e `chave1 (inteiro)`. Se a função `ConsultaR` encontrar o item com a chave correspondente, ela vai retorna um ponteiro para o nó anterior àquele que contém a chave procurada, que vai ser armazenado no apontador `anterior1`, se ela (`ConsultaR`) não encontrar nada vai retorna `NULL`. 

Em 6, é o mesmo processo da linha 5, só que para o apontador `anterior2`, e passa como argumento `chave2 (inteiro)`.

No `if`, em 7, ocorre diversas verificações que são as seguintes:
Se `anterior1` for igual a `NULL`, ou seja, se `ConsultaR` não tiver encontrado o item.

OU

Como `anterior1` é antecessor a chave procurada é necessário observar se o seu apontador `prox` também não está vazio, se `prox` estiver vazio significa que a celula com a chave procurada não existe.

OU 

Se `anterior2` for igual a `NULL`, ou seja, se `ConsultaR` não tiver encontrado o item.

OU

Como `anterior2` é antecessor a chave procurada é necessário observar se o seu apontador `prox` também não está vazio, se `prox` estiver vazio significa que a celula com a chave procurada não existe.

Ou seja, se alguma ou nenhuma das chaves procuradas tenha sido encontrada, em 8, mostra uma mensagem informando isso e encerra a execução da função `TrocarElementos` em 9. 

Como foi dito acima, `anterior1` e `anterior2` são celulas anteriores as células que estão sendo procuradas, então na hora de manipular as celulas procuradas é necessário pegar a celula que é posterior a esse valor.
Então em 10 cria-se o apontador `no1` que vai receber o campo `prox` do apontador `anterior1`, ou seja, `no1` vai ser o apontador da celula seguinte a `anterior1`, que a que estamos procurando. 

Em 11 ocorre o mesmo processo para `no2`, só que para o apontador `anterior2`.

Em 12, checa se o campo `prox` de `no1` é igual a `no2`, ou seja, se `no1` vem antes de `no2`, se sim executa o seguinte código.

Em 13 o campo `prox` de `no1` recebe o campo `prox` de `no2`, ou seja, agora `no1` aponta para a próxima celula que era apontada por `no2`. 
Em 14 o campo `ant` de `no2` recebe o campo `ant` de `no1`, ou seja, `no2` agora aponta para a celula que era anterior a `no1`.
O processo dessas duas linhas, atualiza as referências (apontador `prox` e `ant`) de `no1` e `no2`, para prepara-los para uma futura troca.

No `if`, em 15, verifica se o campo prox de `no2` é diferente de `NULL`, ou seja, se aponta para uma celula válida, se sim executa o seguinte código. 

Caso o `if` de 15 seja verdadeiro, em 16, acessa o campo `ant` do campo `prox` de no2 e faz com que ele receba `no1`, ou seja, faz com que a celula seguinte a `no2` passe agora a apontar para `no1`, já que `no1` vai para a posição de `no2`.

Já que `no1` vai para a posição de `no2`.

Em 17, o campo `prox` de `no2` passa a apontar para `no1`, ou seja, `no2` agora aponta para o seu seguinte que é `no1`.
Em 18, o campo `ant` de `no1` passa a apontar para `no2`, ou seja, `no1` agora aponta para seu antecessor que é `no2`. 

Em 19 acessa o campo `prox` do apontador `anterior1` e armazena `no2`, ou seja, atualiza o `anterior1` para que ele aponte para a sua nova celula seguinte que é `no2`. 

No `else if`, em 20, verifica uma condição parecida com a condição de 12, mas nesse caso, verifica se o campo `prox` de `no2` é igual a `no1`, ou seja, se `no2` vem antes de `no1`, se sim executa o seguinte código. 
**Obs.**: As operações a seguir serão bastantes semelhantes as operações do bloco `if` (linhas 12 a 19).

Em 21, `no2` aponta para a próxima celula que era apontada por `no1`.
Em 22, `no1` agora aponta para a celula que era anterior a `no2`.

Em 23, verifica se o campo `prox` de `no1` é diferente de `NULL`, ou seja, se aponta para uma celula válida, se sim executa o seguinte código.

Caso o `if` de 23 seja verdadeiro, em 24, faz com que a celula seguinte a `no1` passe agora a apontar para `no2`, já que `no2` vai para a posição de `no1`.

Em 25, `no1` agora aponta para o seu seguinte que é `no2`.
Em 26, `no2` agora aponta para seu antecessor que é `no1`.

Em 27,  acessa o campo prox do apontador `anterior2` e armazena `no1`, ou seja, atualiza o `anterior1` para que ele aponte para a sua nova celula seguinte que é `no1`.

O `else` de 28 só será executado se as condições de 12 e 20 não forem verdadeiras, ou seja `no1` e `no2` não serem consecutivos de nenhuma forma. 

Em 29 cria-se o apontador `tempProx` que vai ser responsável por armazenar o campo `prox` de `no1`, ou seja, armazenar o apontador para a próxima celula de `no1`. 

Em 30, cria-se o apontador `tempAnt`, que vai ser responsável por armazenar o campo `ant` de `no1`, ou seja, armazenar o apontador para a celula anterior a `no1`.

Em 31 o campo `prox` de `no1` vai receber o campo `prox` de `no2`, ou seja, `no1` agora vai apontar para a celula que era próxima a `no2`. 
Em 32 o campo `ant` de `no1` vai receber o campo `prox` de `no2`, ou seja, `no1` agora vai apontar para a celula que vinha antes de `no2`. 

Em 33 o campo `prox` de `no2` recebe o apontador `tempProx`, que era o antigo `prox` de `no1`, ou seja, `no2` agora aponta para a celula que era próxima a `no1`. 
 
Em 34 o campo `prox` de `no2` recebe o apontador `temAnt`, que era o antigo `ant` de `no1`, ou seja, `no2` agora aponta para a celula que vinha antes de `no1`.

Com isso, em 33 e 34, as referêncis de `no1` e `no2` são preparadas/atualizadas para as suas futuras posições. 

No `if`, em 35, se o campo `prox` de `no1` for difernte de NULL, ou seja, apontar para uma celula válida, executa o seguinte código. 

Em 36, se 35 for verdadeiro, o campo `ant` do campo `prox` de `no1` recebe `no1`, ou seja, a celula seguinte a `no1` que apontava para o que era antes `no2`, agora passa a apontar para `no1`.

Em 37 e 38 é o mesmo processo de 35 e 36, só que para o apontador `no2`. Ou seja, a celula seguinte a `no1` que possivelmente apontava para `no1`, agora passa a apontar para `no2`. 

Em 39, atualiza o campo `prox` de `anterior1` para apontar para `no2`, ou seja, `anterior1` que antes da troca vinha antes de `no1`, e apontava para o mesmo, agora aponta para `no2`, já que eles foram trocados. 

Em 40, atualiza o campo prox de `anterior2` para apontar para `no1`, ou seja, `anterior2` que antes da troca vinha antes de `no2`, e apontava para o mesmo, agora aponta para `no1`, já que eles foram trocados.

As próximas linhas serão executadas somente se forem necessários, ou seja, as trocas ocorreram com últimos elementos da lista.

No `if`, em 41, se o campo `prox` de `no1` for igual a `NULL`, o campo `ultimo` de lista recebe `no1`, ou seja, atualiza o último apontador da lista para armazenar `no1`, que é o novo último.

Em 42, ocorre o mesmo processo da linha 41 só que para `no2`.

**Demonstração do uso da função em main:**
```c
/*Opcao para Trocar dois elementos de posição*/
        case 6:
1           printf("\nInforme a chave do primeiro elemento: ");
2           scanf("%d", &codigo);
 
3           int codigo2;
4           printf("\nInforme a chave do segundo elemento: ");
5           scanf("%d", &codigo2);
 
6           TrocarElementos(&minhaLista, codigo, codigo2);
7           system("Pause");
8           break;
```

Em 1 e 2 pede para o usuário informar a chave do primeiro elemento a ser trocado, e armazena o resultado na variável `codigo` (inteiro).

Em 3 a 5, pede para o usuário informar chave do segundo elemento a ser trocado, e armazena o resultado na variável `codigo2` (inteiro).

Em 6 chama-se a função `TrocarElementos` passando para ela como argumentos a lista onde as trocas devem ocorrer `(minhaLista)`, e os códigos dos itens a serem trocados que são `codigo` e `codigo2`.

Em 7 chama o comando `pause`, para "pausar" o terminal até que o usuário digite alguma tecla.

# Função ZerarLista:
```c
1void ZerarLista(TipoLista *lista)
{
  2 apontador aux = lista->primeiro->prox;
  3 apontador temp;
 
  4 while (aux != NULL)
    {
      5 temp = aux;
      6 aux = aux->prox;
      7 free(temp);
    }
 
  8 lista->ultimo = lista->primeiro;
  9 lista->primeiro->prox = NULL;
  10 lista->primeiro->ant = NULL;
 
  11 printf("\nLista zerada com sucesso!\n");
}
```

Em 1 define-se a `função ZerarLista`, que tem com parâmetros um ponteiro `lista (TipoLista)`.

Em 2 cria-se o apontador `aux`, que vai receber o campo `prox` do apontador `primeiro` da lista. 
Em 3 cria-se o apontador `temp`.

No laço `while`, em 4, enquanto o apontador `aux` for diferente de `NULL`, ou seja, enquanto `aux` não tiver chegado no fim da lista, vai executar o seguinte código. 

Enquanto o `while` em 4 é executado, em 5, o apontador `temp` recebe o apontador `aux`. 

Em 6 o apontador `aux` vai receber o campo `prox` de si mesmo, ou seja, `aux` vai receber o próximo apontador (ou próxima celula).

Em 7 utiliza o comando `free` sobre o apontador `temp`, liberando assim a memória que estava sendo alocada para a celula que estava sendo apontada por `temp`. 

Depois de que `aux` tenha percorrida toda a lista, e comando `free` tenha sido aplicado para todos os elementos, o seguinte código é executado.
**Obs.: O código abaixo já está fora do laço while.**

Em 8, o apontador `ultimo` da lista recebe o apontador `primeiro` da lista, indicando assim que ele está vazia.

Em 9, acessa o campo `prox` do apontador `primeiro` da lista, e armazena nele o valor `NULL`, para indicar que não existe próxima `celula`.
Em 10, acessa o campo `prox` do apontador `primeiro` da lista, e armazena nele o valor `NULL`, para indicar que não existe celula anterior.

Em 11, mostra uma mensagem que a lista foi zerada com sucesso.

**Demonstração do uso da função em main:**
```c
        /*Opção para Zerar a lista*/
        case 7:
1           ZerarLista(&minhaLista);
2           system("Pause");
            break;
```
Em 1 chama-se a função `ZerarLista` passando como argumento a lista a ser zerada `(minhaLista)`.

Em 2 chama o comando `pause`, para "pausar" o terminal até que o usuário digite alguma tecla.

# Função ConsultarTimePorId:
```c
1void ConsultarTimePorId(TipoLista lista, int chave)
{
  2 apontador aux = lista.primeiro->prox;
 
  3 while (aux != NULL)
    {
     4  if (aux->item.chave == chave)
        {
      5     printf("\nTime encontrado!\n");
            printf("Id: %d\n", aux->item.chave);
            printf("Nome: %s\n", aux->item.nome);
      9     printf("Pontos: %d\n", aux->item.pontos);
      10     return;
        }
     11  aux = aux->prox;
    }
 
 12  printf("\nErro: Time com ID %d nao encontrado!\n", chave);
}
```
Em 1, declaração de função e parâmetros.

Em 2, `aux` recebe o primeiro item da lista. 

Em 3, enquanto `aux` não chegar no último elemento da lista, executa o seguinte. 

Enquanto 3 for verdadeiro, em 4, caso o campo chave de `aux` seja igual a `chave` procurada, ou seja, o item foi encontrado, mostra as informações do item correspondente, em 5 a 9, e então encerra a execução da função.

Em 11, enquanto o laço `while` em 3 é executado, faz com que o apontador `aux` em `while` vá percorrendo as celulas da lista por meio do acesso e armazenamento do seu campo `prox`.

Em 12, caso `aux` percorra toda a lista com o while, e não encontre o item procurado, mostra uma mensagem de erro informando isso.

**Demonstração do uso da função em main:**
```c
/*Opcao de Consultar*/
        case 2:
1           printf("\nInforme a chave do time a ser consultado: ");
2           scanf("%d", &codigo);
3           ConsultarTimePorId(minhaLista, codigo);
4           system("Pause");
            break;
```

Em 1 e 2 pede para o usuário digitar a chave do time a ser consultado e armazena a entrada na variável `codigo` (inteiro).

Em 3 chama-se a função `ConsultarTimePorId` passando como argumento a lista em que a consulta deve ser realizada `(minhaLista)`, e o `codigo` a ser consultado. 

Em 4 chama o comando `pause`, para "pausar" o terminal até que o usuário digite alguma tecla.

# Função AlterarPontos:
```c
1void AlterarPontos(TipoLista *lista, int chave, int novosPontos)
{
  2 apontador no = BuscaElemento(*lista, chave);
 
  3 if (no == NULL)
    {
     4  printf("\nErro: Time com a chave %d nao encontrado.\n", chave);
     5  return;
    }
 
  6 no->item.pontos = novosPontos;
 
  7 printf("\nPontuacao do time com chave %d foi alterada para %d.\n", chave, novosPontos);
}
```

Em 1, declaração de função e parâmetros.

Em 2 utiliza o apontador `no` para buscar e armazenar a celula com a chave correspondente da busca.

Em 3, verifica se o time digitado é válido, se não, mostra uma mensagem e encerra a execução da função. 

Em 6 caso o time digitado seja válido, acessa o campo pontos do item do apontador `no`, e armazena a nova pontuação nele, assim atualizando para a nova pontuação. 
Em 7 então mostra uma mensagem que a alteração de pontos foi bem sucedida. 

**Demonstração do uso da função em main:**
```c
        /*Opcao para alterar a pontuacao de um time*/
        case 9:
1           printf("\nInforme a chave do time: ");
2           scanf("%d", &codigo);
 
3           printf("\nInforme a nova pontuacao: ");
4           scanf("%d", &itemAux.pontos);
 
5           AlterarPontos(&minhaLista, codigo, itemAux.pontos);
6           system("Pause");
            break;
```
Em 1 e 2 pede para o usuário informa a chave do time que vai ter a pontuação alterada, e armazenado o valor digitado na variável `codigo` (inteiro).

Em 3 e 4 pede para o usuário informar a nova pontuação do time, e armena no campo `pontos` de `itemAux(TipoItem)`.

Em 5 chama-se a função `AlterarPontos` e passa como argumentos a lista em que o time deve ser alterado `(minhaLista)`, o `codigo` do time (inteiro), e o campo `pontos` de `itemAux` (inteiro).

Em 6 chama o comando `pause`, para "pausar" o terminal até que o usuário digite alguma tecla.

