    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h> // clock(), CLOCKS_PER_SEC e clock_t

    void insercao(int N, int v[]) {
        int i, j, aux;
        for (j = 1; j < N; j++) {
            aux = v[j];
            for (i = j - 1; i >= 0 && v[i] > aux; i--) {
                v[i + 1] = v[i];
            }
            v[i + 1] = aux; 
        }
    }

    int main() {
        clock_t t; // variavel para armazenar tempo
        int *vetor;
        int tamanho;

        // gera a semente de aleatoriedade
        srand((unsigned)time(NULL));
        
        printf(" tamanho      tempo \n");
        
        for (tamanho = 0; tamanho <= 400000; tamanho += 20000) {
            // aloca dinamicamente o vetor com o tamanho atual
            vetor = (int *)malloc(tamanho * sizeof(int));
            if (vetor == NULL) {
                printf("Erro ao alocar memoria.\n");
                return 1;
            }
            
            
            // geracao aleatoria dos valores do vetor
            for (int a = 0; a < tamanho; a++)
                vetor[a] = rand() % tamanho;

            // mede o tempo de execucao do Insertion Sort
            t = clock(); // armazena tempo inicial
            insercao(tamanho, vetor);
            t = clock() - t; // calcula o tempo final

            // imprime o tempo em segundos
        
            printf(" %d             %.6f s\n", tamanho, ((double)t) / CLOCKS_PER_SEC);

            // libera o vetor
            free(vetor);
        }

        return 0;
    }
