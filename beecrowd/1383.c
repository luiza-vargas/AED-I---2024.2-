    /* Luiza Claro Vargas
    RA: 168982 */

    #include <stdio.h>

    // percorre todas as linhas da matriz e ve se tem valores repetidos 

    int verifica_linha_99(int matriz[9][9]) {
        int i, j, k;

        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                if (matriz[i][j] > 9 || matriz[i][j] < 1) {  // verifica se algum número maior que 9 ou menor que 1
                    return 0;
                }

                for (k = j + 1; k < 9; k++) {
                    if (matriz[i][j] == matriz[i][k]) {
                        return 0;
                    }
                }
            }
        }
        return 1;
    }

    // percorre todas as colunas da matriz e ve se tem valores repetidos 

    int verifica_coluna_99(int matriz[9][9]) {
        int i, j, k;

        for (j = 0; j < 9; j++) {
            for (i = 0; i < 9; i++) {
                for (k = 0; k < 9; k++) {
                    if (i != k && matriz[i][j] == matriz[k][j]) {
                        return 0;
                    }
                    if (matriz[i][j] > 9 || matriz[k][j] > 9) {
                        return 0;
                    }
                }
            }
        }
        return 1;
    }

    // cria uma matriz 3x3 e dps chama uma função que verifica se tem valores iguais nela

    int monta_matriz_33(int matriz[9][9]) {
        int i, j, k, l;
        int nova[3][3];

        for (i = 0; i < 9; i += 3) {
            for (j = 0; j < 9; j += 3) {
                for (k = 0; k < 3; k++) {
                    for (l = 0; l < 3; l++) {
                        nova[k][l] = matriz[k + i][l + j];
                    }
                }
                if (verifica_matriz_33(nova) != 1) {
                    return 0;
                }
            }
        }
        return 1;
    }

    /* variavel num vale de 1 a 9 e cada ocorrencia, sua qnt aumenta. Se a qnt for maior q 1, significa que tem valores repetidos 
    e nao pode formar um sudoku */

    int verifica_matriz_33(int nova[3][3]) {
        int num, i, j, qnt;

        for (num = 1; num <= 9; num++) {
            qnt = 0;
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    if (nova[i][j] == num) {
                        qnt++;
                    }
                }
            }
            if (qnt > 1) {
                return 0;
            }
        }
        return 1;
    }

    int main() {
        int n, i, j, matriz[9][9], aux;
        scanf("%d", &n);

        for (aux = 1; aux <= n; aux++) {
            for (i = 0; i < 9; i++) {
                for (j = 0; j < 9; j++) {
                    scanf("%d", &matriz[i][j]);
                }
            }

            printf("Instancia %d\n", aux);

            if (verifica_linha_99(matriz) && verifica_coluna_99(matriz) && monta_matriz_33(matriz)) {
                printf("SIM\n");
            } else {
                printf("NAO\n");
            }
            printf("\n");
        }
        return 0;
    }
