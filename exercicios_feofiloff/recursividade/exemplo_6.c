        //somatoria de um vetor de inteiros
        #include<stdio.h>
        #include<stdlib.h>

        int somatoria(int v[],int tam){
            if(tam==0){
                return 0;
            }
            else{  
                 return v[tam-1]+ somatoria(v,tam-1) ;
            }
         }

        int main(){
            int v[10]={1,2,3,4,5,6,7,8,9,10};
             
            printf("soma: %d",somatoria(v,10));
        }
