#include "Dijsktra.hpp"

int
main ()
{

  int V = 10;

  Vertex *adj = (Vertex *) malloc (V * sizeof (Vertex));

   adj[0] = VertexInitialize (0, 0);

   for(int v=1; v<V; v++)
    adj[v] = VertexInitialize(0, v);

  Graph G = GraphInitialize (V, adj);

  GraphInsertEdge (G, G->adj[8], G->adj[2], 7);
  GraphInsertEdge (G, G->adj[2], G->adj[8], 7);
  GraphInsertEdge (G, G->adj[0], G->adj[1], 4);
  GraphInsertEdge (G, G->adj[1], G->adj[0], 4);
  GraphInsertEdge (G, G->adj[1], G->adj[4], 5);
  GraphInsertEdge (G, G->adj[4], G->adj[1], 5);
  GraphInsertEdge (G, G->adj[1], G->adj[3], 15);
  GraphInsertEdge (G, G->adj[3], G->adj[1], 15);
  GraphInsertEdge (G, G->adj[2], G->adj[0], 7);
  GraphInsertEdge (G, G->adj[0], G->adj[2], 7);
  GraphInsertEdge (G, G->adj[9], G->adj[3], 9);
  GraphInsertEdge (G, G->adj[3], G->adj[9], 9);
  GraphInsertEdge (G, G->adj[4], G->adj[5], 13);
  GraphInsertEdge (G, G->adj[5], G->adj[4], 13);
  GraphInsertEdge (G, G->adj[4], G->adj[6], 3);
  GraphInsertEdge (G, G->adj[6], G->adj[4], 3);
  GraphInsertEdge (G, G->adj[5], G->adj[1], 8);
  GraphInsertEdge (G, G->adj[1], G->adj[5], 8);
  GraphInsertEdge (G, G->adj[5], G->adj[6], 2);
  GraphInsertEdge (G, G->adj[6], G->adj[5], 2);
  GraphInsertEdge (G, G->adj[5], G->adj[7], 8);
  GraphInsertEdge (G, G->adj[7], G->adj[5], 8);
  GraphInsertEdge (G, G->adj[6], G->adj[8], 3);
  GraphInsertEdge (G, G->adj[8], G->adj[6], 3);
  GraphInsertEdge (G, G->adj[6], G->adj[7], 9);
  GraphInsertEdge (G, G->adj[7], G->adj[6], 9);
  GraphInsertEdge (G, G->adj[9], G->adj[8], 10);
  GraphInsertEdge (G, G->adj[8], G->adj[9], 10);
  GraphInsertEdge (G, G->adj[0], G->adj[9], 5);
  GraphInsertEdge (G, G->adj[9], G->adj[0], 5);
  
  ImprimeGraph (G);
  
  cout << endl;

 // BFS (G, G->adj[0]);
  
  Dijsktra (G, G->adj, G->adj[0]);

  return 0;

}
