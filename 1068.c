 #include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    char dado;
    struct cel *prox;
} celula;

void empilha(char info, celula *p) {
    celula *nova;
    nova = malloc(sizeof(celula));
    nova->dado = info;
    nova->prox = p->prox;
    p->prox = nova;
}

char desempilha(celula *p) {
    char x;
    celula *q;
    q = p->prox;
    x = q->dado;
    p->prox = q->prox;
    free(q);
    return x;
}

void libera(celula *p) {
    celula *aux;
    for (aux = p; aux != NULL; p = aux) {
        aux = aux->prox;
        free(p);
    }
}

int verifica(char *expressao) {
    celula aux; // Nao tem ponteiro pq ela e a cabeca
    aux.prox = NULL;
    int i;
    char c;

    // Processa cada caractere da expressão
    for (i = 0; expressao[i] != '\0'; i++) {
        c = expressao[i];

        if (c == '(') {
            empilha(c, &aux);  // Empilha '('
        } else if (c == ')') {
            if (aux.prox == NULL) { 
               
                return 0; // Errado
            }
            // Desempilha quando encontrar ')'
            desempilha(&aux);
        }
        // Ignora qualquer outro caractere (não parênteses)
    }

    // Verifica se a pilha está vazia (todos os parênteses foram fechados)
    if (aux.prox == NULL) {
        return 1; // Certo
    } else {
        libera(aux.prox);
        return 0; // Errado
    }
}

int main() {
    char expressao[1000];
    int count=0;
    do{
    fgets(expressao, 1000, stdin);
    
    if (expressao[0]!='\n' &&verifica(expressao)) {
        printf("correct\n");
    } else if (expressao[0]!='\n') {
        printf("incorrect\n");
    }
    count++;
    }while(count<10000 && expressao[0]!='\n');
    return 0;
}
