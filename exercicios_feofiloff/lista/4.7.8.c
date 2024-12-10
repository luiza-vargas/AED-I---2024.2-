/*Contagem e remoção. Escreva uma função que remova a k-ésima célula de
uma lista encadeada.*/

    void tira_posicao(int n,celula*p){
        celula*aux=p,*ant;
        int cont=1;
        if(n==1){
            p=aux->prox;
            free (aux);
        }
        for(cont=1 ; aux!=NULL&& cont < n; cont ++){
           ant=aux;
           aux=aux->prox;
        }
        if(aux!=NULL){
            ant->prox=aux->prox;
            free(aux);
        }
    }
