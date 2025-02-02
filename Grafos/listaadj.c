#include <stdio.h>
#include <stdlib.h>

struct no{
    int vertice;
    int peso;
    int no*prox;
};
typedef struct no*No;

struct grafo{
    int numv;
    No**adj;
};

Grafo iniciagrafo(int v){
    int i;
    Grafo G= malloc(sizeof*G);
    G->numv=v;
    G->adj=malloc(v*sizeof(No*));
    for(i=0;i<n;i++){
        G->adj[i]=NULL;
    }
    return G;
}

void inserearco(Grafo G, int v, int w,int peso){
    No*p;
    //ver se ja ta inserido
    for(p=G->adj[v];p!=NULL;p=p->prox){
        if(p-> vertice==w){
            return;
        }
    }
    p=malloc(sizeof(No));
    p-> vertice = w;
    p->peso= peso;
    p->prox= G->adj[v];
    G->adj[v]=p;

}


