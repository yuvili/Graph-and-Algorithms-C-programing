#pragma once
#include <stdlib.h>
#include "vertex.h"

typedef struct _Graph {
    vertex * _head;
    size_t _size;
}Graph;

/*
 * Allocates a new empty List.
 * It's the user responsibility to free it with List_free.
 */
Graph* Graph_alloc();

/*
 * Frees the memory and resources allocated to list.
 * If list==NULL does nothing (same as free).
 */
void Graph_free(Graph* list);

/*
 * Returns the number of elements in the list.
 */
size_t Graph_size(const Graph* list);

/*
 * Inserts an element in the begining of the list.
 */
void Graph_insertFirst(Graph* list, int data,int tag);

/*
 * Returns the list first data.
 */

double Graph_firstData(const Graph* list);
void Graph_insertFirst(Graph* list, int data,int tag);
void insertLast(int data, Graph* list);