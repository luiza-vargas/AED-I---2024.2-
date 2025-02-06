    #include <stdio.h>
    #include <stdlib.h>

    int M;

    int mod(int x, int M) {
        return x % M;
    }

    int comparar(const void *a, const void *b) {
        int x = *(int *)a;
        int y = *(int *)b;

        int mod_x = mod(x, M);
        int mod_y = mod(y, M);

        if (mod_x != mod_y) {
            return mod_x - mod_y;
        }

        if ((x % 2 != 0) && (y % 2 == 0)) {
            return -1;
        }
        if ((x % 2 == 0) && (y % 2 != 0)) {
            return 1;
        }

        if ((x % 2 != 0) && (y % 2 != 0)) {
            return y - x;
        }

        if ((x % 2 == 0) && (y % 2 == 0)) {
            return x - y;
        }

        return 0;
    }

    int main() {
        int N;

        while (1) {
            scanf("%d %d", &N, &M);

            if (N == 0 && M == 0) {
                printf("0 0\n");
                break;
            }

            int numeros[N];
            for (int i = 0; i < N; i++) {
                scanf("%d", &numeros[i]);
            }

            qsort(numeros, N, sizeof(int), comparar);

            printf("%d %d\n", N, M);

            for (int i = 0; i < N; i++) {
                printf("%d\n", numeros[i]);
            }
        }

        return 0;
    }
