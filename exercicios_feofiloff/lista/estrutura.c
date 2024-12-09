       // estrutura
       struct cel{
        int dado;
        struct cel* prox; // aponta p prox elemento
       };

       // vamos tratar as celulas como um novo tipo de dados
       typedef struct cel celula;

       void insere(int x,celula *p){
        celula*nova;
        nova= malloc(sizeof(celula));
        nova->dado=x;
        nova->prox=p->prox;
        p->prox=nova;
        //insere no final
       }

       // sem cabeca
       void imprime (celula *p){
        celula *aux;
        for(aux=p;p!=NULL;aux=aux->prox){
            printf("%d\n",aux->dado);
        }
       }

        //lista com cabeca, a primeira so marca o inicio da lista
        void imprime (celula *p){
        celula *aux;
        for(aux=p->prox;p!=NULL;aux=aux->prox){
            printf("%d\n",aux->dado);
        }
       }

      // versao recursiva
      void imprimeR(celula *p){
        if(p==NULL){
          return 1;
        }
        printf("%d\n",l->dado);
        imprimeR(p->prox);
      }

       //com cabeca
       celula *busca(int x,celula*p){
        celula*aux;
        aux=p->prox;
        for(aux=p->prox;p!=NULL;aux=aux->prox){
            if(p->dado==x){
                return p; // retorna o endereco do no
            }
        }
       }

       // versao recursiva c cabeca
       celula *busca_recursiva(int x, celula *p){
        if(p->prox==NULL){
            return NULL;
        }
        if(p->prox->dado==x){
            return p->prox;
        }
        return busca_recursiva(x,p->prox);
       }

       void remove (celula *p){
        celula *aux;
        aux=p->prox;
        p->prox=aux->prox;
        free(aux);
       }
       /* Esta função recebe uma lista encadeada lst com cabeça
        * e remove da lista a primeira célula que contiver x,
         se tal célula existir. */

        void busca_remove(int x, celula*p){
            celula*ant,*q;
            ant=p;
            q=p->prox;
            while(q!=NULL && q->dado!=x){
                ant=q;
                q=q->prox;
            }
            if(q!=NULL){//achamos o elemento
                ant->prox=q->prox;
                free (q);
            }
        }

        /* Recebe uma lista encadeada lst com cabeça e insere uma
* nova célula na lista imediatamente antes da primeira que
* contiver x. Se nenhuma célula contiver x, a nova célula
* será inserida no fim da lista. A nova célula terá
* conteúdo y. */
        void busca_insere(int y, int x, celula*p){
            celula *ant,*q,*nova;
            nova=malloc(sizeof(celula));
            nova->dado=y;
            ant=p;
            q=p->prox;
            while(q!=NULL && q->dado!=x){
                ant=q;
                q=q->prox;
            }
            nova->prox=q;
            p->prox=nova;
        }

