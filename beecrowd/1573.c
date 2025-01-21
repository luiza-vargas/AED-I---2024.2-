#include <stdio.h>
#include <math.h>

int main() {
    int A, B, C;

    while (1) {
        scanf("%d %d %d", &A, &B, &C);

        if (A == 0 && B == 0 && C == 0) {
            break;
        }

        int volume = A * B * C;

        int aresta_cubo = (int)cbrt(volume);

        printf("%d\n", aresta_cubo);
    }

    return 0;
}
