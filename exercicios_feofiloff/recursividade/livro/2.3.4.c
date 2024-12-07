/*Escreva uma função recursiva que calcule a soma dos dígitos
decimais de um inteiro positivo. A soma dos dígitos de 132, por exemplo, é 6.*/

        int soma_dig(int n){
            if(n>10){
                return n;
            }
            else{
                return (n%10)+ soma_dig(n/10);
            }
        }
