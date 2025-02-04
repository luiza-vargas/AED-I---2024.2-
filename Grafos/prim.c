    #include <stdio.h>
    #include <stdlib.h>

    struct no{
        int vertice;
        int peso;
        int no*prox;
    };
    typedef struct no*No;

    struct grafo{
        int numv;
        No**adj;
    };

    void UGRAPHmstP1(Grafo G, int *pa) {
        int mst[1000]; // Usaremos 0 para "não na MST" e 1 para "na MST"
        int preco[1000];
        int v, w;
        No a;

        // Inicialização
        for (v = 0; v < G->numv; ++v) {
            pa[v] = -1; // Nenhum vértice tem pai inicialmente
            mst[v] = 0; // Nenhum vértice está na MST inicialmente
            preco[v] = INFINITY;
        }
        pa[0] = 0; // O vértice 0 é a raiz da MST
        mst[0] = 1; // Adiciona o vértice 0 à MST

        // pega os vertices adjacentes a 0
        for (a = G->adj[0]; a != NULL; a = a->prox) {
            pa[a->vertice] = 0; // O pai dos vértices adjacentes é 0
            preco[a->vertice] = a->peso;    // Atualiza o custo para conectar à MSt
        }

        while (true) {
            int min = INFINITY;
            int y = -1;

            // Encontra o vértice mais próximo que ainda não está na MST
            for (w = 0; w < G->numv; ++w) {
                if (mst[w] == 0 && preco[w] < min) {
                    min = preco[w];
                    y = w;
                }
            }

            // Se não há mais vértices para adicionar, termina
            if (min == INFINITY) break;

            // Adiciona o vértice y à MST
            mst[y] = 1;

            // Atualiza os preços e os pais dos vértices adjacentes a y
            for (a = G->adj[y]; a != NULL; a = a->prox) {
                if (mst[a->vertice] == 0 && a->peso < preco[a->vertice]) {
                    preco[a->vertice] = a->peso;
                    pa[a->vertice] = y;
                }
            }
        }
    }
