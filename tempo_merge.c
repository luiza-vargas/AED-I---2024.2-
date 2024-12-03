    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h> // clock(), CLOCKS_PER_SEC e clock_t

    // Função de intercalação do MergeSort
    void Intercala(int p, int q, int r, int v[]) {
        int i, j, k, *w;

        // Aloca espaço para o vetor auxiliar
        w = malloc((r - p) * sizeof(int));
        i = p;
        j = q;
        k = 0;

        // Combina os dois subarrays ordenados
        while (i < q && j < r) {
            if (v[i] <= v[j]) {
                w[k++] = v[i++];
            } else {
                w[k++] = v[j++];
            }
        }

        // Copia os elementos restantes do primeiro subarray (se houver)
        while (i < q) {
            w[k++] = v[i++];
        }

        // Copia os elementos restantes do segundo subarray (se houver)
        while (j < r) {
            w[k++] = v[j++];
        }

        // Copia os elementos intercalados para o vetor original
        for (i = p; i < r; i++) {
            v[i] = w[i - p];
        }

        free(w);
    }

    // Função principal do MergeSort
    void Mergesort(int p, int r, int v[]) {
        if (p < r - 1) {
            int q = (p + r) / 2;

            // Recursivamente ordena o subarray esquerdo
            Mergesort(p, q, v);

            // Recursivamente ordena o subarray direito
            Mergesort(q, r, v);

            // Intercala os dois subarrays ordenados
            Intercala(p, q, r, v);
        }
    }

    int main() {
        clock_t t; // variável para armazenar tempo
        int *vetor;

        printf("Tamanho\tTempo (s)\n");

        // Itera sobre tamanhos de vetor de 0 até 400.000 (incrementando 20.000)
        for (int tamanho = 0; tamanho <= 400000; tamanho += 20000) {
            // Aloca dinamicamente o vetor
            vetor = (int *)malloc(tamanho * sizeof(int));
            if (vetor == NULL && tamanho > 0) {
                printf("Erro ao alocar memoria para tamanho %d.\n", tamanho);
                return 1;
            }

            // Gera a semente de aleatoriedade
            srand((unsigned)time(NULL));

            // Geração aleatória dos valores do vetor (ignorado se tamanho == 0)
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

            // Libera a memória alocada (exceto para tamanho == 0)
            if (tamanho > 0) {
                free(vetor);
            }
        }

        return 0;
    }
