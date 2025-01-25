    #include <stdio.h>
    #include <string.h>

    #define MAX 101

    int grafo[MAX][MAX];  
    int visitado[MAX];    
    int N;

    void dfs(int no) {
        visitado[no] = 1;
        for (int i = 1; i <= N; i++) {
            if (grafo[no][i] && !visitado[i]) {
                dfs(i);
            }
        }
    }

    int main() {
        int L;
        scanf("%d %d", &N, &L);
        memset(grafo, 0, sizeof(grafo));
        memset(visitado, 0, sizeof(visitado));

        for (int i = 0; i < L; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            grafo[x][y] = 1;
            grafo[y][x] = 1;  
        }

        dfs(1);

        int completo = 1;  
        for (int i = 1; i <= N; i++) {
            if (!visitado[i]) {
                completo = 0;  
                break;
            }
        }

        if (completo) {
            printf("COMPLETO\n");
        } else {
            printf("INCOMPLETO\n");
        }

        return 0;
    }
