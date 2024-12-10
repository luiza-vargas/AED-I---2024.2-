// fila - FIFO - first in, first out
// vai adicionando um atras do outro e pra remover, sai o primeiro
#include<stdlib.h>
struct cel{
    int dado;
    struct cel* prox;
};
typedef struct cel fila;

// sprimeiro
// t ultimo
void cria(){
    fila *ini,*fim;
    ini=fim=NULL;
}
void insere(int y,fila**ini,fila**fim){
    fila*nova;
    nova=malloc(sizeof(fila));
    nova->dado=y;
    nova->prox=NULL;
    if(*fim==NULL){ //vazia
        *fim=*ini=nova;
    }
    else{
        (*fim)->prox=nova;
        *fim=nova;
    }
}

int remove(fila**ini,fila**fim){
    fila *aux;
    int x;
    aux=*ini;
    x=aux->dado;
    *ini=aux->prox;
    free(aux);
    if(*ini==NULL){
        *fim=NULL;
    }
    return x;
}
