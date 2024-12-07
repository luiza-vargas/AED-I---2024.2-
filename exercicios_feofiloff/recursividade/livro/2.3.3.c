/*2.3.3 Soma. Escreva uma função recursiva que calcule a soma dos elementos positivos
do vetor de inteiros v[0 . . n−1].*/

        int somatorio(int v[],int n){
            if(n==0){
                return v[0];
            }
            if (v[n-1]>0){
              return n + somatorio(v,n-1);
            }  else {
              return somatorio(v, n - 1);
            }
        }
