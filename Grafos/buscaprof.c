// Variáveis globais para a busca em profundidade
static int cnt;        // Contador global para a ordem de descoberta
int pre[1000];         // Vetor que armazena a ordem de descoberta dos vértices

// Função auxiliar recursiva para a busca em profundidade (DFS)
static void dfsR(struct Graph* G, int v) {
  pre[v] = cnt++; // Marca o vértice `v` como visitado, atribuindo o contador global
  struct node* temp = G->adjLists[v]; // Obtém a lista de adjacências do vértice `v`

  // Itera pelos vértices adjacentes
  while (temp) {
    int w = temp->vertex; // Vértice adjacente
    if (pre[w] == -1) {   // Se o vértice ainda não foi descoberto
      dfsR(G, w);         // Chama recursivamente a DFS para o vértice adjacente
    }
    temp = temp->next;    // Avança para o próximo vértice na lista
  }
}

// Função principal para realizar a busca em profundidade no grafo
void graphDFS(struct Graph* G) {
  cnt = 0; // Inicializa o contador global para a ordem de descoberta
  for (int v = 0; v < G->numVertices; v++) {
    pre[v] = -1; // Marca todos os vértices como não descobertos inicialmente
  }

  // Inicia a busca em profundidade para cada componente desconexa
  for (int v = 0; v < G->numVertices; v++) {
    if (pre[v] == -1) { // Se o vértice ainda não foi visitado
      dfsR(G, v);       // Inicia a DFS a partir deste vértice
    }
  }
}
