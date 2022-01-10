#include "graph.h"
#include "vertex.h"

Graph* Graph_alloc() {
    Graph* p= (Graph*)malloc(sizeof(Graph));
    p->_head= NULL;
    p->_size= 0;
    return p;
}

void Graph_free(Graph* list) {
    if (list==NULL) return;
    vertex * p1= list->_head;
    vertex * p2;
    while(p1) {
        p2= p1;
        p1= p1->next;
        Node_free(p2);
    }
    free(list);
    list = NULL;
}

void Graph_insertFirst(Graph* list, int data) {
    list->_head= add_node(data, list->_head);
    ++(list->_size);
}

void insertLast(int data, Graph* list) {
    vertex **p= &list->_head;
    while(*p){
        p = &((*p)->next);
    }
    *p = add_node(data,NULL);
    ++(list->_size);
}
