#include <stdio.h>
#include <stdlib.h>
#include "vertex.h"
#include "graph.h"

Graph *graph;

void A(){
    int number_of_nodes;
    scanf("%d", &number_of_nodes);
    graph = Graph_alloc();
    int src;
    vertex *prev = NULL;

    for(int i = 0; i<=number_of_nodes; i++){
        scanf("%d",&src);

        if(src == 0){
            Graph_insertFirst(graph,src,0);
            prev = graph->_head;
        } else{
            insertLast(src,graph);
            prev = prev->next;
        }

        int dest;
        float weight;
        int first = -1;

        while(scanf("%d",&dest)){
            scanf("%f",&weight);
            if(first == -1){
                first_edge(prev,src,dest,weight);
                first = 0;
            } else{
                add_edge(src,dest,weight,prev);
            }
        }
    }
}