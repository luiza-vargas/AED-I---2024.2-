/* Escreva uma função recursiva que calcule log2 n, ou seja,
o piso do logaritmo de n na base 2.*/
        int log(int n){
            if (n<2){
                return 0;
            }
            return 2+ log (n/2);
        }
