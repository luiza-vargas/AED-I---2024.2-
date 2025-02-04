    #include <stdio.h>

    const char* verifica_pci(int X, int Y, int Xi, int Yi) {
        if ((Xi <= X && Yi <= Y) || (Xi <= Y && Yi <= X)) {
            return "Sim";
        } else {
            return "Nao";
        }
    }

    int main() {
        int X, Y, M;
        int Xi, Yi;

        while (scanf("%d %d %d", &X, &Y, &M) != EOF) {
            for (int i = 0; i < M; i++) {
                scanf("%d %d", &Xi, &Yi);
                const char* resultado = verifica_pci(X, Y, Xi, Yi);
                printf("%s\n", resultado);
            }
        }

        return 0;
    }
