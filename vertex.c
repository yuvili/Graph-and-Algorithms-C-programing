#include <stdlib.h>
#include "vertex.h"

edge * edge_alloc(int src,int dest,float w, edge* next) {
    edge* edge1= (edge *)malloc(sizeof(edge));
    edge1->src= src;
    edge1->dest = dest;
    edge1->weight = w;
    edge1->next= next;
    return edge1;
}

void free_edge(edge * e){
    free(e);
}

void Node_free(vertex* node) {
    if (node==NULL) return;
    edge * p1= node->edges;
    edge * p2;
    while(p1) {
        p2= p1;
        p1= p1->next;
        free_edge(p2);
    }
    free(p1);
    free(p2);
    free(node);
    p1 = NULL;
    p2 = NULL;
}

vertex * add_node(int data, vertex *next) {
    vertex *p = (vertex *) malloc(sizeof(vertex));
    p->id = data;
    p->tag = 0;
    p->edges = NULL;
    p->next = next;
    return p;
}

void first_edge(vertex * v, int src, int dest, float w) {
    v->edges = edge_alloc(src,dest,w,NULL);
}

void add_edge(int src, int dest, float w, vertex * v) {
    struct _edge **p = &v->edges;
    while(*p){
        p = &((*p)->next);
    }
    *p = edge_alloc(src, dest, w,NULL);
}

vertex * get_node(int id, vertex * head){
    vertex **p = &head;
    while(((*p)->id) != id){
        p = &((*p)->next);
    }
    return *p;
}
