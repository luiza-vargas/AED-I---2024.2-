/*Contagem. Escreva uma função que conte o número de células de uma lista
encadeada.*/
    int num_celulas(celula*p){
        int qntd=1;
        celula*aux;
        for(aux=p;aux!=NULL;aux=aux->prox){
            qntd++;
        }
        return qntd;
    }
