    #include <stdio.h>
    #include <stdlib.h>

    #define LINHAS 9

    void preencher_parede(int parede[LINHAS][LINHAS]) {
        for (int i = LINHAS - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                if (parede[i][j] == -1) { // Tijolo em branco
                    parede[i][j] = parede[i + 1][j] + parede[i + 1][j + 1];
                }
            }
        }
    }

    int main() {
        int N;
        scanf("%d", &N); 

        while (N--) {
            int parede[LINHAS][LINHAS];
            for (int i = 0; i < LINHAS; i++) {
                for (int j = 0; j <= i; j++) {
                    parede[i][j] = -1;
                }
            }
            for (int i = 0; i < LINHAS; i += 2) {
                for (int j = 0; j <= i; j += 2) {
                    scanf("%d", &parede[i][j]);
                }
            }
            preencher_parede(parede);

            for (int i = 0; i < LINHAS; i++) {
                for (int j = 0; j <= i; j++) {
                    printf("%d", parede[i][j]);
                    if (j < i) {
                        printf(" ");
                    }
                }
                printf("\n");
            }
        }

        return 0;
    }
