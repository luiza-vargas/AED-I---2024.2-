#include<stdlib.h>
//pilha - inserimos no final e o que removemos e o ultimo elemento

struct cel{
    int dado;
    struct cel*prox;
};
typedef struct cel pilha;

void empilha(int y, pilha*p){
    pilha *nova;
    nova=malloc(sizeof(pilha));
    nova->dado=y;
    nova->prox=p->prox;
    p->prox=nova;
}
int desempilha(pilha*p){
    int x;
    pilha *aux;
    aux=p->prox; // o primeiro elemento da pilha real é o segundo
    x=aux->dado;
    p->prox=aux->prox;
    free(aux);
    return x;
}
/*Em uma pilha, o topo é o local onde os elementos são adicionados e
 de onde são removidos. Quando falamos em remover o último elemento inserido, 
 estamos nos referindo ao topo da pilha, e não ao final da lista (se pensarmos 
 na lista como uma sequência linear).*/
