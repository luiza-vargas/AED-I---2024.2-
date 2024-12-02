/*Faça um gráfico comparando o desempenho dos algoritmos InsertionSort e MergeSort em ordenação de números inteiros.
O eixo vertical do gráfico deve ser o tempo em segundos e o eixo horizontal o valor de n. A escala de tempo no eixo horizontal deve ir de 0 a 400 mil, de 50 em 50 mil; se quiser, pode aumentar a precisão da escala.

O entregável será o relatório do experimento, em formato PDF, contendo:

1) link para a sua implementação do Insertion.

2) link para a sua implementação do Merge.
3) o gráfico comparativo.

Para evitar distorções na medida, lembre-se de usar vetores com valores inteiros aleatórios. Também pode ser interessante que cada ponto no gráfico seja a média de 03 ou mais execuções*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h> // clock(), CLOCKS_PER_SEC e clock_t

#define TAM 20000 // constante para tamanho do vetor

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

// Função principal
int main() {
    clock_t t; // variável para armazenar tempo
    int vetor[TAM];

    // Gera a semente de aleatoriedade
    srand((unsigned)time(NULL));

    // Geração aleatória dos valores do vetor
    for (int a = 0; a < TAM; a++)
        vetor[a] = rand() % TAM;

    // Verificando tempo de execução do MergeSort
    t = clock(); // armazena tempo inicial
    Mergesort(0, TAM, vetor);
    t = clock() - t; // calcula o tempo final

    // Imprime o tempo na tela
    printf("Tempo de execucao (MergeSort): %lf ms\n", ((double)t) / ((CLOCKS_PER_SEC / 1000))); // conversão para milissegundos

    return 0;
}

