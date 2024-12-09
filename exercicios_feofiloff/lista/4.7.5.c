/*Escreva uma função que decida se duas listas dadas têm o mesmo
conteúdo.*/

int sao_iguais (celula*p,celula*q){
   while(p!=NULL && q!=NULL){
    if(p->dado != q->dado){
        return 0; // diferentes
    }
    p=p->prox;
    q=q->prox;  
}
  if (p == NULL && q == NULL) {
        return 1;  // iguais
    }
    return 0; 
}
