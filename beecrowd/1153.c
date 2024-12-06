    #include <stdio.h>
    int fatorial (int n){
        int fat;
        //caso base, n=1
        if (n<=1){
            return 1;
        }
        else{
            fat= n* fatorial(n-1);
            return (fat);
        }
    }
    
    int main() {
    int n;
    scanf("%d",&n);
    printf("%d\n",fatorial(n));
    
    
        return 0;
    }
