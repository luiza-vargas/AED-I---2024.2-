/*Escreva uma função que copie uma lista encadeada para
um vetor*/

void lista_p_vetor(celula*p,int v[],int tam){
    celula*aux=p;
    int i;
    for(i=0;i<tam;i++){
        if(aux==NULL){
            break;
        }
        v[i]=aux->dado;
        aux=aux->prox;    
    }
}
