/*Escreva uma função que insira uma nova célula com
conteúdo x entre a k-ésima e a (k+1)-ésima células de uma lista encadeada.*/

    void insere_dps(int x,int k,celula*p){
        int cont=1;
        celula*aux=p;
        
        celula*nova;
        nova=malloc(sizeof(celula));
        nova->dado=x;

        if(k==1){
           nova->prox=aux;
        }
         for(cont=1 ; aux!=NULL && cont < k; cont ++){
           aux=aux->prox;
        }
        if(aux!=NULL){
            nova->prox=aux->prox;
            aux->prox=nova;
        }
    }
