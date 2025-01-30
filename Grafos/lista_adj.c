#include <stdio.h>
#include <stdlib.h>

// Estrutura que representa um nó na lista de adjacências
struct node {
  int vertex;           // Armazena o número do vértice
  struct node* next;    // Ponteiro para o próximo nó da lista
};

// Função para criar um novo nó
struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node)); // Aloca memória para o nó
  newNode->vertex = v; // Atribui o número do vértice
  newNode->next = NULL; // Inicializa o ponteiro próximo como NULL
  return newNode; // Retorna o novo nó
}

// Estrutura que representa o grafo
struct Graph {
  int numVertices;       // Número total de vértices no grafo
  struct node** adjLists; // Ponteiro para um vetor de listas de adjacência
};

// Função para criar um grafo com um número específico de vértices
struct Graph* createAGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph)); // Aloca memória para o grafo
  graph->numVertices = vertices; // Define o número de vértices

  // Aloca memória para o vetor de listas de adjacência
  graph->adjLists = malloc(vertices * sizeof(struct node*));

  // Inicializa todas as listas como NULL
  for (int i = 0; i < vertices; i++)
    graph->adjLists[i] = NULL;

  return graph; // Retorna o grafo
}

// Função para adicionar uma aresta ao grafo
void addEdge(struct Graph* graph, int s, int d) {
  // Adiciona uma aresta de s para d
  struct node* newNode = createNode(d); // Cria um novo nó para o destino
  newNode->next = graph->adjLists[s]; // Insere o nó no início da lista de adjacência de s
  graph->adjLists[s] = newNode;

  // Adiciona uma aresta de d para s (pois o grafo é não direcionado)
  newNode = createNode(s); // Cria um novo nó para a origem
  newNode->next = graph->adjLists[d]; // Insere o nó no início da lista de adjacência de d
  graph->adjLists[d] = newNode;
}

// Função para imprimir o grafo
void printGraph(struct Graph* graph) {
  for (int v = 0; v < graph->numVertices; v++) { // Itera sobre cada vértice
    struct node* temp = graph->adjLists[v]; // Ponteiro para a lista de adjacência do vértice
    printf("\n Vertex %d\n: ", v); // Imprime o número do vértice
    while (temp) { // Itera pela lista de adjacência
      printf("%d -> ", temp->vertex); // Imprime os vértices adjacentes
      temp = temp->next; // Avança para o próximo nó
    }
    printf("\n"); // Nova linha após imprimir todos os vértices adjacentes
  }
}

// Função principal
int main() {
  struct Graph* graph = createAGraph(4); // Cria um grafo com 4 vértices
  addEdge(graph, 0, 1); // Adiciona aresta entre 0 e 1
  addEdge(graph, 0, 2); // Adiciona aresta entre 0 e 2
  addEdge(graph, 0, 3); // Adiciona aresta entre 0 e 3
  addEdge(graph, 1, 2); // Adiciona aresta entre 1 e 2

  printGraph(graph); // Imprime a representação do grafo

  return 0; // Encerra o programa
}
