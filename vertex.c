#include <stdlib.h>
#include "vertex.h"

pedge edge_alloc(int src,int dest,int w, pedge next) {
    pedge edge1= (pedge)malloc(sizeof(edge));
    edge1->src= src;
    edge1->dest = dest;
    edge1->weight = w;
    edge1->next= next;
    return edge1;
}

void free_edge(pedge e){
    free(e);
}

void Node_free(pvertex node) {
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

pvertex  add_node(int data, pvertex next) {
    pvertex p = (pvertex) malloc(sizeof(vertex));
    p->id = data;
    p->tag = 0;
    p->edges = NULL;
    p->next = next;
    return p;
}

void first_edge(pvertex v, int src, int dest, int w) {
    v->edges = edge_alloc(src,dest,w,NULL);
}

void add_edge(int src, int dest, int w, pvertex v) {
    struct _edge **p = &v->edges;
    while(*p){
        p = &((*p)->next);
    }
    *p = edge_alloc(src, dest, w,NULL);
}

pvertex get_node(int id, pvertex head, int number_of_nodes){
    vertex **p = &head;
    while(((*p)->id) != id){
        p = &((*p)->next);
    }
    if(((*p)->id) == number_of_nodes-1){
        return NULL;
    }
    return *p;
}
