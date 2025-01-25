    #include <stdio.h>

    int main() {
        int N;

        while (1) {

            scanf("%d", &N);
            if (N == 0) break;

            int tempos[N];

            for (int i = 0; i < N; i++) {
                scanf("%d", &tempos[i]);
            }

            int tempo_ativo = 0;
            int fim_ativo = 0;

            for (int i = 0; i < N; i++) {
                if (tempos[i] > fim_ativo) {

                    tempo_ativo += 10;
                    fim_ativo = tempos[i] + 9;
                } else {
        
                    tempo_ativo += (tempos[i] + 9 - fim_ativo);
                    fim_ativo = tempos[i] + 9;
                }
            }
            printf("%d\n", tempo_ativo);
        }

        return 0;
    }
