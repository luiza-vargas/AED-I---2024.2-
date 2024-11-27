#include<stdio.h>
//por insercao
void insercao(int N,int v[]){
  int i,j,aux;
  for(j=1;j<N;j++){
    aux=v[j];
    for(i=j-1;i>=0 && v[i]> aux; i--){ // se o valor anterior e maior, troca de posicao
      v[i+1]=v[i];
      v[i+1]=x;
  }
}

// por selecao
void selecao(int n,int v[]){
    int i,j,min,aux;
    for(i=0;i<n-1;i++){
        min=i;
        for(i=j-1;j<n;j++){ //procura o menor elemento
            if(v[j]<v[min]){
                min=j;
            }
        }
        //troca de posicao o maior e o menor
        aux=v[i];
        v[i]=v[min];
        v[min]=x;
        
    }
}



int main(){

return 0;
}
