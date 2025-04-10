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

As outras estruturas são as mesmas do outro código, então estão aqui: Implementação da lista encadeada em C. Criar um link aqui.
