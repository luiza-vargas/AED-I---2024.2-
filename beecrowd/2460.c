    #include <stdio.h>
    #include <stdlib.h>

    typedef struct cel {
        int identificador;
        struct cel* prox;
    } celula;

    void insere(int x, celula** ini, celula** fim) {
        celula* nova = malloc(sizeof(celula));
        nova->identificador = x;
        nova->prox = NULL;
        
        if (*fim == NULL) {
            *ini = *fim = nova;
        } else {
            (*fim)->prox = nova;
            *fim = nova;
        }
    }

    void removePessoa(celula** ini, celula** fim, int x) {
        if (*ini == NULL) {
            return;
        }

        celula* aux = *ini;
        celula* ant = NULL;
        
        while (aux != NULL && aux->identificador != x) {
            ant = aux;
            aux = aux->prox;
        }

        if (aux == NULL) {
            return;
        }

        if (ant == NULL) {
            *ini = aux->prox;
        } else {
            ant->prox = aux->prox;
        }

        if (aux == *fim) {
            *fim = ant;
        }

        free(aux);
    }

    void imprimeFila(celula* ini) {
        celula* temp = ini;
        int primeiro = 1;
        
        while (temp != NULL) {
            if (!primeiro) {
                printf(" ");
            }
            printf("%d", temp->identificador);
            primeiro = 0;
            temp = temp->prox;
        }
        printf("\n");
    }

    void liberaFila(celula* ini) {
        celula* temp;
        while (ini != NULL) {
            temp = ini;
            ini = ini->prox;
            free(temp);
        }
    }

    int main() {
        int N, M;
        scanf("%d", &N);
        
        celula *ini = NULL, *fim = NULL;
    
        for (int i = 0; i < N; i++) {
            int id;
            scanf("%d", &id);
            insere(id, &ini, &fim);
        }

        scanf("%d", &M);
        
        for (int i = 0; i < M; i++) {
            int id;
            scanf("%d", &id);
            removePessoa(&ini, &fim, id);
        }

        imprimeFila(ini);
        liberaFila(ini);

        return 0;
    }
