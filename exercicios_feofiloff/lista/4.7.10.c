/*Escreva uma função que aplique a função free a todas as células de uma lista encadeada. Estamos supondo, 
é claro, que cada célula da lista foi originalmente alocado por malloc.*/

    void libera( celula*p){
        celula*aux=p;

        for(aux=p;aux!=NULL;aux=p){
            p=p->prox;
            free(aux);
        }
    }
