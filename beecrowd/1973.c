    #include <stdio.h>

    int main() {
        int N;
        scanf("%d", &N);
        
        int estrela[N];
        int carneiro[N];
        long long totalEstrela = 0;
        long long totalCarneiro = 0;
        
        for (int i = 0; i < N; i++) {
            scanf("%d", &carneiro[i]);
            estrela[i] = 0;
        }
        
        int j = 0;
        while (1) {
            if (j == 0 && carneiro[j] % 2 == 0) {
                estrela[j] = 1;
                if (carneiro[j] > 0) carneiro[j]--;
                break;
            } else if (j == (N - 1) && carneiro[j] % 2 == 1) {
                estrela[j] = 1;
                if (carneiro[j] > 0) carneiro[j]--;
                break;
            } else if (carneiro[j] % 2 == 1) {
                if (carneiro[j] > 0) carneiro[j]--;
                estrela[j] = 1;
                j++;
            } else if (carneiro[j] % 2 == 0) {
                estrela[j] = 1;
                if (carneiro[j] > 0) carneiro[j]--;
                j--;
            }
        }
        
        for (int i = 0; i < N; i++) {
            totalCarneiro += carneiro[i];
            totalEstrela += estrela[i];
        }
        
        printf("%lld %lld\n", totalEstrela, totalCarneiro);
        
        return 0;
    }
