// achar o maior elemento de um vetor
        //retorna o maior valor do vetor
        #include<stdio.h>
        #include<stdlib.h>

        int maior(int v[],int tam, int indice){
           if (tam==0){
            return v[indice];
           }
           else{
            //compara o ultimo elemento com o nosso primeiro indice=0
            if(v[tam-1]>v[indice]){ // tam-1 e o novo indice
                return maior(v,tam-1,tam-1);
            }
            else{ // ate o elemento comparar ele mesmo
                return maior (v,tam-1,indice);

            }
           }
         }

        int main(){
            int v[10]={1,2,3,4,5,6,7,8,9,10};
             
            printf("maior: %d",maior(v,10,0));
        }
