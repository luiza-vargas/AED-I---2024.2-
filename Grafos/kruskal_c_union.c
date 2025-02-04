void UGRAPHmstK1(UGraph G, edge mst[]) {
    edge e[500000]; // Array para armazenar todas as arestas do grafo

    // Extrai todas as arestas do grafo G e armazena no array e
    UGRAPHedges(G, e);

    // Calcula o número de arestas (E = G->A / 2, pois o grafo é não direcionado)
    int E = G->A / 2;

    // Ordena as arestas em ordem crescente de peso
    sort(e, 0, E - 1);

    // Inicializa a estrutura Union-Find com G->V conjuntos disjuntos
    UFinit(G->V);

    int k = 0; // Contador de arestas adicionadas à MST
    for (int i = 0; k < G->V - 1; ++i) {
        // Encontra os conjuntos (componentes conectados) dos vértices da aresta atual
        vertex v0 = UFfind(e[i].v);
        vertex w0 = UFfind(e[i].w);

        // Se os vértices estão em conjuntos diferentes, a aresta não forma ciclo
        if (v0 != w0) {
            // Une os conjuntos de v0 e w0
            UFunion(v0, w0);

            // Adiciona a aresta à MST
            mst[k++] = e[i];
        }
    }
}

/* Esta função armazena as arestas do grafo não-dirigido G no vetor e[0..E-1]. */
static void UGRAPHedges(UGraph G, edge e[]) {
    int i = 0; // Contador para o índice do array e

    // Percorre todos os vértices do grafo
    for (vertex v = 0; v < G->V; ++v) {
        // Percorre todas as arestas adjacentes ao vértice v
        for (link a = G->adj[v]; a != NULL; a = a->next) {
            // Para evitar duplicação (grafo não direcionado), armazena apenas se v < a->w
            if (v < a->w) {
                // Armazena a aresta no array e
                e[i++] = EDGE(v, a->w, a->c);
            }
        }
    }
}
