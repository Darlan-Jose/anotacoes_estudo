**10 de abril de 2025**

# Enunciado:
Você está desenvolvendo um sistema para um hospital público que deseja organizar os atendimentos de emergência com base na prioridade de entrada dos pacientes. Cada paciente tem um ID único e uma pontuação de prioridade (quanto maior, mais urgente o caso).
Para otimizar a alocação de recursos, a triagem precisa ser feita rapidamente. Por isso, será usada uma Árvore Binária de Busca com a pontuação de prioridade como chave.

Implemente uma árvore binária de busca que ofereça as seguintes funcionalidades:
1. Inserir Pacientes: Cada nó conterá:
- ID do paciente (inteiro)
- Nome (string)
- Pontuação de prioridade (inteiro de 0 a 100)
2. Buscar Paciente por ID: Permite consultar rapidamente se um paciente já está cadastrado.
3. Listar Pacientes em Ordem de Prioridade: Faça uma travessia em ordem para exibir do menor ao maior grau de prioridade.
4. Calcular Estatísticas:
- Média da prioridade de todos os pacientes
- Quantidade total de pacientes
- Maior e menor prioridade registrada

# Declaração das estruturas:
```c
1typedef struct tree{
2   int prioridade;
3   int id;
4   char nome[30];
5   struct tree* sad;
6   struct tree* sae;
7}Tree;
```

Em 1 declara-se a struct tree que também possui um alias chamado Tree, como pode ser visto em 7.

Essa estrutura vai armazenar uma prioridade (inteiro), um id (inteiro), nome (char), um ponteiro para a struct tree chamado sad (sub-árvore à direita), e um ponteiro para a struct tree chamado sae (sub-árvore à esquerda).

#Main e o menu:
```c
1int main(){
2   setlocale(LC_ALL, "portuguese");
3   int op, prioridade, id, total_pacientes, maior, menor;
4   char nome[30];
5   float media;
 
    // Inicializa o gerador de numeros aleatorios
6   srand(time(NULL));
7   int numeros[N];
8   int index = 0;
 
    // Preenche o vetor com numeros de 1 a 1000
9   for (int i = 0; i < N; i++) {
10      numeros[i] = i + 1;
    }
 
    // Embaralha os numeros no vetor
11  embaralhar(numeros, N);
 
12  Tree* t = createTree();  // Cria uma arvore
 
13  do {
14      system("cls");
15      printf("1 - Inserir um paciente\n2 - Buscar um paciente pelo id\n3 - Listar pacientes em ordem de prioridade\n"
               "4 - Calcular estatasticas\n5 - Remover um paciente\n-1 - Sair\n\nSua opcao: ");
16      scanf("%d", &op);
 
17      switch (op) {
18      case 1:
		   //Aqui tem o código do case
19          system("pause");
20          break;

        case 2:
            //Aqui tem o código do case
            system("pause");
            break;
 
        case 3:
            //Aqui tem o código do case
            system("pause");
            break;
 
        case 4:
            //Aqui tem o código do case
            system("pause");
            break;
 
        case 5:
		   //Aqui tem o código do case
            system("pause");
            break;
        }
21  } while (op != -1);
 
22  system("PAUSE");
23  return 0;
}
```
Em 3 declara-se as seguintes variáveis inteiras que serão usadas no restante do código:
-op: Vai armazenar a opção do menu escolhida pelo usuário.
-prioridade: Vai armazenar a prioridade do paciente, para passar esse valor para alguma função.
-id: Vai armazenar o id do paciente, para passar esse valor para alguma função.
-total_pacientes: Vai armazenar o número total de pacientes que é calculado por uma função com essa tarefa.
-maior: Vai armazenar a maior prioridade.
-menor: Vai a armazenar a menor prioridade.

Em 3 declara-se a variável nome do tipo char. 

Em 5 declara-se a variável media do tipo float (número flutuante).

Em 6, utiliza a função srand(), passando como seed para ela o retorno da função time(), a função time(NULL) retorna um número de segundos desde de a data epoch (o tempo atual em segundos), com esse valor sendo usado como seed para srand.

Em 7 declara-se um vetor do tipo inteiro chamado numeros, que tem o tamanho máximo de N (1000). Esse vetor será responsável por armazenar os ids gerados aleatoriamente pela função srand. 

Em 8 declara-se a variável index (inteiro) que vai ser responsável por ...

Em 9 no laço for, cria-se a variável i que vai receber 0, e enquanto ela for menor que N (1000) vai percorrer o vetor em +1.
	Em 10, enquanto o laço em 9 for verdadeiro, pega-se a posição do vetor correspondente a i e armazena nessa posição i + 1, isso faz o vetor seja preenchido com números de 1 até N. 

Em 11 chama-se a função embaralhar, passando como argumentos o vetor numeros e o macro N. 

Em 12 chama-se a função createTree() e armazena o árvore criada por essa função no Tree* chamado t.

De 13 a 23 é utilizado a mesma estrutura e lógica do código usado aqui: Main e o menu, com a alteração dos cases e das opções do menu.

# Função createTree:
```c
1Tree* createTree(){
2    return NULL;
}
```
Em 1 declaração da função createTree, ela não possui nenhum parâmetro, o retorno dela será do tipo Tree.

# Função treeIsEmpty:
```c
1int treeIsEmpty(Tree* t){
2   return t == NULL;
}
```
1 declaração da função é do seu parâmetro. 

Em 2 checa-se se a árvore (Tree) está vazia, ou seja, se t é igual a NULL, se for verdadeiro, retorna 1 (a árvore está vazia), se for falso, retorna 0 (a árvore não está vazia.)

Em 2 ela retorna NULL, já que a função está criando uma árvore vazia.
Obs.: Uma árvore é representada pelo endereço do no raiz. Com essa função criando uma árvore com nenhum elemento, por isso ela retorna NULL.

# Função showTree:
```c
1void showTree(Tree* t){
 
2   if(!treeIsEmpty(t)){ /* se a árvore não for vazia... */
3       showTree(t->sae); /* mostra a sae (sub-árvore a esquerda) */
4       printf("<%d> ", t->num); /* mostra a raiz */
5       showTree(t->sad); /* mostra a sad (sub-árvore a direita) */
    }
}
```
Em 1 declaração da função e dos seus parâmetros.

Em 2 verifica se a árvore não está vazia, ou seja, chama a função treeIsEmpty com uma negação antes da chamada, passando como argumento a árvore a ser analisada. Se for verdadeiro, ou seja, a árvore não estiver vazia executa o restante do código.

Em 3, se 2 for verdadeiro, a função vai se chamar, passando como argumento a sub-árvore a esquerda.
Na chamada da sub-árvore a esquerda vai se verificar se ela não é vazia, se não for vazia, novamente passa o ponteiro da sub-árvore a esquerda, esse processo ocorre até a função treeIsEmpty falar que a árvore é vazia, ou seja, !treeIsEmpty vai retornar falso, quando isso ocorrer a função volta imprimindo os dados de cada nó "raiz" de cada sub-árvore, utilizando comando da linha  4.

Em 5 ocorre o mesmo processo lógico da linha 3, só que para o lado direto da árvore.

A lógica das linhas 3, 4 e 5 é a seguinte:

Caso 2 seja verdadeiro, ou seja, a árvore não está vazia, primeiro vai percorrer o lado esquerdo da árvore (que do ponto de vista lógico também é uma árvore), então a função chama a si mesmo, passando como parâmetro o lado esquerdo da sub-árvore, vai se verificar se essa sub-árvore (que também é uma árvore) não está vazia, e vai se repetir o processo até que alguma sub-árvore do lado esquerdo seja vazia, quando isso ocorrer, ou seja showTree for NULL não vai imprimir nada e vai passar para a chamada anterior e imprimir o valor daquela chamada, depois vai para o lado direto da sub-árvore que teve o valor impresso e repete a mesma lógica citada aqui até encontrar um elemento vazio, indo do lado esquerdo e direito da árvore até se encontrar um valor NULL, e poder voltar e imprimir os valores válidos (não nulos).
Simulação de uma execução

Utiliza a mesma lógica, com alteração para a impressão dos respectivos dados desse contexto que são id, nome e prioridade.

# Função insertTree:
```c
/* Funçao que insere um dado na arvore */
1void insertTree(Tree** t, int prioridade, int id, char* nome){
2   if (*t == NULL) {
3       *t = (Tree*)malloc(sizeof(Tree)); // Aloca mem ria para o no
4       (*t)->sae = NULL;  // Subarvore a esquerda e NULL
5       (*t)->sad = NULL;  // Sub rvore a direita e NULL
6       (*t)->prioridade = prioridade;  // Armazena a prioridade
7       (*t)->id = id;  // Armazena o id
8       strcpy((*t)->nome, nome);  // Armazena o nome
9   } else {
10      if (prioridade < (*t)->prioridade) {
11          insertTree(&(*t)->sae, prioridade, id, nome);  // Vai para a subarvore a esquerda
12      } else if (prioridade > (*t)->prioridade) {
13          insertTree(&(*t)->sad, prioridade, id, nome);  // Vai para a subarvore a direita
14      } else {
            // Se a prioridade for igual, usa o id como criterio
15          if (id < (*t)->id) {
16              insertTree(&(*t)->sae, prioridade, id, nome);  // Insere a esquerda se o id for menor
17          } else {
18              insertTree(&(*t)->sad, prioridade, id, nome);  // Insere a direita se o id for maior ou igual
            }
        }
    }
}
```
Em 1 é a declaração da função e dos seus parâmetros, o primeiro parâmetro vai ser do tipo Tree chamado t, ele é um ponteiro para um ponteiro (2. Como um ponteiro para um ponteiro funciona?), o segundo parâmetro é um num do tipo int.

Obs.: Considere t a raiz da árvore.

No if em 2 verifica se a raiz da árvore está vazia (a árvore ainda não existe), ou seja, se *t é igual a NULL. 

Em 3, aloca a memória para a estrutura da árvore, ou seja, utiliza o comando malloc em conjunto com sizeof para alocar na memória um espaço do tamanho de Tree, o ponteiro genérico retornado por malloc é convertido em um ponteiro do tipo Tree, com isso tudo sendo armazenado  na raiz (*t).

Obs.: Depois da alocação, lembre-se *t agora é uma estrutura Tree, ou seja, possui um int num, uma tree sad e uma tree sae.

Em 4 seta o lado esquerdo da árvore para indicar que ainda não existe nenhum elemento, ou seja, acessa sae de *t e armazena NULL. 

Em 5 seta o lado direito da árvore para indicar que ainda não existe nenhum elemento, ou seja, acessa sad de *t e armazena NULL. 

Em 6 armazena a primeira prioridade a ser inserida em prioridade, que vai ser a raiz da árvore, ou seja, acessa o campo prioridade de *t e armazena prioridade.
 
Em 7 repete-se o mesmo processo de 6, só que para o campo id. 

Em 8, utiliza a função strcpy para copiar o nome a ser inserido, no campo nome do nó raiz da árvore.

No else em 9, que vai ocorrer caso a raiz da árvore já exista, ou seja, *t é diferente de NULL, vai executar os seguinte comandos:
	No if em 10 verifica se a prioridade digitada é menor que a prioridade armazenada na raiz, ou seja, se prioridade é menor que o campo prioridade de *t, se sim executa o seguinte código.
		Em 11, a função insertTree se chama recursivamente, passando como parâmetro a árvore a esquerda do nó atual (sub-árvore a esquerda) e a prioridade, id e nome, ou seja, chama insertTree e passa como ponteiro, o campo sae, e também passa a prioridade, id e nome. A recursão vai continuar até encontrar um nó vazio (*t == NULL) para armazenar o novo elemento.
		
No else if em 12 verifica se a prioridade digitada é maior que a prioridade armazenada na raiz, ou seja, se prioridade é maior que o campo prioridade de *t, se sim executa o seguinte código.
		Em 13, a função insertTree se chama recursivamente, passando como parâmetro a árvore a direta do nó atual (sub-árvore a direita) e a prioridade, id e nome, ou seja, chama insertTree e passa como ponteiro, o campo sad, e também passa a prioridade, id e nome. A recursão vai continuar até encontrar um nó vazio (*t == NULL) para armazenar o novo elemento.
		
No else em 14, caso as prioridades digitadas sejam iguais, vai utilizar o id como parâmetro, executando os seguinte códigos.
		No if em 15 verifica se o id digitado é menor que o id armazenado na raiz, ou seja, se id é menor que o campo id de *t, se sim executa o seguinte código.
			Em 16, a função insertTree se chama recursivamente, passando como parâmetro a árvore a esquerda do nó atual (sub-árvore a esquerda) e a prioridade, id e nome, ou seja, chama insertTree e passa como ponteiro, o campo sae, e também passa a prioridade, id e nome. A recursão vai continuar até encontrar um nó vazio (*t == NULL) para armazenar o novo elemento.
			
No else em 17 verifica se o id digitado é maior que o id armazenado na raiz, ou seja, se id é maior que o campo id de *t, se sim executa o seguinte código.
Em 18, a função insertTree se chama recursivamente, passando como parâmetro a árvore a direta do nó atual (sub-árvore a direita) e a prioridade, id e nome, ou seja, chama insertTree e passa como ponteiro, o campo sad, e também passa a prioridade, id e nome. A recursão vai continuar até encontrar um nó vazio (*t == NULL) para armazenar o novo elemento.

# Função embaralhar:
```c
// Função para embaralhar o vetor de IDs
1void embaralhar(int *arr, int n) {
2   for (int i = 0; i < n; i++) {
3       int j = rand() % n;
4       int temp = arr[i];
5       arr[i] = arr[j];
6       arr[j] = temp;
    }
}
```
Em 1 declaração da função embaralhar e dos seus atributos que são um ponteiro para um vetor de inteiros, e n (inteiro), que representa o tamanho do vetor.

No laço for em 2, cria uma variável inteira chamada int, que recebe zero, e enquanto i for menor que n, i é incrementado em +1, isso faz com que i percorra o vetor do início ao fim. Enquanto esse laço ocorrer os seguintes comandos são executados.
	Em 3 utiliza a função rand para gerar um número pseudoaleatório entre 0 e n - 1, esse número é armazenado em j. 
	
Em 4 armazena a posição atual de i no vetor em uma variável temporária temp. 
	
Em 5 a posição atual em que i se encontra, vai receber a posição "aleatória" em que j se encontra.
	
E em 6, a posição em que j se encontra, vai receber temp, que era o antigo valor correspondente a antiga posição de i.
Com isso que ocorre em 5 e 6, é feita o embaralhamento de forma "aleatória" entre os elementos do vetor numeros. 

# Função obter_id_unico:
```c
// Função para obter um novo ID único
1int obter_id_unico(int *arr, int *index) {
2   if (*index < N) {
3       return arr[(*index)++];
    }
4   return -1;  // Caso todos os IDs já tenham sido utilizados
}
```
Em 1 declaração da função obter_id_unico e dos seus parâmetros, arr que um ponteiro para um vetor de inteiros, e index (0) que é um ponteiro inteiro para representar uma posição no vetor. 

No if em 2, enquanto a posição de index for menor que o tamanho total do vetor numeros que é indicado por N (1000), executa os seguinte código.
	
Em 3, quando 2 for verdadeiro, vai retornar a posição do vetor numeros com posição correspondente a index, depois que esse retorno é feito index é incrementado em +1, fazendo com que ele passe para o próximo elemento do vetor.
	
Em 4, que vai ocorrer caso index não seja mais menor que N, ou seja, tenha percorrido todo o vetor numeros, retorna -1, para indicar que não existem mais ids válidos para serem retornados. 

# Função busca:
```c
/* Função que verifica se um elemento pertence ou não a árvore */
1Tree* busca(Tree* t, int id) {
2   if (t == NULL)
3       return NULL;
 
4   if (t->id == id)
        return t;
 
    // Busca recursivamente nas subarvores esquerda e direita
5   Tree* resultado = busca(t->sae, id);
6   if (resultado != NULL)
7       return resultado;
 
8   return busca(t->sad, id);
}
```

Em 1 declaração da função  busca e dos seus parâmetros, que são um ponteiro do tipo tree chamado t, e um id (inteiro).

No if em 2, verifica se o a árvore está vazia, ou seja, se t é igual a NULL, se sim retorna NULL, em 3. 

No if em 4, verifica se o id em que t se encontra é igual ao id procurado, ou seja se encontrou o id, se sim retorna o no da árvore que possui esse id correspondente, em 4.

Obs.: O if em 2 e 4 são as condições de parada da função. 

Em 5 cria-se um ponteiro chamado resultado (tipo Tree), ele vai chamar a função busca de forma recursiva, passando como argumentos, o lado esquerdo da árvore e o id, ou seja, o campo sae de t, e o id. Com isso a função busca fara a busca até encontrar nada (condição de parada em 2) ou até encontrar o nó com o id correspondente (condição de parada em 4), o que ela retornar vai ser armazenado em resultado. 

Em 6 verifica se busca retornou um resultado válido, ou seja, se resultado é diferente de NULL, se sim retorna a variável resultado, como trabalho da função. Esse trecho verifica se o id procurado foi encontrado no lado esquerdo da árvore. 

Em 8, caso o if em 6 seja falso, ou seja o id não foi encontrado no lado esquerdo, faz a busca agora no lado direto da árvore, repetindo os mesmos processo acima, enquanto for necessário.

# Função calcular_media_prioridade:
```c
// Função recursiva para calcular a soma das prioridades e o numero de nos
1void calcular_media_prioridade(Tree* t, int* soma, int* contagem) {
2   if (t != NULL) {
3       *soma += t->prioridade;  // Acumula a prioridade do no
4       (*contagem)++;           // Conta o no
 
        // Recursivamente, percorre a subarvore a esquerda e a direita
5       calcular_media_prioridade(t->sae, soma, contagem);
6       calcular_media_prioridade(t->sad, soma, contagem);
    }
}
```

Em 1 define-se a função calcular_media_prioridade e os seus parâmetros que são um ponteiro t (Tree), um ponteiro soma (inteiro) e um ponteiro contagem (inteiro).

Em 2 verifica se a árvore não está vazia, ou seja, se t é diferente de NULL, se sim executa os seguintes códigos.
	Enquanto 2 for verdadeiro, em 3, acumula o valor da prioridade de cada nó no ponteiro soma. 
	E em 4 faz a contagem de nós, incrementando a variável contagem em + 1.
	
Obs.: O if em 2 é a condição de parada.
	
Em 5, faz a contagem do lado esquerdo da árvore, ou seja, se 2 for verdadeiro, a função calcular_media_prioridade se chama recursivamente, passando como argumentos o lado esquerdo da árvore (sub-árvore a esquerda), a variável soma e contagem. 
	
E depois em 6, faz a contagem do lado direito da árvore, ou seja, se 2 for verdadeiro, a função calcular_media_prioridade se chama recursivamente, passando como argumentos o lado direito da árvore (sub-árvore a direita), a variável soma e contagem.

# Função media_prioridade:
```c
// Função que retorna a media das prioridades
1float media_prioridade(Tree* t) {
2   int soma = 0, contagem = 0;
3   calcular_media_prioridade(t, &soma, &contagem);
 
4   if (contagem == 0) {
5       return 0;  // Evita divisao por zero se a arvore estiver vazia
    }
 
6   return (float)soma / contagem;  // Retorna a media
}
```

Em 1 declaração da função media_prioridade e dos seus parâmetros que são, um ponteiro t (Tree).

Em 2 cria as duas varáveis principais para o cálculo, soma e contagem as duas do tipo inteiro, e seta os valores inicias dela como zero. 

Em 3 vai chamar a Função calcular_media_prioridade, passando com argumentos a variável t, soma e contagem.

Em 4 verifica se a função de calcular não contou nenhum nó, ou seja, se contagem é igual a 0, se sim retorna 0. Isso é feito para evitar divisões por zero.

Em 6, caso 4, seja falso, ou seja, calcular é diferente de 0, vai realizar a divisão de soma (acumulo (soma) de todos os valores de prioridades) por contagem (número de nós percorridos). E vai retornar o resultado dessa divisão. 

# Função contar_pacientes:
```c
// Função recursiva para contar a quantidade de nos na arvore
1int contar_pacientes(Tree* t) {
2   if (t == NULL) {
3       return 0;  // Se a arvore estiver vazia, a quantidade e 0
    }
 
    // Conta o no atual e recursivamente conta os nos das subarvores o esquerda e o direita
4   return 1 + contar_pacientes(t->sae) + contar_pacientes(t->sad);
}
```
Em 1 ocorre a declaração da função contar_pacientes e dos seu parâmetro que é um ponteiro t (Tree).

Em 2 verifica se a árvore é vazia, ou seja, se t é igual a NULL.
	
Se 2 for verdadeiro, em 3 retorna 0, como a árvore é vazia existem 0 pacientes.

Obs.: 2 é a condição de parada.

Se 2 for falso, em 4 retorna 1 + a o resultado da função contar_pacientes se chamando de forma recursiva, passando como argumento a sub-árvore a esquerda (sae) + o resultado da função contar_pacientes se chamando de forma recursiva, passando como argumento a sub-árvore a direita (sad). Ou seja retorna o resultado da soma da sub-árvore à esquerda, mais a sub-árvore à direita, mais o 1 do nó inicial da árvore. 

# Função encontrar_maior_menor_prioridade:
```c
// Função recursiva para encontrar a maior e a menor prioridade
1void encontrar_maior_menor_prioridade(Tree* t, int* maior, int* menor) {
2   if (t == NULL) {
3       return;  // Se a árvore estiver vazia, não faz nada
    }
 
    // Atualiza a maior prioridade se necessário
4   if (t->prioridade > *maior) {
5       *maior = t->prioridade;
    }
 
    // Atualiza a menor prioridade se necessário
6   if (t->prioridade < *menor) {
7       *menor = t->prioridade;
    }
 
    // Recursivamente, percorre as subárvore a esquerda e a direita
8   encontrar_maior_menor_prioridade(t->sae, maior, menor);
9   encontrar_maior_menor_prioridade(t->sad, maior, menor);
}
```
Em 1 define-se a função encontrar_maior_menor_prioridade e os seus parâmetros que são, um ponteiro t (Tree), um ponteiro maior e menor (os dois são inteiros).

Em 2 verifica se a árvore está vazia, ou seja, se t é igual a NULL, se sim retorna sem fazer nada, em 3. 

Obs.: 2 é a condição de parada.

Em 4 verifica se a prioridade do nó t atual é maior que o valor armazenado em maior, se sim faz com que o ponteiro maior recebe esse novo valor do campo prioridade de t, em 5.

Em 6 e 7 faz o mesmo processo de 4 e 5, só que para a menor prioridade.

Em 8, percorre o lado esquerdo da árvore a procura da maior e menor prioridade, ou seja, a função encontrar_maior_menor_prioridade se chama recursivamente, passando como argumento a sub-árvore a esquerda (sae) e as variáveis maior e menor. 

Em 9, percorre o lado direito da árvore a procura da maior e menor prioridade, ou seja, a função encontrar_maior_menor_prioridade se chama recursivamente, passando como argumento a sub-árvore a direita (sad) e as variáveis maior e menor. 

# Função maior_menor_prioridade:
```c
// Função que retorna a maior e a menor prioridade
1void maior_menor_prioridade(Tree* t, int* maior, int* menor) {
2   if (t == NULL) {
3       printf("A arvore esta vazia.\n");
4       return;
    }
 
    // Inicializa maior e menor com a prioridade do primeiro no
5   *maior = t->prioridade;
6   *menor = t->prioridade;
 
    // Chama a função recursiva para encontrar maior e menor prioridade
7   encontrar_maior_menor_prioridade(t, maior, menor);
}
``` 
Em 1 define-se a função maior_menor_prioridade e seus parâmetros que são um ponteiro t (Tree), um ponteiro maior e menor (os dois são do tipo inteiro. )

Em 2 a 4, checa-se a árvore está vazia, se sim, mostra uma mensagem informando isso e retorna a função sem fazer nada. 

Em 5, inicializa o ponteiro maior com o valor da prioridade do primeiro nó da árvore.

Em 6, inicializa o ponteiro menor com o valor da prioridade do primeiro nó da árvore.

Em 7 chama a função encontrar_maior_menor_prioridade (Função encontrar_maior_menor_prioridade:)  para que ele descubra e altere os valores da maior prioridade (maior ) e da menor prioridade (menor)

# Função encontrar_minimo:
```c
// Função auxiliar para encontrar o menor no da subarvore
1Tree* encontrar_minimo(Tree* t) {
2   while (t && t->sae != NULL) {
3       t = t->sae;
    }
4   return t;
}
```
Em 1 declaração da função encontrar_minimo e do seu parâmetro que é um ponteiro t (Tree).

No while em 2, enquanto t e a sub-árvore a esquerda (sae) de t forem valores válidos, ou seja, t e o campo sae de t forem diferentes de NULL, executa os seguintes códigos. 
	Enquanto 2 estiver sendo executado, em 3, a árvore t vai receber a sub-árvore a esquerda dela mesma (sae), ou seja, t vai receber o campo sae dele mesmo. Isso em conjunto com o while em 2, faz com a árvore percorra as sub-árvores do lado esquerdo (onde estão armazenados os valores menores que t) até chegaram no menor valor válido da árvore original (t).

Em 4 depois de ter descoberto o menor valor da árvore em 2 e 3, retorna esse valor.  

# Função removeTree:
```c
// Função para remover um no da arvore mantendo a estrutura de busca
1Tree* removeTree(Tree* t, int prioridade, int id) {
2   if (t == NULL){
	3  return NULL; 
	}
 
4    if (prioridade < t->prioridade || (prioridade == t->prioridade && id < t->id)) {
5       t->sae = removeTree(t->sae, prioridade, id);  // Vai para a esquerda
6   } else if (prioridade > t->prioridade || (prioridade == t->prioridade && id > t->id)) {
7       t->sad = removeTree(t->sad, prioridade, id);  // Vai para a direita
8   } else {
        // Encontrou o no a ser removido
 
        // Caso 1: sem filhos
9      if (t->sae == NULL && t->sad == NULL) {
10          free(t);
11          return NULL;
        }
 
        // Caso 2: apenas um filho
12      else if (t->sae == NULL) {
13          Tree* temp = t->sad;
14          free(t);
15          return temp;
16      } else if (t->sad == NULL) {
17          Tree* temp = t->sae;
18          free(t);
19          return temp;
        }
 
        // Caso 3: dois filhos
20      Tree* temp = encontrar_minimo(t->sad);  // Sucessor (menor da subarvore direita)
21      t->prioridade = temp->prioridade;
22      t->id = temp->id;
23      strcpy(t->nome, temp->nome);
24      t->sad = removeTree(t->sad, temp->prioridade, temp->id);
    }
 
25  return t;
}
```

Em 1 declaração da função removeTree e dos seus parâmetros que são um ponteiro t (Tree), uma variável prioridade (inteiro) e um id (inteiro).

Em 2 verifica se o nó da árvore é vazio, ou seja, se t é igual a NULL, isso significa que o nó que estamos procurando não existe (✅ O que ele faz?).

Se 2 for verdadeiro, retorna NULL, em 3, já que não tem nada para ser removido.

Obs.: O código em 2 e 3 é a condições de parada da função. 

No if em 4 verifica várias condições que são:
Primeiro verifica se a prioridade digitada é menor que a prioridade de t.

OU

Se a prioridade é igual a prioridade de t, e o id digitado é menor que o id de t.
Esse if verifica as condições que determinam se a função deve ir para o lado esquerdo da árvore, onde estão armazenados os valores de menor prioridade, e em caso do mesmo valor de prioridade, com o id de menor valor.

Em 5 caso 4 seja verdadeiro, o lado esquerdo da árvore vai chamar a função removeTree recursivamente, passando como argumentos a sub-árvore a esquerda (sae), a prioridade digitada e o id digitado, isso faz com que a função procure pelo nó alvo no lado esquerdo da árvore.
	
No else if em 6 verifica várias condições que são:
Primeiro verifica se a prioridade digitada é maior que a prioridade de t.

OU

Se a prioridade é igual a prioridade de t, e o id digitado é maior que o id de t.
Esse if verifica as condições que determinam se a função deve ir para o lado direito da árvore, onde estão armazenados os valores de maior prioridade, e em caso do mesmo valor de prioridade, com o id de maior valor.
	Em 7 caso 6 seja verdadeiro, o lado direito da árvore vai chamar a função removeTree recursivamente, passando como argumentos a sub-árvore a direita(sad), a prioridade digitada e o id digitado, isso faz com que a função procure pelo nó alvo no lado direto da árvore.

No else em 8, que vai ocorrer quando a prioridade e o id forem iguais aos valores que estão sendo procurados, ou seja, quando o código em 5 ou 7 encontrar o nó alvo (ou não encontra-lo, condição em 2), vai executar o seguinte.

Caso 8 seja verdadeiro, no if em 9, vai verificar se o nó a ser removido não possui nenhuma sub-árvore filha, nem a esquerda, nem a direita, ou seja, se o campo sae de t é igual a NULL e o campo sad de t também seja igual a NULL, vai executar o seguinte código.
		Caso 9 seja verdadeiro, em 10 utiliza o comando free sobre o nó t, para realmente libera-lo da memória e da estrutura da árvore.
		
E em 11 retorna NULL para encerrar a execução da função removeTree. 
		
Caso 8 seja verdadeiro e 9 falso, entra no else if em 12 e 16, que vai verificar se o nó a ser removido possui apenas uma sub-árvore, em 12 verifica se a sub-árvore a esquerda não existe (sae), ou seja, se o campo sae de t é igual a NULL, se sim executa o seguinte código. 
		
Caso 12 seja verdadeiro, ou seja, só existe a sub-árvore a direita (sad), em 13 cria um ponteiro chamado temp (Tree), que vai receber a sub-árvore do lado direto do nó a ser removido, ou seja, o campo sad de t. 
		
Com 12 sendo verdadeiro, em 14 utiliza o comando free sobre o nó t, para realmente libera-lo da memória e da estrutura da árvore.
Com 12 sendo verdadeiro, em 15 retorna temp (que era a antiga sub-árvore a direita do nó que foi removido) para que dentro do case (case 5) que chamou a função removeTree, seja atualiza o nó da sub-árvore. 
	
Considerando 8 verdadeiro, 9 e 12 falsos, no else if em 16 verifica se a sub-árvore a direta não existe (sad), ou seja, se o campo sad de t é igual a NULL, se sim executa o seguinte código.
		
Caso 16 seja verdadeiro, ou seja, só existe a sub-árvore a esquerda (sae), vai executar os mesmos passos e a mesma lógica das linhas 13, 14 e 15, só que agora para a sub-árvore a esquerda do nó a ser removido. 
		
		
Considerando 8 verdadeiro e todos os outros ifs e elses acima falsos, se encaixa no caso 3, que vai ser quando o nó a ser removido possui duas sub-árvores, tanto esquerda (sae), quanto direita (sad). Vai executar os seguintes códigos. 
	
Com 8 verdadeiro, em 20 cria-se o ponteiro chamado temp (Tree) que vai chamar e armazenar o resultado da função encontrar_minimo, passando como argumento a sub-árvore a direita (sad), encontrar_minimo vai buscar e retornar o menor valor da sub-árvore que armazena os maiores valores de t, esse valor que vai ser retornado por encontrar_minimo é o sucessor em ordem do no a ser removido. 
	
Das linhas 21 a 23 copia-se os dados (prioridade, id, nome) do sucessor de t (que é temp) para o nó atual.
	
Em 24, a sub-árvore a direita (sad) chama removeTree de forma recursiva passando como argumentos a sub-árvore a direita, a prioridade de temp e o id de temp. Isso é feito por que temp (o sucessor do nó removido) foi clonado para t, então é necessário remover ele, e remove ele porque como ele é o menor nó da sub-árvore a direta, ou seja, ele não possui sub-árvore filha a esquerda, o que facilita a remoção dele, e não a remoção "direta" do nó pai (antigo nó t.)
	
Em 25 retorna t para atualizar a árvore, no case principal que chamou a função removeTree (case 5).


