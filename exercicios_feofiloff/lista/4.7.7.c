/*4.7.7 Ponto médio. Escreva uma função que receba uma lista encadeada e devolva
o endereço de uma célula que esteja o mais próximo possível do ponto médio da lista.
Faça isso sem calcular explicitamente o número n de células da lista e o quociente n/2.*/

    celula * ponto_medio(celula*p){
        if(p==NULL){
            return NULL;
        }
        celula * lento = p;
        celula* rapido = p;

        while(rapido!=NULL && rapido->prox!=NULL){
            rapido= rapido->prox->prox; // avanca duas casas
            lento = lento->prox; //avanca uma casa 
        }
        return lento;
    }
