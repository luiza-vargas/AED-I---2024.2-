        #include <stdio.h>
        #include <stdlib.h>
        #include <time.h> // clock(), CLOCKS_PER_SEC e clock_t


        // Função de intercalação do MergeSort
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
            clock_t t; // variável para armazenar tempo
            int *vetor;
            int tamanho;

            printf("Digite o tamanho do vetor: ");
            scanf("%d", &tamanho);


            vetor = (int *)malloc(tamanho * sizeof(int));
            if (vetor == NULL) {
                printf("Erro ao alocar memoria.\n");
                return 1;
            }

            // Gera a semente de aleatoriedade
            srand((unsigned)time(NULL));

            // Geração aleatória dos valores do vetor
            for (int a = 0; a < tamanho; a++)
                vetor[a] = rand() % tamanho;

            // Medindo o tempo de execução do MergeSort
            t = clock(); // armazena tempo inicial
            Mergesort(0, tamanho, vetor);
            t = clock() - t; // calcula o tempo final

            // Imprime o tempo em segundos
            printf("Tempo de execucao (MergeSort): %.6f s\n", ((double)t) / CLOCKS_PER_SEC); // conversão para segundos

            return 0;
        }
