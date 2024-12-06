    #include <stdio.h>
    #include <stdlib.h>

    typedef struct FILA {
        int valor;
        struct FILA *prox;
    } fila;


    void insere_fila(int x, fila **ini, fila **fim) {
        fila *nova = (fila *)malloc(sizeof(fila));
        nova->valor = x;
        nova->prox = NULL;
        
        if (*fim == NULL) {
            *ini = *fim = nova;
        } 
        else {
            (*fim)->prox = nova;
            *fim = nova;
        }
    }

    int remove_fila(fila **ini, fila **fim) {
        if (*ini == NULL) {
            return -1;
        }
        
        fila *aux = *ini;
        int x = aux->valor;
        *ini = aux->prox;
        free(aux);
        
        if (*ini == NULL) {
            *fim = NULL;
        }
        return x;
    }

    void cria_carta(int n, fila **ini, fila **fim) {
        for (int i = 1; i <= n; i++) {
            insere_fila(i, ini, fim);
        }
    }

    void processa_cartas(int n) {
        fila *ini = NULL, *fim = NULL;

        cria_carta(n, &ini, &fim);

        int descartadas[50];
        int contador_descartadas = 0;

        while (ini != fim) { // ate ter mais de uma carta
            
            descartadas[contador_descartadas++] = remove_fila(&ini, &fim);
            
            insere_fila(remove_fila(&ini, &fim), &ini, &fim);
        }
        
        printf("Discarded cards: ");
        for (int i = 0; i < contador_descartadas; i++) {
            if (i > 0) printf(", ");
            printf("%d", descartadas[i]);
        }
        printf("\nRemaining card: %d\n", ini->valor);

        free(ini);
    }

    int main() {
    int n;

        scanf("%d", &n);

        while (n != 0) {
            processa_cartas(n);
            scanf("%d", &n); 
        }

        return 0;
    }
