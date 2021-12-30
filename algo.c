#include <stdio.h>
#include "vertex.h"
#include "graph.h"

Graph *graph;
int bool = 0;

void A(){
    if(bool == 1){
        Graph_free(graph);
    }
    int number_of_nodes;
    scanf("%d", &number_of_nodes);
    graph = Graph_alloc();
    int src;
    vertex *prev = NULL;

    for(int i = 0; i<=number_of_nodes; i++){
        char n;
        if(scanf("%c",&n) == 'n'){
            scanf("%d",&src);
        }

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
    bool = 1;
}