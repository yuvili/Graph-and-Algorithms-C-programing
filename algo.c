#include <stdio.h>
#include "vertex.h"
#include "graph.h"

Graph *graph;
int bool = 0;

void build_graph_cmd(){
    if(bool == 1){
        Graph_free(graph);
    }
    int number_of_nodes;
    scanf("%d", &number_of_nodes);
    graph = Graph_alloc();
    int src;
    pvertex prev = NULL;

    for(int i = 0; i<=number_of_nodes; i++){
        char n;
        scanf(" %c",&n);
        if(n == 110){
            scanf(" %d",&src);
        }

        if(src == 0){
            Graph_insertFirst(graph,src);
            prev = graph->_head;
        } else{
            insertLast(src,graph);
            prev = prev->next;
        }

        int dest;
        int weight;
        int first = -1;

        while(scanf("%d",&dest)){
            scanf("%d",&weight);
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

void insert_node_cmd() {
    int node_id;
    scanf("%d", &node_id);
    pvertex temp = get_node(node_id, graph->_head, graph->_size);
    if (temp == NULL) {
        insertLast(node_id, graph);
    } else {
        Node_free(temp);
        insertLast(node_id, graph);
        pvertex curr = get_node(node_id, graph->_head, graph->_size);
        int dest;
        int weight;
        int first = -1;

        while (scanf("%d", &dest)) {
            scanf("%d", &weight);
            if (first == -1) {
                first_edge(curr, node_id, dest, weight);
                first = 0;
            } else {
                add_edge(node_id, dest, weight, curr);
            }
        }
    }
}

void delete_node_cmd(){
    int id;
    scanf("%d", &id);
    if(id == graph->_head->id){
        pvertex *temp = &graph->_head;
        graph->_head = graph->_head->next;
        Node_free((*temp));
        temp = NULL;
    }
    else{
        pvertex node_to_del = get_node(id, graph->_head, graph->_size);
        Node_free(node_to_del);
        del_in_edges(graph->_head, id);
        node_to_del = NULL;
    }
}
//
//int shortsPath_cmd(){
//    return 0;
//}