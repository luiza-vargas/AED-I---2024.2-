    #include <stdio.h>

    #define MAXN 100005

    int BIT1[MAXN], BIT2[MAXN], BIT3[MAXN];

    void update(int BIT[], int idx, int val, int n) {
        while (idx <= n) {
            BIT[idx] += val;
            idx += idx & -idx;
        }
    }

    int query(int BIT[], int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += BIT[idx];
            idx -= idx & -idx;
        }
        return sum;
    }

    int main() {
        int n;
        scanf("%d", &n);
        
        int arr[MAXN], inv1[MAXN] = {0}, inv2[MAXN] = {0};
        for (int i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);
        }

        // Contando inversões à esquerda
        for (int i = 1; i <= n; i++) {
            inv1[i] = query(BIT1, n) - query(BIT1, arr[i]);
            update(BIT1, arr[i], 1, n);
        }

        // Contando inversões à direita
        for (int i = n; i >= 1; i--) {
            inv2[i] = query(BIT2, arr[i] - 1);
            update(BIT2, arr[i], 1, n);
        }

        // Contando triplas invertidas
        long long triplas = 0;
        for (int i = 1; i <= n; i++) {
            triplas += (long long)inv1[i] * inv2[i];
        }

        printf("%lld\n", triplas);

        return 0;
    }

