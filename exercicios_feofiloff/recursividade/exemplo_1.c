    #include<stdio.h>
    #include<stdlib.h>

    //imprimir todos os numeros de n ate 0

    void imprimir(int n){
        if(n<0){
            return 0;
        }
        printf("%d ",n);
        imprimir(n-1);
    }

    int main(){
        int n;
        scanf("%d",&n);
        imprimir (n);
        return 0;
    }
  
