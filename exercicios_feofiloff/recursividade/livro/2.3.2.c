/*Escreva uma função recursiva que calcule a diferença entre o valor
de um elemento máximo e o valor de um elemento mínimo do vetor v[0..n-1].*/

        int max(int v[],int n){
            if(n==1){
                return v[0];
            }
            else {
                int x = max(v,n-1);
                if(x>v[n-1]){
                    return x;
                }
                else{
                    return v[n-1];
                }
            }
        }
         
        int min(int v[],int n){
            if(n==1){
                return v[0];
            }
            else {
                int x = max(v,n-1);
                if(x<v[n-1]){
                    return x;
                }
                else{
                    return v[n-1];
                }
            }
        }
        int conta( int v[],int n){
            int max= max(v,n);
            int min= min(v,n);
            return max-min;
        }
