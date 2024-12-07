/*Escreva uma função recursiva eciente que receba inteiros
positivos k e n e calcule o valor de k n.*/

        int exp(int x, int n){
            if (n==0){
                return 1;
            }
            return x * exp(x,n-1);
        }
