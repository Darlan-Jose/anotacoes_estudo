** 01 de abril de 2025 **
# Enunciado:
Considere um sistema de rastreamento que precisa monitorar a posição dos veículos com: Id, placa, data e hora, latitude e longitude
Quando o equipamento está offline ele armazena as posições em sua memória a cada minuto numa lista.
Quando ele entra na área de cobertura o equipamento consome a lista de posições armazenados e envia para um banco de dados e um sistema mostra no mapa onde o veículo está de acordo com a posição.
Alguns clientes desejam lidar com essas posições em forma de pilha, pois querem priorizar onde o veículo está no momento que voltou a comunicar, outros querem em forma de fila para permitir ter todas as posições na sequência montando o trajeto.

Seu programa deverá permitir através do menu:

- Escolher se o cliente vai trabalhar com Pilha ou Fila;
- Incluir novas posições na memória do equipamento do veículo:
- Retirar posições do equipamento do veículo baseado na escolha do cliente;   
- Imprimir o conteúdo da memória do equipamento.

# Declaração das estruturas:
```c
1typedef struct {
2   int id;
3   int placa;
4   char data_hora[20];
5   char latitude[50];
6   char longitude[50];
7} TipoItem;
```
 
Em 1 declaração da struct TipoItem como pode ser visto em 7.
De 2 a 6 são declarados os elementos dessa struct, id (int), placa (int), data_hora (char), latitude (char) e longitude (char).
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
6typedef struct {
7   apontador primeiro;
8} TipoFilaPilha;
 ```
-Em 6 cria uma struct chamada TipoFilaPilha como poder ser visto em 8.

# Main e o Menu:
O menu continua basicamente o mesmo do citado acima, com a adição de mais opções no printf, que são:
Obs.: As particularidades de alguns cases serão citados juntos com suas respectivas funções:
 ```c
printf("1 - Escolher entre fila ou pilha (não é possível alterar depois)\n2 - Incluir novas posicoes\n3 - Retirar posicoes\n"
               "4 - Imprimir dados\n-1 - Sair\n\nSua opcao: ");
 ```

[Função criar](https://github.com/Darlan-Jose/anotacoes_estudo/blob/main/estrutura-dados/exercicios/2-Fila-de-prioridade.md#fun%C3%A7%C3%A3o-criar)

[Função vazia](https://github.com/Darlan-Jose/anotacoes_estudo/blob/main/estrutura-dados/exercicios/2-Fila-de-prioridade.md#fun%C3%A7%C3%A3o-vazia)

# Função push:
```c
1void push(TipoFilaPilha *fila_pilha, TipoItem item){
2   if(verificarID(*fila_pilha, item.id)==1){
3       printf("O id do item ja esta na pilha\n");
4       return;
5   }else{
6       apontador aux = fila_pilha->primeiro;
7       while(aux->prox != NULL){
8           aux = aux->prox;
        }
9       aux->prox = (apontador) malloc(sizeof(celula));
10      aux = aux->prox;
11      aux->prox = NULL;
12      aux->item = item;
 
13      printf("Item inserido na pilha.\n");
    }
}
```
1 declaração da função e dos seus parâmetros.

Em 2, a função verificarID é chamada para verificar se o id do item que está sendo enfileirado já existe na fila.

Em 3, caso o id do item já exista na fila, a mensagem será impressa, indicando que o id já está na lista.

Em 4, se o id já estiver na fila (caso em que a função verificarID retornaria um valor verdadeiro), a função Fila_Enfileira_Normal retorna sem enfileirar o item.

Em 5, caso o id não exista na fila (ou seja, a verificação retornou falso), o bloco de código dentro do else será executado para adicionar o item à fila.

Em 6, é criado um ponteiro aux que inicialmente aponta para o primeiro elemento da fila, acessado via fila->primeiro. Esse ponteiro será usado para percorrer a fila até o final.

Esse while , em 7, percorre a fila até encontrar o último elemento. A condição aux->prox != NULL verifica se o próximo elemento na fila (aux->prox) é nulo, ou seja, se o próximo elemento a aux não é válido.

Em 8, dentro do laço while, o ponteiro aux é movido para o próximo elemento da fila (ou seja, vai "andando" pela fila até chegar no último item).

Em 9 é alocado dinamicamente memória para um novo elemento da fila, com o ponteiro prox de aux recebendo esse novo elemento. 

Em 10 aux recebe o elemento recém criado que está armazenado em prox, ou seja, aux recebe o campo prox dele mesmo.

Em 11 atualiza o campo prox para indicar está no fim da fila, faz isso indicando que não existe nenhum elemento depois dele, ou seja, o campo prox de aux recebe NULL.

Em 12  insere o novo elemento onde aux está, ou seja, o campo item do apontador aux recebe o item digitado pelo usuário.

Em 13 mostra uma mensagem dizendo que o item foi inserido na fila.

# Função enfileirar:
Mesma lógica da [Função push](https://github.com/Darlan-Jose/anotacoes_estudo/edit/main/README.md#fun%C3%A7%C3%A3o-push) com a alteração da mensagem mostrada em 13, que informa  que o item foi inserido na fila.

[Função verificarID](https://github.com/Darlan-Jose/anotacoes_estudo/blob/main/estrutura-dados/exercicios/2-Fila-de-prioridade.md#fun%C3%A7%C3%A3o-verificarid)

# Função pop:
```c
1apontador pop(TipoFilaPilha *fila_pilha) {
2   if (vazia(*fila_pilha) == 1) {
3       printf("A pilha esta vazia!!!\n");
4       return NULL;
5   } else {
6       apontador aux = fila_pilha->primeiro->prox;
7       apontador anterior = fila_pilha->primeiro;
 
8       while (aux->prox != NULL) {
9           anterior = aux;
10          aux = aux->prox;
        }
 
        // A celula removida (aux) é retornada
11      anterior->prox = NULL;
12      return aux;  // Retorna o ponteiro para a celula removida
    }
}
```
1 declaração da função e dos respectivos parâmetros. 

De 2 a 4 verifica se a fila está vazia.

Em 3 mostra uma mensagem informando isso.
Em 4 retorna NULL. Como a função deve retornar um valor, mas como nenhum valor deve ser retirado da memória no comando free no case de chamada, retorna NULL, com isso free não vai retirar nada da memória.

Em 5 caso 2 seja falso, ou seja a fila não está vazia, executa os seguintes códigos. 

Considerando que 5 foi verdadeiro, em 6 cria o apontador aux que vai receber o primeiro item válido da fila/pilha, ou seja, o campo prox do apontador primeiro de fila_primeiro é armazenado em aux.

Em 7, o elemento anterior recebe o elemento que vem antes de aux, ou seja, o apontador anterior vai receber o apontador primeiro de fila_pilha.

No while em 8, enquanto aux não chegar no final da fila vai executar o código dentro dele, ou seja, enquanto o campo prox de aux for diferente de NULL executa o código dentro do while. 

Enquanto 8 for verdadeiro, em 9, anterior é atualizado para receber o aux, já que futuramente aux vai mudar de posição/elemento, ou seja, o apontador anterior recebe o apontador aux. 

Em 10, aux passa para o próximo elemento da fila, ou seja, aux recebe o apontador prox dele mesmo.

Em 11, como aux será removido o item anterior passa a ser o último elemento da lista, com isso o apontador prox de anterior deve ser atualizado para indicar que ele é o último da fila, ou seja, o campo prox do apontador anterior recebe NULL.

Em 12 retorna aux para ele ser liberado no case que chamou a função em main.

[Função desenfileirar](Link para desenfileirar exercício03)

# Função imprimir:
```c
1void imprimir(TipoFilaPilha fila_pilha, int metodoEscolhido) {
2   if (metodoEscolhido == 0) {  // Se nenhum metodo foi escolhido
3       printf("Escolha um metodo primeiro!\n");
4       return;
    }
 
5   if (vazia(fila_pilha) == 1) {
6       if (metodoEscolhido == 2) {  // Se o metodo escolhido for pilha
7           printf("A pilha está vazia!!!\n");
8       } else {  // Caso seja fila
9           printf("A fila está vazia!!!\n");
        }
10      return;
11  } else {
12      apontador aux = fila_pilha.primeiro->prox;
13      while (aux != NULL) {
14          printf("Id: %d\n", aux->item.id);
15          printf("Placa: %d\n", aux->item.placa);
16          printf("Data e Hora: %s\n", aux->item.data_hora);
17          printf("Latitude: %s, Longitude: %s\n", aux->item.latitude, aux->item.longitude);
18          printf("\n");
19          aux = aux->prox;
        }
    }
}
```
1 declaração da função e dos seus respectivos parâmetros. 

No if em 2, checa se nenhum método foi escolhido, ou seja, se metodoEscolhido é igual a 0, se sim, executa os seguintes códigos.

Considerando 2 verdadeiro, em 3 mostra uma mensagem informando para escolher um método.
E em 4 retorna a função sem executar nenhuma ação de imprimir. 

Em 5 chama a função vazia, se a mesma retornar 1, indica que a estrutura está vazia.
	Em 6, caso o if em 5 seja verdadeiro, esse if checa se o método escolhido na função escolherMetodo é igual ao método pilha, ou seja, se metodoEscolhido é igual a 2. Se sim, em conjunto com o if em 5 que verifica se uma estrutura está vazia, mostra uma mensagem informando que a pilha está vazia.

No else em 8, que pertence ao if em 6, é o caso se metodoEscolhido for diferente de 2, logicamente vai ser o outro método disponível, que é fila, isso em conjunto com o if em 5, mostra uma mensagem dizendo que a fila está vazia. 

Se o if em 5 for verdadeiro, ou seja a estrutura estiver vazia, o return em 10, para a execução da função sem imprimir qualquer informação. 

No else em 11, que pertence ao if em 5, ou seja, se a estrutura não estiver vazia, executa os seguintes comandos. 

Em 12, cria-se o apontador aux que vai armazenar o primeiro elemento da fila_pilha.

No while em 13, verifica se aux é diferente de NULL, isso em conjunto com 19, faz com aux percorra a estrutura até chegar no final dela. 

Da linha 14 a 18, enquanto o while de 13 for verdadeiro, mostra mensagens informando os dados referentes a célula com posição igual a posição em que aux se encontra. 

Em 19, é a lógica responsável por fazer aux percorrer a estrutura do while em 13, ou seja, aux recebe o seu campo prox. 

[Função zerar](https://github.com/Darlan-Jose/anotacoes_estudo/blob/main/estrutura-dados/exercicios/2-Fila-de-prioridade.md#fun%C3%A7%C3%A3o-zerar)

# Função escolherMetodo:
```c
/* Funcao para escolher o metodo de pilha ou fila */
1void escolherMetodo(int *metodoEscolhido) {
2   if (*metodoEscolhido == 0) {  // Se nao foi escolhido nenhum metodo ainda
3       int opcao;
4       printf("Escolha entre Fila (1) ou Pilha (2): ");
5       scanf("%d", &opcao);
6       if (opcao == 1) {
7           printf("Metodo de Fila escolhido.\n");
8           *metodoEscolhido = 1;  // Fila
9       } else if (opcao == 2) {
10          printf("Metodo de Pilha escolhido.\n");
11          *metodoEscolhido = 2;  // Pilha
12      } else {
13          printf("Opção inválida.\n");
14          return;
        }
15  } else {
16      printf("Nao é possível alterar o método após a escolha inicial.\n");
    }
}
```
1 declaração do função e do seu parâmetro. 

Em 2, verifica se nenhum método ainda não foi escolhido, ou seja, se metodoEscolhido está igual a 0, se sim executa o seguinte código. 

Considerando 2 verdadeiro, em 3 cria uma variável int chamada opcao. 
E em 4 e 5, pede para o usuário escolher entre fila (1) e pilha (2), e armazena o resultado em opcao.

Em 6 checa se opcao é igual a 1, ou seja, se a opção escolhida foi fila, se sim, mostra uma mensagem informando isso em 7, e seta o valor de metodoEscolhido para 1, em 8.

No else if em 9, checa se opcao é igual a 2, ou seja, se a opção escolhida foi pilha, es sim, mosta uma mensagem informando isso em 10, e seta o valor de metodoEscolhido para 2, em 11.

No else em 12 que pertence ao if em 6, caso nenhum valor válido (1, 2) tenha sido digitado, mostra uma mensagem informando isso em 13, e retorna a função sem fazer nada em 14. 

No else em 15, que pertence ao if  2, caso metodoEscolhido seja diferente de zero, ou seja, algum  método já foi escolhido, mostra uma mensagem informando que não se pode alterar o método depois da escolha em 16.
