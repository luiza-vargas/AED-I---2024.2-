#include <stdio.h>
#include <stdlib.h>

/* MERGESORT 
ideia - dividir para conquistar
divide, um conjunto de dados ate que cada subconjunto tenha 1 elemento
combina dois subconjuntos de forma a obter 1 conjunto maoir e ordenado
se repete ate ter apenas 1 conjunto  */


// Função para intercalar dois subarrays ordenados dentro do vetor v
void Intercala(int p, int q, int r, int v[]) {
    int i, j, k, *w;

    // Aloca espaço para o vetor auxiliar que armazenará os elementos intercalados
    w = malloc((r - p) * sizeof(int));

    // i: índice inicial do primeiro subarray [p, q)
    // j: índice inicial do segundo subarray [q, r)
    // k: índice do vetor auxiliar w
    i = p;
    j = q;
    k = 0;

    // Combina os dois subarrays ordenados
    while (i < q && j < r) {
        if (v[i] <= v[j]) {
            // Se o elemento do primeiro subarray for menor ou igual ao do segundo,
            // adiciona o elemento ao vetor auxiliar
            w[k++] = v[i++];
        } else {
            // Caso contrário, adiciona o elemento do segundo subarray
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

    // Copia os elementos intercalados no vetor auxiliar de volta ao vetor original
    for (i = p; i < r; i++) {
        // (i - p) ajusta o índice para o vetor auxiliar
        v[i] = w[i - p];
    }

    // Libera a memória alocada dinamicamente para o vetor auxiliar
    free(w);
}

// Função principal do Merge Sort
// Ordena o vetor v no intervalo [p, r)
void Mergesort(int p, int r, int v[]) {
    // Verifica se o intervalo contém mais de um elemento
    if (p < r - 1) {
        // Calcula o índice do meio do intervalo [p, r)
        int q = (p + r) / 2;

        // Recursivamente ordena o subarray esquerdo [p, q)
        Mergesort(p, q, v);

        // Recursivamente ordena o subarray direito [q, r)
        Mergesort(q, r, v);

        // Intercala os dois subarrays ordenados
        Intercala(p, q, r, v);
    }
}

