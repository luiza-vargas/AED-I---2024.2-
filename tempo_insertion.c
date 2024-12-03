#include <stdio.h>
#include <stdlib.h>
#include <time.h> // clock(), CLOCKS_PER_SEC e clock_t

// Função de Insertion Sort
void insercao(int N, int v[]) {
    int i, j, aux;
    for (j = 1; j < N; j++) {
        aux = v[j];
        for (i = j - 1; i >= 0 && v[i] > aux; i--) {
            v[i + 1] = v[i];
        }
        v[i + 1] = aux; // Coloca o valor correto na posição
    }
}

int main() {
    clock_t t; // variável para armazenar tempo
    int *vetor;
    int tamanho;

    // Gera a semente de aleatoriedade
    srand((unsigned)time(NULL));

    // Loop para testar tamanhos de vetor de 50.000 a 400.000
    for (tamanho = 50000; tamanho <= 400000; tamanho += 50000) {
        // Aloca dinamicamente o vetor com o tamanho atual
        vetor = (int *)malloc(tamanho * sizeof(int));
        if (vetor == NULL) {
            printf("Erro ao alocar memoria.\n");
            return 1;
        }

        // Geração aleatória dos valores do vetor
        for (int a = 0; a < tamanho; a++)
            vetor[a] = rand() % tamanho;

        // Medindo o tempo de execução do Insertion Sort
        t = clock(); // armazena tempo inicial
        insercao(tamanho, vetor);
        t = clock() - t; // calcula o tempo final

        // Imprime o tempo em segundos
        printf("Tamanho: %d, Tempo de execucao: %.6f s\n", tamanho, ((double)t) / CLOCKS_PER_SEC);

        // Libera o vetor
        free(vetor);
    }

    return 0;
}

