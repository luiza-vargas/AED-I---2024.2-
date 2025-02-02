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
    No* adj; // Lista de adjacência
};
typedef struct grafo* Grafo;

// Função para inicializar o grafo
Grafo init_grafo(int n) {
    Grafo G = malloc(sizeof(*G));
    G->n = n;
    G->adj = malloc(n * sizeof(No));
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

// Implementação básica do Dijkstra
void dijkstra(Grafo G, int orig, int *dist, int *pred) {
    int i, *R;
    int u, v, custo, tam_R, min_dist;
    No p;

    // Inicializando distâncias e predecessores
    for (i = 0; i < G->n; i++) {
        dist[i] = INT_MAX;
        pred[i] = -1;
    }
    dist[orig] = 0;

    // Inicializando conjunto R (vértices já processados)
    R = malloc(G->n * sizeof(int));
    for (i = 0; i < G->n; i++) {
        R[i] = 0; // 0 indica que o vértice não está em R
    }
    tam_R = 0;

    // Laço principal
    while (tam_R < G->n) {
        // Busca o vértice em V - R que minimiza dist[u]
        min_dist = INT_MAX;
        u = -1;
        for (i = 0; i < G->n; i++) {
            if (R[i] == 0 && dist[i] < min_dist) {
                u = i;
                min_dist = dist[i];
            }
        }

        // Adiciona u ao conjunto R
        R[u] = 1;
        tam_R++;

        // Percorre os vizinhos de u
        for (p = G->adj[u]; p != NULL; p = p->prox) {
            v = p->v;
            custo = p->p;

            // Atualiza a distância e o predecessor se necessário
            if (R[v] == 0 && dist[v] > dist[u] + custo) {
                dist[v] = dist[u] + custo;
                pred[v] = u;
            }
        }
    }

    // Libera a memória alocada para o conjunto R
    free(R);
}
