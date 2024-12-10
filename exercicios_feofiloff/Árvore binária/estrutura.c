#include<stdlib.h>
// arvore binaria
struct cel{
    int info;
    struct cel*esq;
    struct cel*dir;
};
typedef struct cel no;
typedef no *arvore;

arvore cria(int x, arvore esq, arvore dir){
    arvore novo =(arvore)malloc(sizeof(no));
    novo->info= x;
    novo->esq=esq;
    novo->dir=dir;
    return novo;
}

// impressao- varredura ERD
void impressao_ERD( arvore r){
    if(r!=NULL){
        impressao_ERD(r->esq);
        printf("%d\n",r->info);
        impressao_ERD (r->dir);
    }
}

//altura 
int altura(arvore r){
    if (r==NULL){
        return -1; // altura arvore vazia
    }
    else{
        int he= altura(r->esq);
        int hd= altura(r->dir);
        if(he<hd){
            return hd+1;
        }
        else{
            return he+1;
        }
    }
}

//estrutura de no com o campo pai
struct cel{
    int dado;
    struct cel*pai;
    struct cel*esq;
    struct cel*dir;
};
typedef struct cel no;
typedef no* arvore_pai;

no*seguinte (no*x){
    if(x->dir!=NULL){
        no*y=x->dir;
        while(y->esq!=NULL){
            y=y->esq;
        }
        return y;
    }
    while(x->pai !=NULL&& x->pai->dir==x)
        x=x->pai;
    return x->pai;
    
}
