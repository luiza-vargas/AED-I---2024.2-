    #include <stdio.h>
    #include <string.h>

    int main() {
        const int MAX_T = 100;       // Limite máximo de conexões
        const int MAX_NAME = 31;    // Tamanho máximo do nome das ilhas
        int T;

        while (1) {
            scanf("%d", &T);
            if (T == 0) break;

            // Armazenar conexões no formato X -> Y
            char X[MAX_T][MAX_NAME];
            char Y[MAX_T][MAX_NAME];
            int isFunction = 1, isInvertible = 1;

            // Ler as conexões
            for (int i = 0; i < T; i++) {
                scanf("%s -> %s", X[i], Y[i]);
            }

            // Verificar se é uma função
            for (int i = 0; i < T; i++) {
                for (int j = i + 1; j < T; j++) {
                    if (strcmp(X[i], X[j]) == 0 && strcmp(Y[i], Y[j]) != 0) {
                        isFunction = 0; // Não é uma função
                        break;
                    }
                }
                if (!isFunction) break;
            }

            // Verificar se é invertível
            if (isFunction) {
                for (int i = 0; i < T; i++) {
                    for (int j = i + 1; j < T; j++) {
                        if (strcmp(Y[i], Y[j]) == 0 && strcmp(X[i], X[j]) != 0) {
                            isInvertible = 0; // Não é invertível
                            break;
                        }
                    }
                    if (!isInvertible) break;
                }
            }

            // Imprimir o resultado
            if (!isFunction) {
                printf("Not a function.\n");
            } else if (isInvertible) {
                printf("Invertible.\n");
            } else {
                printf("Not invertible.\n");
            }
        }

        return 0;
    }
