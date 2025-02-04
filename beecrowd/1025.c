	#include <stdio.h>
	#include <stdlib.h>

	// Função de comparação para ordenar os mármores em ordem ascendente
	int comparar(const void *a, const void *b) {
		return (*(int *)a - *(int *)b);
	}

	int main() {
		int N, Q, caso = 1;
		while (scanf("%d %d", &N, &Q) && (N != 0 || Q != 0)) {
			int marbles[N];
			for (int i = 0; i < N; i++) {
				scanf("%d", &marbles[i]);
			}

			// Ordena os mármores em ordem ascendente
			qsort(marbles, N, sizeof(int), comparar);

			printf("CASE# %d:\n", caso++);
			for (int i = 0; i < Q; i++) {
				int consulta;
				scanf("%d", &consulta);

				// Busca binária para encontrar a posição do mármore
				int encontrado = 0;
				int esquerda = 0, direita = N - 1;
				while (esquerda <= direita) {
					int meio = (esquerda + direita) / 2;
					if (marbles[meio] == consulta) {
						// Verifica se é a primeira ocorrência
						while (meio > 0 && marbles[meio - 1] == consulta) {
							meio--;
						}
						printf("%d found at %d\n", consulta, meio + 1);
						encontrado = 1;
						break;
					} else if (marbles[meio] < consulta) {
						esquerda = meio + 1;
					} else {
						direita = meio - 1;
					}
				}

				if (!encontrado) {
					printf("%d not found\n", consulta);
				}
			}
		}

		return 0;
	}
