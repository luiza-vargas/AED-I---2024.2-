    #include <stdio.h>
    #include <stdlib.h>

    // Protótipos
    void Intercala(int p, int q, int r, int v[]);
    void MergeSort(int p, int r, int v[]);

    void Intercala(int p, int q, int r, int v[]) {
        int i = p, j = q, k = 0;
        int *w = malloc((r - p) * sizeof(int)); 

        while (i < q && j < r) {
            if (v[i] >= v[j]) 
                w[k++] = v[i++];
            else
                w[k++] = v[j++];
        }

        while (i < q)
            w[k++] = v[i++];

        while (j < r)
            w[k++] = v[j++];

        for (i = p; i < r; i++)
            v[i] = w[i - p];

        free(w); 
    }

    void MergeSort(int p, int r, int v[]) {
        if (p < r - 1) { 
            int q = (p + r) / 2; 

            MergeSort(p, q, v); 
            MergeSort(q, r, v); 
            Intercala(p, q, r, v);
        }
    }

    int main() {
        int N, M, resposta;
        int original[1000], ordenado[1000];
      
        scanf("%d", &N);

        for (int k = 0; k < N; ++k) {
            // Lê o tamanho do vetor
            scanf("%d", &M);

            for (int i = 0; i < M; ++i) {
                scanf("%d", &original[i]); // Lê o vetor original
                ordenado[i] = original[i]; // Copia para outro vetor
            }

            MergeSort(0, M, ordenado);

            resposta = 0;
            for (int i = 0; i < M; ++i) {
                if (original[i] == ordenado[i])
                    ++resposta;
            }

            printf("%d\n", resposta);
        }

        return 0;
    }
