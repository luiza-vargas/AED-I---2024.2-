    #include <stdio.h>
    #include <string.h>

    #define MAX_LENGTH 2001

    // Função para compactar uma linha de texto
    void compactar_linha(char *linha) {
        int i = 0;
        int n = strlen(linha);

        while (i < n) {
            if (linha[i] == '0') {
                // Verifica se é uma sequência de zeros
                int j = i;
                while (j < n && linha[j] == '0') {
                    j++;
                }
                int comprimento = j - i;

                if (comprimento > 2) {
                    // Compacta a sequência de zeros
                    while (comprimento > 0) {
                        int bloco = (comprimento > 255) ? 255 : comprimento;
                        printf("#%c", (char)bloco); // Usa o caractere ASCII correspondente
                        comprimento -= bloco;
                    }
                    i = j;
                } else {
                    // Não compacta sequências curtas
                    for (int k = i; k < j; k++) {
                        printf("%c", linha[k]);
                    }
                    i = j;
                }
            } else if (linha[i] == ' ') {
                // Verifica se é uma sequência de espaços
                int j = i;
                while (j < n && linha[j] == ' ') {
                    j++;
                }
                int comprimento = j - i;

                if (comprimento > 2) {
                    // Compacta a sequência de espaços
                    while (comprimento > 0) {
                        int bloco = (comprimento > 255) ? 255 : comprimento;
                        printf("$%c", (char)bloco); // Usa o caractere ASCII correspondente
                        comprimento -= bloco;
                    }
                    i = j;
                } else {
                    // Não compacta sequências curtas
                    for (int k = i; k < j; k++) {
                        printf("%c", linha[k]);
                    }
                    i = j;
                }
            } else {
                // Caracteres normais
                printf("%c", linha[i]);
                i++;
            }
        }
        printf("\n"); // Nova linha após cada caso de teste
    }

    int main() {
        int N;
        scanf("%d", &N); // Lê o número de casos de teste
        getchar(); // Consome o '\n' após o número

        for (int i = 0; i < N; i++) {
            char linha[MAX_LENGTH];
            fgets(linha, MAX_LENGTH, stdin); // Lê a linha de texto

            // Remove o '\n' no final da linha, se houver
            linha[strcspn(linha, "\n")] = '\0';

            // Compacta e imprime a linha
            compactar_linha(linha);
        }

        return 0;
    }
