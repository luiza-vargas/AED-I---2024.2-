#include <stdio.h>
 
int main() {
    
 int certo,aux,cont=0;
 int resp[5];
 
 scanf("%d",&certo);
 
 for (aux = 0; aux < 5; aux++) {
        scanf("%d", &resp[aux]);
    }
    
 for(aux=0;aux<5;aux++){
     if(certo==resp[aux]){
         cont++;
     }
 }
 
 printf("%d\n",cont);
 
    return 0;
}
