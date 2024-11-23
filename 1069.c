//parecido com o 1068

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel {
    char dado;
    struct cel *prox;
} celula;

void empilha(char info, celula *p) {
    celula *nova = malloc(sizeof(celula));
    nova->dado = info;
    nova->prox = p->prox;
    p->prox = nova;
}

char desempilha(celula *p) {
    if (p->prox == NULL) return '\0';

    char x;
    celula *q = p->prox;
    x = q->dado;
    p->prox = q->prox;
    free(q);
    return x;
}

int conta_diamantes(char *expressao) {
    celula pilha;
    pilha.prox = NULL;
    int diamantes = 0;

    for (int i = 0; expressao[i] != '\0'; i++) {
        char c = expressao[i];

        if (c == '<') {
            empilha(c, &pilha); 
        } else if (c == '>') {
            if (pilha.prox != NULL) { // Se houver um '<' na pilha
                desempilha(&pilha);
                diamantes++; 
            }
        }
    }

    celula *aux;
    while (pilha.prox != NULL) {
        aux = pilha.prox;
        pilha.prox = aux->prox;
        free(aux);
    }

    return diamantes;
}

int main() {
    int N; 
    scanf("%d", &N);
    getchar(); 

    for (int i = 0; i < N; i++) {
        char expressao[1001];
        fgets(expressao, 1001, stdin);

        // Remover o caractere de nova linha, se existir
        if (expressao[strlen(expressao) - 1] == '\n') {
            expressao[strlen(expressao) - 1] = '\0';
        }

        int resultado = conta_diamantes(expressao);
        printf("%d\n", resultado);
    }

    return 0;
}
