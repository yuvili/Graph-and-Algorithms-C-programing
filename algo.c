#include <stdio.h>
#include "vertex.h"
#include <limits.h>
#include "graph.h"

Graph *graph;
int number_of_nodes;
int bool = 0;
int distances[50][50];

void insert_node_cmd() {
    int node_id;
    scanf("%d", &node_id);
    pvertex temp = get_node(node_id, graph->_head);
    if (temp == NULL) {
        graph->_size++;
        number_of_nodes++;

        insertLast(node_id, graph);
        pvertex curr = get_node(node_id, graph->_head);
        int dest;
        int weight;
        int first = -1;

        while (scanf("%d", &dest)) {
            scanf("%d", &weight);
            if (first == -1) {
                first_edge(curr, node_id, dest, weight);
                distances[node_id][dest] = weight;
                first = 0;
            } else {
                add_edge(node_id, dest, weight, curr);
                distances[node_id][dest] = weight;
            }
        }
    } else {
        free(temp->edges);
        temp->edges = NULL;
        int dest;
        int weight;
        int first = -1;

        while (scanf("%d", &dest)) {
            scanf("%d", &weight);
            if (first == -1) {
                first_edge(temp, node_id, dest, weight);
                first = 0;
                distances[node_id][dest] = weight;
            } else {
                add_edge(node_id, dest, weight, temp);
                distances[node_id][dest] = weight;
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
        pvertex *p = &graph->_head;
        while((*p)->next->id != id) {
            p = &(*p)->next;
        }
        pvertex node_to_del = get_node(id, graph->_head);
        (*p)->next = node_to_del->next;
        Node_free(node_to_del);
        del_in_edges(graph->_head, id);
        node_to_del = NULL;
    }
}

int lowest_dist(int src){
    int temp_dist = INT_MAX;
    int ans = -1;
    int i;
    pvertex current_node =  graph->_head;
    while(current_node != NULL){
        i = current_node->id;
        if(current_node->tag == 0){
            if(distances[src][i] != -1 && distances[src][i] < temp_dist){
                temp_dist = distances[src][i];
                ans = i;
            }
        }
        current_node = current_node->next;
    }
    return ans;
}

void Dijkstra_algorithm(int index, int src, pvertex node) {
    int distance = distances[src][index];
    pedge head = node->edges;

    while(head != NULL) {
        pvertex dest_node = get_node(head->dest, graph->_head);
        int new_dist = distance + head->weight;

        if (new_dist < distances[src][dest_node->id]) {
            distances[src][dest_node->id] = new_dist;
        }
        head= head->next;
    }
}

int shortsPath(int src, int dest){
    if(src == dest){
        return -1;
    }

    pvertex tag_change = graph->_head;
    while (tag_change != NULL){
        tag_change->tag = 0;
        tag_change = tag_change->next;
    }

    pvertex *temp_dest = &graph->_head;
    while((*temp_dest)->id != dest){
        temp_dest = &(*temp_dest)->next;
    }

    while((*temp_dest)->tag != 1){
        int index = lowest_dist(src);

        if(index == -1){
            return -1;
        }
        else if(index != src){
            pvertex curr = get_node(index, graph->_head);
            Dijkstra_algorithm(index, src, curr);
            curr->tag = 1;
        } else{
            pvertex curr = get_node(index, graph->_head);
            curr->tag = 1;
        }
    }
    return distances[src][dest];
}

void shortsPath_cmd(){
    int src;
    int dest;

    scanf("%d", &src);
    scanf("%d", &dest);

    if(src == dest){
        printf("Dijsktra shortest path: -1 \n");
    }

    int ans = shortsPath(src,dest);
    printf("Dijsktra shortest path: %d \n", ans);
}

int weight = INT_MAX;
int size = -1;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void calculateWeight(int *arr){
    int tempWeight = 0;
    for (int i = 0; i < size - 1; i++){
        int dis = shortsPath( arr[i], arr[i + 1]);
        if (dis == -1){
            tempWeight = INT_MAX;
            return;
        }
        tempWeight += dis;
    }
    if (tempWeight < weight)
    {
        weight = tempWeight;
    }
}

int *copyList(int *list){
    int *copy = (int *)malloc(sizeof(int) * size);
    if(copy == NULL){
        return NULL;
    }
    int i = 0;
    while (i<size){
        copy[i] = list[i];
        i++;
    }
    return copy;
}

void allPaths(int first, int *arr){
    if (first == size - 1)
    {
        calculateWeight(arr);
        return;
    }
    for (int i = first; i < size; ++i)
    {
        int *copy = copyList(arr);
        swap(&copy[first], &copy[i]);
        allPaths(first + 1, copy);
        free(copy);
        copy = NULL;
    }
}

void TSP_cmd(){
    scanf("%d", &size);
    int list[size];
    for (int i = 0; i < size; ++i) {
        int temp;
        scanf("%d", &temp);
        list[i] = temp;
    }

    allPaths(0, list);
    if(weight == INT_MAX){
        weight = -1;
    }
    printf("TSP shortest path: %d \n", weight);
    weight = INT_MAX;
    size = -1;
}

void build_graph_cmd(){
    if(bool == 1){
        Graph_free(graph);
    }
    for (int i = 0; i < 50; i++){
        for (int j = 0; j < 50; ++j) {
            if (i==j){
                distances[i][j] = -1;
            } else{
                distances[i][j] = INT_MAX;
            }
        }
    }

    scanf("%d", &number_of_nodes);
    graph = Graph_alloc();
    int src;
    pvertex prev = NULL;

    char n;
    while (scanf(" %c", &n) && n == 110) {
        scanf(" %d", &src);

        if (src == 0) {
            Graph_insertFirst(graph, src);
            prev = graph->_head;
        } else {
            insertLast(src, graph);
            prev = prev->next;
        }

        int dest;
        int weight;
        int first = -1;

        while (scanf("%d", &dest)) {
            scanf("%d", &weight);
            if (first == -1) {
                first_edge(prev, src, dest, weight);
                first = 0;
                distances[src][dest] = weight;
            } else {
                add_edge(src, dest, weight, prev);
                distances[src][dest] = weight;
            }
        }
    }

    if (n == 'B') {
        insert_node_cmd();
    } else if (n == 'D') {
        delete_node_cmd();
    } else if (n == 'S') {
        shortsPath_cmd();
    } else if(n == 'T'){
        TSP_cmd();
    }

    bool = 1;
}

