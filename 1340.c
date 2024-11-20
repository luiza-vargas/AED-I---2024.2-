#include <stdio.h>
#include <stdlib.h>

// pilha - ultimo a entrar, primeiro a sair
typedef struct PILHA {
    int valor;
    struct PILHA *prox;
} pilha;

void insere_pilha(int x, pilha **topo) {
    pilha *nova = (pilha *)malloc(sizeof(pilha));
    nova->valor = x;
    nova->prox = *topo;
    *topo = nova;
}

int remove_pilha(pilha **topo) {
    if (*topo == NULL) {
        return -1;
    }
    pilha *aux = *topo;
    int x = aux->valor;
    *topo = aux->prox;
    free(aux);
    return x;
}

/* estrutura da fila - primeiro a entrar, primeiro a sair. 
ponteiros ** para apontar pro inicio e pro fim da fila
funcoes de inserir e remover (q retorna um inteiro)*/

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
    } else {
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

// fila de prioridade
typedef struct FILA_PRIOR {
    int valor;
    struct FILA_PRIOR *prox;
} fila_prior;

void insere_fila_prior(int x, fila_prior **ini, fila_prior **fim) {
    fila_prior *nova = (fila_prior *)malloc(sizeof(fila_prior));
    nova->valor = x;
    nova->prox = NULL;
    if (*fim == NULL) {
        *ini = *fim = nova;
    } else {
        (*fim)->prox = nova;
        *fim = nova;
    }
}

int remove_fila_prior(fila_prior **ini, fila_prior **fim) {
    if (*ini == NULL) { //vazia
        return -1;
    }
    fila_prior *atual = *ini;
    fila_prior *anterior = NULL;
    fila_prior *max = *ini;
    fila_prior *max_anterior = NULL;

    while (atual != NULL) {
        if (atual->valor > max->valor) {
            max = atual;
            max_anterior = anterior;
        }
        anterior = atual;
        atual = atual->prox;
    }

    if (max_anterior == NULL) { //inicio
        *ini = max->prox;
    } else {
        max_anterior->prox = max->prox;
    }

    if (max == *fim) {
        *fim = max_anterior;
    }

    int valor = max->valor;
    free(max);
    return valor;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        pilha *topo_pilha = NULL;
        fila *ini_fila = NULL;
        fila *fim_fila = NULL;
        fila_prior *ini_fila_prior = NULL;
        fila_prior *fim_fila_prior = NULL;

        int possivel_pilha = 1, possivel_fila = 1, possivel_fila_prior = 1;

        for (int i = 0; i < n; i++) {
            int comando, x;
            scanf("%d", &comando);
            if (comando == 1) {
                scanf("%d", &x);
                if (possivel_pilha) insere_pilha(x, &topo_pilha);
                if (possivel_fila) insere_fila(x, &ini_fila, &fim_fila);
                if (possivel_fila_prior) insere_fila_prior(x, &ini_fila_prior, &fim_fila_prior);
            } else if (comando == 2) {
                scanf("%d", &x);
                if (possivel_pilha) {
                    if (remove_pilha(&topo_pilha) != x) possivel_pilha = 0;
                }
                if (possivel_fila) {
                    if (remove_fila(&ini_fila, &fim_fila) != x) possivel_fila = 0;
                }
                if (possivel_fila_prior) {
                    if (remove_fila_prior(&ini_fila_prior, &fim_fila_prior) != x) possivel_fila_prior = 0;
                }
            }
        }

        if (possivel_pilha + possivel_fila + possivel_fila_prior > 1) {
            printf("not sure\n");
        } else if (possivel_pilha) {
            printf("stack\n");
        } else if (possivel_fila) {
            printf("queue\n");
        } else if (possivel_fila_prior) {
            printf("priority queue\n");
        } else {
            printf("impossible\n");
        }
    }

    return 0;
}
