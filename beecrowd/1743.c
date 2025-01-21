#include <stdio.h>

int main() {
    int X[5], Y[5];
    int compativel = 1; 

    for (int i = 0; i < 5; i++) {
        scanf("%d", &X[i]);
    }

    for (int i = 0; i < 5; i++) {
        scanf("%d", &Y[i]);
    }

    for (int i = 0; i < 5; i++) {
        if (X[i] == Y[i]) {
            compativel = 0; 
            break;
        }
    }

    if (compativel) {
        printf("Y\n");
    } else {
        printf("N\n");
    }

    return 0;
}
