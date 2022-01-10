#pragma once
#include <stdlib.h>

typedef struct _edge
{
    int src;
    int dest;
    int weight;
    struct _edge *next;
}edge, *pedge;

typedef struct _vertex{
    int id;
    int tag;
    pedge edges;
    struct _vertex *next;
}vertex, *pvertex;

void Node_free(pvertex node);
pvertex add_node(int data, pvertex next);
void first_edge(pvertex v, int src, int dest, int w);
void add_edge(int src, int dest, int w, pvertex v);
pvertex get_node(int id,pvertex head);
void del_in_edges(pvertex head, int id);