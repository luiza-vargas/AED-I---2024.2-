    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    // Estrutura da célula
    typedef struct cel {
        char nome[21]; 
        int validade;
        struct cel *prox; 
    } celula;

    void insere_ordenado(char *nome, int validade, celula *p) {
        celula *nova = malloc(sizeof(celula));
        strcpy(nova->nome, nome);
        nova->validade = validade;

        celula *ant = p, *atual = p->prox;

        // Busca a posição correta para inserção (ordenada por validade)
        while (atual != NULL && atual->validade < validade) {
            ant = atual;
            atual = atual->prox;
        }

        nova->prox = atual;
        ant->prox = nova;
    }


    void imprime_lista(celula *p) {
        celula *aux = p->prox; 
        int primeiro = 1;

        while (aux != NULL) {
            if (!primeiro) {
                printf(" ");
            }
            printf("%s", aux->nome);
            primeiro = 0;
            aux = aux->prox;
        }
        printf("\n");
    }

    void libera_lista(celula *p) {
        celula *aux;
        while (p != NULL) {
            aux = p;
            p = p->prox;
            free(aux);
        }
    }

    int main() {
        int N;

        while (scanf("%d", &N) != EOF) {
            if (N == 0) {
                printf("\n");
                continue;
            }

            // Criação da lista com cabeça
            celula cabeca;
            cabeca.prox = NULL;

            for (int i = 0; i < N; i++) {
                char nome[21];
                int validade;
                scanf("%s %d", nome, &validade);

                insere_ordenado(nome, validade, &cabeca);
            }

            imprime_lista(&cabeca);

            libera_lista(cabeca.prox);
        }

        return 0;
    }
