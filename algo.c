#include <stdio.h>
#include "vertex.h"
#include <limits.h>
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

int * lowest_dist(int *dist[]){
    int temp_dist = INT_MAX;
    int ans = -1;

    for(int i = 0; i< graph->_size; i++){
        pvertex current_node = get_node(i, graph->_head, graph->_size);
        if(current_node->tag == 0){
            if((*dist[i]) < temp_dist){
                temp_dist = (*dist[i]);
                ans = i;
            }
        }
    }
    return &ans;
}

void Dijkstra_algorithm(int index, int *dist[], pvertex node) {
    int distance = (*dist[index]);
    pedge head = node->edges;

    while(head != NULL) {
        pvertex dest_node = get_node(head->dest, graph->_head, graph->_size);
        int new_dist = distance + head->weight;

        if (new_dist < (*dist[dest_node->id])) {
            dist[dest_node->id] = &new_dist;
        }
        head= head->next;
    }
}

int shortsPath_cmd(){
    int src;
    int dest;

    scanf("%d", &src);
    scanf("%d", &dest);

    if(src == dest){
        return -1;
    }

    int number_of_nodes = graph->_size;
    pvertex src_node = get_node(src,graph->_head,number_of_nodes);
    pvertex dest_node = get_node(dest,graph->_head,number_of_nodes);
    int *arr[number_of_nodes];
    arr[src] = (int *) -1;

    pvertex head = graph->_head;

    while(head != NULL) {
        if (head->id != src) {
            pedge temp = get_edge(src_node, head->id);
            if(temp != NULL){
                arr[head->id] =  &temp->weight;
            }
            else{
                arr[head->id] = (int *) INT_MAX;
            }
        }
        head = head->next;
    }

    while(dest_node->tag != 1){
        int *index = lowest_dist(arr);

        if((*index) == -1){
            return -1;
        }
        else{
            pvertex curr = get_node((*index), graph->_head,number_of_nodes);
            Dijkstra_algorithm((*index), arr, curr);
            curr->tag = 1;
        }
    }
    printf("%d", (*arr[dest]));
    return (*arr[dest]);
}

//void TSP_cmd(){
//    int len;
//    scanf("%d", &len);
//    int list[len];
//    for (int i = 0; i < len; ++i) {
//        int temp;
//        scanf("%d", &temp);
//        list[i] = temp;
//    }
