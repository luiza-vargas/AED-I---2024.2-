        #include <stdio.h>
        #include <stdlib.h>
        #include <time.h> // clock(), CLOCKS_PER_SEC e clock_t

            int separa (int ini, int fim, int v[]) {
                int pivo, j, k, t;

                // Escolhe o pivô como o último elemento 
                pivo = v[fim];

                // 'j' marca a próxima posição disponível para um elemento <= pivô
                j = ini;

                // Percorre o vetor do índice 'ini' até 'fim - 1'
                for (k = ini; k < fim; k++) { 
                    if (v[k] < pivo) {
                        // Troca v[k] com o elemento na posição 'j'
                        t = v[j];
                        v[j] = v[k];
                        v[k] = t;

                        // Incrementa 'j' para apontar para a próxima posição disponível
                        j++;
                    }
                }

                // Coloca o pivô na posição correta (índice 'j')
                v[fim] = v[j];
                v[j] = pivo;

                return j; // Retorna o índice final do pivô
        }


            void Quicksort (int p, int r, int v[]) {
                int j;
                if (p < r) {
                j = separa (p, r, v);
                Quicksort (p, j - 1, v);
                Quicksort (j + 1, r, v);
                }
        }

        int main() {
            clock_t t; // variável para armazenar tempo
            int *vetor;

            printf("Tamanho\tTempo (s)\n");

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
                    Quicksort(0, tamanho, vetor);
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
