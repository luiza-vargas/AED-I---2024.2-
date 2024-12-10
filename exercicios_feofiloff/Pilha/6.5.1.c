/* Escreva uma função iterativa que simule o comportamento da função recursiva
abaixo. Use uma pilha.
int TTT (int x[], int n) {
if (n == 0) return 0;
if (x[n] > 0) return x[n] + TTT (x, n - 1);
else return TTT (x, n - 1); } */

int soma_pilha(pilha*p){
    if(p==NULL){
        return 0;
    }
    int x=0;
    while(p->prox!= NULL){
        if(p->dado>0){
            x = x + p->dado;
        }
        p=p->prox;
    }
    return x;
}
