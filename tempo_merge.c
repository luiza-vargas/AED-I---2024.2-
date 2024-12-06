    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h> // clock(), CLOCKS_PER_SEC e clock_t

    void Intercala(int p, int q, int r, int v[]) {
        int i, j, k, *w;

        w = malloc((r - p) * sizeof(int));
        i = p;
        j = q;
        k = 0;

        while (i < q && j < r) {
            if (v[i] <= v[j]) {
                w[k++] = v[i++];
            } else {
                w[k++] = v[j++];
            }
        }
        while (i < q) {
            w[k++] = v[i++];
        }

        while (j < r) {
            w[k++] = v[j++];
        }

        for (i = p; i < r; i++) {
            v[i] = w[i - p];
        }

        free(w);
    }

    void Mergesort(int p, int r, int v[]) {
        if (p < r - 1) {
            int q = (p + r) / 2;

            Mergesort(p, q, v);
            Mergesort(q, r, v);
            Intercala(p, q, r, v);
        }
    }

    int main() {
        clock_t t; // variavel para armazenar tempo
        int *vetor;

        printf("Tamanho\tTempo (s)\n");

        for (int tamanho = 0; tamanho <= 400000; tamanho += 20000) {
            // aloca dinamicamente o vetor
            vetor = (int *)malloc(tamanho * sizeof(int));
            if (vetor == NULL && tamanho > 0) {
                printf("Erro ao alocar memoria para tamanho %d.\n", tamanho);
                return 1;
            }

            // gera a semente de aleatoriedade
            srand((unsigned)time(NULL));

            // geracao aleatoria dos valores do vetor (ignorado se tamanho == 0)
            for (int a = 0; a < tamanho; a++) {
                vetor[a] = rand() % tamanho;
            }

            // Medindo o tempo de execução do MergeSort
            t = clock(); // armazena tempo inicial
            if (tamanho > 0) {
                Mergesort(0, tamanho, vetor);
            }
            t = clock() - t; // calcula o tempo final

            // Imprime o tamanho e o tempo em segundos
            printf("%d\t%.6f\n", tamanho, ((double)t) / CLOCKS_PER_SEC);

            // Libera a memoria alocada (exceto para tamanho == 0)
            if (tamanho > 0) {
                free(vetor);
            }
        }

        return 0;
    }
