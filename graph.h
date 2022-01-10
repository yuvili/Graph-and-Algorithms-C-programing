#pragma once
#include <stdlib.h>
#include "vertex.h"

typedef struct _Graph {
    pvertex _head;
    int _size;
}Graph;

Graph* Graph_alloc();
void Graph_free(Graph* list);
void Graph_insertFirst(Graph* list, int data);
void insertLast(int data, Graph* list);