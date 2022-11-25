#include "bfs.hpp"


//// procs FILA

Fila* FFVazia(){
  Fila *f = (Fila*) malloc(sizeof(Fila));
  f->head = NULL;
  f->tail = NULL;
  return f;
}

void Queue(Fila *f, int vertex){
  Item *d = (Item *) malloc (sizeof(Item));
  d->data = vertex;
  d->prox = NULL;

  if(f->head == NULL){
    f->head = d;
    f->tail = d;
  }else{
    f->tail->prox = d;
    f->tail = d;
  }

  f->size ++;
}

Item* Dequeue(Fila *f){
  Item *aux;

  if(f->head == NULL)
    return NULL;

  aux = f->head;
  f->head = f->head->prox;
  f->size --;

  return aux;
}

//// fim procs FILA

// procs para tratar com grafos 

Vertex VertexInitialize(int value, int id){
    
  Vertex v = (Vertex)malloc (sizeof(Vertex));
  v->dist = value;
  v->id = id;
  v->prox  = NULL;
  
  return v;
}

Graph GraphInitialize(int V, Vertex * adj){
  Graph G = (Graph)malloc (sizeof(Graph));
  G->V = V;
  G->E = 0;
  G->adj = adj;

  //for(int v=0; v<V; v++)
    //G->adj[v] = VertexInitialize(v);

  return G;
}

void GraphInsertEdge(Graph G, Vertex v1, Vertex v2, int dist){
    
  Vertex v = G->adj[v1->id];
  
  while(v->prox != NULL){
    if (v->id == v2->id)
      return;
    v = v->prox;
  }

  v->prox = VertexInitialize(dist, v2->id);
  G->E ++;
}

void ImprimeGraph(Graph G){
  Vertex aux;

  for(int v=0; v < (G->V) ; v++){
    aux = G->adj[v];

    while(aux != NULL){
      
      if(aux->dist != 0) cout << " " << aux->dist << " km -> "; 
      
      cout << "Cidade " << aux->id << " ->";
      aux = aux->prox;
    }

    cout << "[]";
    printf("\n");
  }
  
}

// fim procs para tratar com grafos
void BFS(Graph G, Vertex s){
  Fila *f = FFVazia();
  int cor[G->V]; //0 Branco, 1 Cinza, 2 Preto
  int d[G->V];
  int pi[G->V]; // -1 == NULL
  
  for(int i=0; i<G->V; i++)
    if(i != s->id){
      cor[i] = 0;
      d[i]   = -1; //infinito
      pi[i]  = -1; // ? não tem pai ainda
    }

  cor[s->id] = 1;
  d[s->id]   = 0;
  pi[s->id]  = -1;

  Queue(f, s->id);

  while (f->size > 0){
    Item *u = Dequeue(f);
    for(Vertex v = G->adj[u->data]; v != NULL; v=v->prox){
      if(cor[v->id] == 0){
        cor[v->id] = 1;
        d[v->id]   = d[u->data] + 1;
        pi[v->id]  = u->data;
        Queue(f, v->id);
      }
    }

    cor[u->data] = 2;
    printf("Vertex:%d Antecessor:%d\n", u->data, pi[u->data]);
  }
}

void Dijsktra (Graph G, Vertex *adj, Vertex s){
    int d[G->V];
    int pi[G->V];
    
    d[0] = 0;
    pi[0] = 0;
    
    
    for(int i=1; i<G->V; i++)
    {
        d[i] = 1000;
        pi[i] = -1;
    }
    
    Graph Q = GraphInitialize(G->V, G->adj);
    Graph S = GraphInitialize(G->V, G->adj);
    Q = G;
    
    for(int v=0; v < (Q->V) ; v++){
        Vertex u = Q->adj[v];
        S->adj[u->id] = u;
     
        while (u != NULL){
            if (d[v] > u->dist + d[u->id]){
                d[v] = u->dist + d[u->id];
                pi[v] = u->id;
                
            }
            
            u = u->prox;
        }
      }
      
    
    for(int i=0; i<G->V; i++)
    {
        cout << "Dist da cidade " << i << ": " << d[i] << " Pai: " << pi[i];
        cout << endl;
    }
    
}