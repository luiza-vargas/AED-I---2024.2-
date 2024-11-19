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
        celula aux; // n tem ponteiro pq ela e a cabeca 
        aux.prox = NULL;
        int i;
        char c;
        
        for (i = 0; expressao[i] != '\0'; i++) {
            c = expressao[i];
            
            if (c == '(') {
                empilha(c, &aux); 
            } else if (c == ')') {
                if (aux.prox == NULL) { 
                    // verifica se ta vazia e nao tem '(' correspondente
                    libera(aux.prox);
                    return 0; // Errado
                }
                // se nao ta vazia, quer dizer que tem '(' correspondente e esvazia aux
                desempilha(&aux);  
            }
        }

        // Ve se a pilha ta vazia
        if (aux.prox == NULL) {
            libera(aux.prox);
            return 1; // certinho
        } else {
            libera(aux.prox);
            return 0; 
        }
    }

    int main() {
        char expressao[1000];

        printf("Digite a expressão: ");
        fgets(expressao, 1000, stdin);

        if (verifica(expressao)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }

        return 0;
    }
