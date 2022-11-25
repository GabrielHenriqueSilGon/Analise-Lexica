#ifndef BFS_HPP
#define BFS_HPP

#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;

typedef struct graph *Graph;
typedef struct TipoVertex *Vertex;

typedef struct TipoItem Item;
typedef struct TipoFila Fila;

struct TipoVertex{
  int dist;
  int id;
  Vertex prox;
};

struct graph{
  int V;
  int E;
  Vertex *adj;
};


//fila
struct TipoItem{
    int data;
  Item *prox;
};

struct TipoFila{
  Item *head;
  Item *tail;
  int size;
};



Vertex VertexInitialize(int value, int id);
Graph GraphInitialize(int V, Vertex *adj);
void GraphInsertEdge(Graph G, Vertex v1, Vertex v2, int dist);
void ImprimeGraph(Graph G);

Fila* FFVazia();
void Queue(Fila *f, int vertex);
Item* Dequeue(Fila *f);

void BFS(Graph G, Vertex s);

void Dijsktra (Graph G, Vertex *adj, Vertex s);

#endif