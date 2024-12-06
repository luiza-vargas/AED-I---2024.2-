    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

    struct cel {
        char nome[30];
        struct cel* prox;
    };

    typedef struct cel cel;

    cel* insere_fim(cel* velha, cel* nova) {
        if (velha == NULL) return nova;  
        cel* p = velha;
        while (p->prox != NULL) {
            p = p->prox;  
        }
        p->prox = nova;  
        return velha;
    }

    cel* insere_meio(cel* velha, cel* nova, char tira[]) {
        if (strcmp(velha->nome, tira) == 0) {  
            nova->prox = velha;  
            return nova;  
        }
        
        cel* aux1 = velha;
        cel* aux2;
        
        while (aux1 != NULL) {
            if (aux1->prox != NULL && strcmp(aux1->prox->nome, tira) == 0) {
                aux2 = aux1->prox;
                aux1->prox = nova;
                while (nova->prox != NULL) {
                    nova = nova->prox;
                }
                nova->prox = aux2;
                break;
            }
            aux1 = aux1->prox;
        }
        return velha;
    }

    void imprime(cel* velha) {
        cel* aux = velha;
        while (aux != NULL) {
            if (aux->prox != NULL) {
                printf("%s ", aux->nome);  // Imprime o nome seguido de um espaço, se não for o último
            } else {
                printf("%s", aux->nome);  // Não imprime o espaço após o último nome
            }
            aux = aux->prox;
        }
        printf("\n");  
    }

    void libera(cel* velha) {
        cel* aux;
        while (velha != NULL) {
            aux = velha;
            velha = velha->prox;
            free(aux);
        }
    }

    cel* cria_amigo(char* nome) {
        cel* novo = (cel*)malloc(sizeof(cel));
        strcpy(novo->nome, nome);
        novo->prox = NULL;
        return novo;
    }

    cel* cria_lista(char* linha) {
        cel* lista = NULL;
        char* token = strtok(linha, " \n");
        while (token != NULL) {
            lista = insere_fim(lista, cria_amigo(token));
            token = strtok(NULL, " \n");
        }
        return lista;
    }

    int main() {
        char L[500], N[500], S[30];

        fgets(L, sizeof(L), stdin);
        cel* velha = cria_lista(L);

        fgets(N, sizeof(N), stdin);
        cel* nova = cria_lista(N);

        fgets(S, sizeof(S), stdin);
        S[strcspn(S, "\n")] = 0;  // Remove o '\n' que pode ser lido pelo fgets

        if (strcmp(S, "nao") == 0) {
            velha = insere_fim(velha, nova);
        } else {
            velha = insere_meio(velha, nova, S);
        }

        imprime(velha);
        libera(velha);

        return 0;
    }
