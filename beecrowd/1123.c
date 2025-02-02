    #include <stdio.h>
    #include <stdlib.h>
    #include <limits.h>

    #define MAX_VERTICES 260
    #define INF INT_MAX

    // Estrutura do nó da lista de adjacência
    struct no {
        int v; // Vértice de destino
        int p; // Peso do arco
        struct no* prox;
    };
    typedef struct no* No;

    // Estrutura do grafo
    struct grafo {
        int n; // Número de vértices
        No adj[MAX_VERTICES]; // Lista de adjacência
    };
    typedef struct grafo* Grafo;

    // Função para inicializar o grafo
    Grafo init_grafo(int n) {
        Grafo G = malloc(sizeof(*G));
        G->n = n;
        for (int i = 0; i < n; i++) {
            G->adj[i] = NULL;
        }
        return G;
    }

    // Função para inserir um arco com peso
    void ins_arco(Grafo G, int orig, int dest, int p) {
        No novo = malloc(sizeof(*novo));
        novo->v = dest;
        novo->p = p;
        novo->prox = G->adj[orig];
        G->adj[orig] = novo;
    }

    // Implementação do Dijkstra com restrição da rota de serviço
    void dijkstra(Grafo G, int orig, int *dist, int *pred, int C) {
        int R[MAX_VERTICES] = {0}; // Conjunto de vértices já processados
        int u, v, custo;
        No p;

        // Inicializando distâncias e predecessores
        for (int i = 0; i < G->n; i++) {
            dist[i] = INF;
            pred[i] = -1;
        }
        dist[orig] = 0;

        // Laço principal
        for (int count = 0; count < G->n; count++) {
            // Busca o vértice em V - R que minimiza dist[u]
            int min_dist = INF;
            u = -1;
            for (int i = 0; i < G->n; i++) {
                if (!R[i] && dist[i] < min_dist) {
                    u = i;
                    min_dist = dist[i];
                }
            }

            if (u == -1) break; // Todos os vértices alcançáveis foram processados

            // Adiciona u ao conjunto R
            R[u] = 1;

            // Percorre os vizinhos de u
            for (p = G->adj[u]; p != NULL; p = p->prox) {
                v = p->v;
                custo = p->p;

                // Verifica se o vértice v está na rota de serviço
                if (v < C && v != u + 1) {
                    continue; // Ignora se não seguir a rota de serviço
                }

                // Atualiza a distância e o predecessor se necessário
                if (!R[v] && dist[v] > dist[u] + custo) {
                    dist[v] = dist[u] + custo;
                    pred[v] = u;
                }
            }
        }
    }

    int main() {
        int N, M, C, K;
        while (1) {
            scanf("%d %d %d %d", &N, &M, &C, &K);
            if (N == 0 && M == 0 && C == 0 && K == 0) {
                break;
            }

            Grafo G = init_grafo(N);

            for (int i = 0; i < M; i++) {
                int u, v, p;
                scanf("%d %d %d", &u, &v, &p);
                ins_arco(G, u, v, p);
                ins_arco(G, v, u, p); // Grafo não direcionado
            }

            int dist[MAX_VERTICES];
            int pred[MAX_VERTICES];

            dijkstra(G, K, dist, pred, C);

            printf("%d\n", dist[C - 1]);

            // Liberar memória alocada
            for (int i = 0; i < N; i++) {
                No p = G->adj[i];
                while (p != NULL) {
                    No temp = p;
                    p = p->prox;
                    free(temp);
                }
            }
            free(G);
        }

        return 0;
    }
