#include<stdlib.h>
  //heapsort - max heap- o pai [e o maior elemento

  /* Esta função recebe um max-heap v[1..m] e transforma
  * v[1..m+1] em max-heap. */
  void insere_heap(int m, int v[]){
    int f= m+1;
    while(f>1 && v[f/2]<v[f]){ // se o filho e maior que o pai, troca a posição
        int t= v[f/2];
        v[f/2]=v[f];
        v[f]=t;
        f=f/2;
    }
  }
  /* Rearranja um quase max-heap v[1..m] de modo a
  * transformá-lo em um max-heap. */
  // seleciona o maior entre os filhos, e se for maior q o pai, troca de posicao 
  void sacode_heap(int m, int v[]){
    int t,f=2;
    while(f<=m){
        if(f<m && v[f]<v[f+1]){// ve se o filho a direita e maior do que o filho da esq, se sim, aponta p da dir
            f++; // aponta p maior
        }
        if(v[f/2]>=v[f]){ // se o pai for maior q o filho, ta td certo
            break;
        }// senao troca
        t = v[f/2];
        v[f/2]=v[f];
        v[f]=t;
        f=f*2; //avanca
    }
  }

  void heapsort(int n, int v[]){
    int m;
    for(m=1;m<n;m++){
        insere_heap(m,v);
    }
    for(m=n;m>1;m--){
        int t=v[1];
        v[1]=v[m];
        v[m]=t;
        sacode_heap(m-1,v);
    }
  }
