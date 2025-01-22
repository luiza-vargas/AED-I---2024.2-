void GRAPHcptD2(Graph G, vertex s, vertex *pa, int *dist)
{
   bool mature[1000];  // Vetor para marcar se o vértice foi processado (matured)
   
   // Inicializa os vetores pa, mature e dist
   for (vertex v = 0; v < G->V; ++v)
      pa[v] = -1;
      mature[v] = false;
      dist[v] = INT_MAX;  // Inicializa pa com -1, mature com false e dist com infinito
      pa[s] = s, dist[s] = 0;  // A partir do vértice de origem, o pai de s é s e a distância de s é 0
   
   PQinit(G->V);  // Inicializa a fila de prioridade com capacidade para V vértices
   
   // Insere todos os vértices na fila de prioridade com suas distâncias
   for (vertex v = 0; v < G->V; ++v)
      PQinsert(v, dist);  // Insere o vértice v na fila de prioridade, com a distância atual (dist[v])
   
   // Executa o algoritmo de Dijkstra
   while (!PQempty()) {  // Enquanto houver elementos na fila de prioridade
      vertex y = PQdelmin(dist);  // Remove o vértice com a menor distância (minimiza dist[y])
      if (dist[y] == INT_MAX) break;  // Se a distância for infinita, significa que todos os vértices acessíveis foram processados, então termina
      
      // Para cada vértice adjacente a y (verifique na matriz de adjacência)
      for (vertex w = 0; w < G->V; ++w) {
         if (G->adj[y][w] == 0 || mature[w]) continue;  // Se não houver aresta (peso 0) ou o vértice já foi processado, pula a iteração
         
         // Se encontrar um caminho mais curto para w
         if (dist[y] + G->adj[y][w] < dist[w]) {  // Verifica se a distância passando por y é menor que a distância conhecida para w
            dist[w] = dist[y] + G->adj[y][w];  // Atualiza a distância para w
            PQdec(w, dist);  // Atualiza a posição de w na fila de prioridade (porque a distância de w foi alterada)
            pa[w] = y;  // Atualiza o pai de w para y
         }
      }
      
      mature[y] = true;  // Marca o vértice y como processado
   }
   
   PQfree();  // Libera os recursos alocados pela fila de prioridade
}

