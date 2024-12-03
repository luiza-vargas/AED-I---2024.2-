/* quicksort - dividir e conquistar
Rearranjar um vetor v[p . . r] de modo que
os elementos pequenos fiquem todos do lado esquerdo
e os grandes do lado direito.

Rearranjar v[p . . r] de modo que v[p . . j−1] ≤ v[j] < v[j+1 . . r]
para algum j em p . . r.

*/
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
      j = Separa (p, r, v);
      Quicksort (p, j - 1, v);
      Quicksort (j + 1, r, v);
    }
}
