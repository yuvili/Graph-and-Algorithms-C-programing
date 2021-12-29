#pragma once
#include <stdlib.h>

typedef struct _edge
{
    int src;
    int dest;
    float weight;
    struct _edge *next;
}edge;

typedef struct _vertex{
    int id;
    int tag;
    edge * edges;
    struct _vertex *next;
}vertex;

void Node_free(vertex* node);

vertex * add_node(int data, vertex *next);

void first_edge(vertex * v, int src, int dest, float w);

void add_edge(int src, int dest, float w, vertex * v);