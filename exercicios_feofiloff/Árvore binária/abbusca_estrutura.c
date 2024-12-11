    // arvore binaria de busca
    struct cel{
        int chave;
        int conteudo;
        struct cel*esq;
        struct cel*dir;
    };
    typedef struct cel no;
    typedef no* arvore;

    arvore insere(arvore r, int k){
        no *novo = malloc(sizeof(no));
        novo->chave=k;
        novo->esq=novo->dir=NULL;
        no *f,*p;
        f=r;
        if(r==NULL){
            return novo;
        }
        while(f!=NULL){
            p=f;
            if(f->chave > novo->chave){
                f=f->esq;
            }
            else{
                f=f->dir;
            }
        }// essa interacao para qnd f e nulo, dai temos q usar o nosso p
        if(p->chave > novo->chave){
            p->esq=novo;
        }else{
            p->dir=novo;
        }
        return r;
    }

    /* Recebe k e uma árvore de busca r. Devolve um nó cuja
    * chave é k ou devolve NULL se tal nó não existe. */
    no *busca (arvore r, int k){
        if(r==NULL || r->chave == k){
            return r;
        }
        if(r->chave >k){
            return busca (r->esq,k);
        }
        else{
            return busca(r->dir,k);
        }
    }

    /* Recebe uma árvore não vazia r, remove a raiz da árvore
    * e rearranja a árvore de modo que ela continue sendo
    * de busca. Devolve o endereço da nova raiz. */

    arvore remove_raiz(arvore r){
        no *p, *q;
        if(r->esq ==NULL){
            q=r->dir;
        }
        else{
            p=r;
            q=r->esq;
            while(q->dir!=NULL){
                p=q;
                q=q->dir;
            }
            if(p != r){
                p->dir= q->esq;
                q->esq = r->esq;
            }
            q->dir= r->dir;
        }
        free (r);
        return q;
    }
