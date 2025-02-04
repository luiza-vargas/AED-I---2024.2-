
// Variáveis globais para a fila de prioridade
HeapNo heap[MAX_VERTICES];
int pos[MAX_VERTICES]; // Armazena a posição de cada vértice no heap
int tamanho_heap;


// Funções para manipular a fila de prioridade (min-heap)

// Inicializa a fila de prioridade
void PQinit(int capacidade) {
    tamanho_heap = 0;
}

// Verifica se a fila de prioridade está vazia
bool PQempty() {
    return tamanho_heap == 0;
}

// Insere um vértice na fila de prioridade
void PQinsert(int vertice, int chave) {
    heap[tamanho_heap].vertice = vertice;
    heap[tamanho_heap].chave = chave;
    pos[vertice] = tamanho_heap;
    tamanho_heap++;
}

// Extrai o vértice com a menor chave (custo mínimo)
int PQdelmin(int* preco) {
    int min_vertice = heap[0].vertice;
    heap[0] = heap[tamanho_heap - 1];
    pos[heap[0].vertice] = 0;
    tamanho_heap--;
    return min_vertice;
}

// Reorganiza o heap após a diminuição da chave de um vértice
void PQdec(int vertice, int* preco) {
    int i = pos[vertice];
    while (i > 0 && heap[(i - 1) / 2].chave > heap[i].chave) {
        // Troca com o pai
        HeapNo temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;

        // Atualiza as posições
        pos[heap[i].vertice] = i;
        pos[heap[(i - 1) / 2].vertice] = (i - 1) / 2;

        i = (i - 1) / 2;
    }
}

// Libera a memória da fila de prioridade
void PQfree() {
    // Nada a liberar, pois usamos arrays estáticos
}

// Função principal do algoritmo de Prim com fila de prioridade
void UGRAPHmstP2(Grafo G, int* pa) {
    bool tree[MAX_VERTICES]; // Indica se um vértice está na MST
    int preco[MAX_VERTICES]; // Armazena o custo mínimo para conectar à MST

    // Inicialização
    for (int v = 1; v < G->numv; ++v) {
        pa[v] = -1;
        tree[v] = false;
        preco[v] = INFINITY;
    }
    pa[0] = 0;
    tree[0] = true;

    // Atualiza os custos dos vértices adjacentes ao vértice 0
    for (No a = G->adj[0]; a != NULL; a = a->prox) {
        pa[a->vertice] = 0;
        preco[a->vertice] = a->peso;
    }

    // Inicializa a fila de prioridade
    PQinit(G->numv);
    for (int v = 1; v < G->numv; ++v) {
        PQinsert(v, preco[v]);
    }

    // Loop principal do algoritmo de Prim
    while (!PQempty()) {
        int y = PQdelmin(preco);
        if (preco[y] == INFINITY) break; // Grafo desconexo
        tree[y] = true;

        // Atualiza os custos dos vértices adjacentes a y
        for (No a = G->adj[y]; a != NULL; a = a->prox) {
            int w = a->vertice;
            if (!tree[w] && a->peso < preco[w]) {
                preco[w] = a->peso;
                PQdec(w, preco);
                pa[w] = y;
            }
        }
    }

    // Libera a fila de prioridade
    PQfree();
}
