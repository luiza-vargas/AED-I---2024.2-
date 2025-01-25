    #include <stdio.h>
    
    int main() {
    int a,b,c,maiorac,aux;
    scanf("%d %d %d",&a,&b,&c);
    aux=(a+b+abs(a-b))/2;
    
    maiorac=(aux+c+abs(aux-c))/2;

    printf("%d eh o maior\n",maiorac);
        return 0;
    }
