/*Escreva uma função que copie um vetor para uma lista
encadeada.*/
//inicia com indice=0
celula* insere(int v[],int tam,int indice){
  //criterio de parada
    if(indice>=tam){
        return NULL;
    }
    celula * nova;
    nova=malloc(sizeof(celula));
    nova->dado=v[indice];
    nova->prox=insere(v,tam,indice+1);
    return novo;
}
