	#include <stdio.h>

	int is_prime(long long num) {
		if (num < 2) return 0;
		for (long long i = 2; i * i <= num; i++) {
			if (num % i == 0) return 0;
		}
		return 1;
	}

	int main() {
		int M, N;
		while (scanf("%d", &M) != EOF) {
			int moedas[M];
			for (int i = 0; i < M; i++) {
				scanf("%d", &moedas[i]);
			}
			scanf("%d", &N);

			long long soma = 0;
			for (int i = M - 1; i >= 0; i -= N) {
				soma += moedas[i];
			}

			if (is_prime(soma)) {
				printf("You’re a coastal aircraft, Robbie, a large silver aircraft.\n");
			} else {
				printf("Bad boy! I’ll hit you.\n");
			}
		}
		return 0;
	}
