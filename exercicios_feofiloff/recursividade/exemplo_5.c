        //somatorio
        #include<stdio.h>
        #include<stdlib.h>

        int somatoria(int n){
            if(n==0){
                return 0;
            }
            else{
                 return n + somatoria(n-1);
            }
         }
         
        int main(){
            int n;
            scanf("%d",&n);
            printf("somatorio de 1 ate %d : %d",n,somatoria(n));
        }
