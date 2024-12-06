        //potencia
        #include<stdio.h>
        #include<stdlib.h>

        int potencia(int x,int n){
            if(n==0){
                return 1;
            }
            else{
                 return x * potencia(x,n-1);
            }
         }

        int main(){
            int n,x;
            scanf("%d %d",&x,&n);
            printf("%d elevado a %d : %d",x,n,potencia(x,n));
        }
