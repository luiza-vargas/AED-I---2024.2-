    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

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

        for (i = 0; expressao[i] != '\0'; i++) {
            c = expressao[i];

            if (c == '(') {
                empilha(c, &aux);  // se tem '(' coloca ele na pilha
            } else if (c == ')') {
                if (aux.prox == NULL) { // se ta vazia, ')' nao tem correspondente
                    libera(aux.prox);
                    return 0; 
                }
                desempilha(&aux);
            }
        }

        if (aux.prox == NULL) {
            return 1; // certinho
        } else {
            libera(aux.prox);
            return 0; // errado
        }
    }

    int main() {
        char expressao[1001];
        int count = 0;

        while (count < 10000 && fgets(expressao, 1000, stdin)) {
            // Remover o caractere de nova linha se estiver presente
            if (expressao[strlen(expressao) - 1] == '\n') {
                expressao[strlen(expressao) - 1] = '\0';
            }
            
            if (expressao[0] != '\0') {
                if (verifica(expressao)) {
                    printf("correct\n");
                } else {
                    printf("incorrect\n");
                }
                count++;
            }
        }

        return 0;
    }

    /*
    1. **Memória Liberada**:
    A função `libera` é chamada sempre que a pilha tem elementos remanescentes após a verificação, tanto na condição de erro quanto no final da verificação correta.
    
    2. **Remoção do `\n`**:
    Usei `strlen` para verificar e remover o caractere de nova linha `\n`, garantindo que as entradas estejam corretas.
    */
