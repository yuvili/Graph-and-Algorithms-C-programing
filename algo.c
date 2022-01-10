#include <stdio.h>
#include "vertex.h"
#include <limits.h>
#include "graph.h"

Graph *graph;
int number_of_nodes;
int bool = 0;

void insert_node_cmd() {
    int node_id;
    scanf("%d", &node_id);
    pvertex temp = get_node(node_id, graph->_head);
    if (temp == NULL) {
        insertLast(node_id, graph);
    } else {
        Node_free(temp);
        insertLast(node_id, graph);
        pvertex curr = get_node(node_id, graph->_head);
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
        pvertex node_to_del = get_node(id, graph->_head);
        Node_free(node_to_del);
        del_in_edges(graph->_head, id);
        node_to_del = NULL;
    }
}

int lowest_dist(int dist[number_of_nodes]){
    int temp_dist = INT_MAX;
    int ans = -1;

    for(int i = 0; i< graph->_size; i++){
        pvertex current_node = get_node(i, graph->_head);
        if(current_node->tag == 0){
            if(dist[i] < temp_dist){
                temp_dist = dist[i];
                ans = i;
            }
        }
    }
    return ans;
}

void Dijkstra_algorithm(int index, int dist[number_of_nodes], pvertex node) {
    int distance = dist[index];
    pedge head = node->edges;

    while(head != NULL) {
        pvertex dest_node = get_node(head->dest, graph->_head);
        int new_dist = distance + head->weight;

        if (new_dist < dist[dest_node->id]) {
            dist[dest_node->id] = new_dist;
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

    pvertex src_node = get_node(src,graph->_head);
    pvertex dest_node = get_node(dest,graph->_head);
    int arr[number_of_nodes];
    arr[src] = -1;

    pvertex head = graph->_head;

    while(head != NULL) {
        if (head->id != src) {
            pedge temp = get_edge(src_node, head->id);
            if(temp != NULL){
                arr[head->id] =  temp->weight;
            }
            else{
                arr[head->id] = INT_MAX;
            }
        }
        head = head->next;
    }

    while(dest_node->tag != 1){
        int index = lowest_dist(arr);

        if(index == -1){
            return -1;
        }
        else{
            pvertex curr = get_node(index, graph->_head);
            Dijkstra_algorithm(index, arr, curr);
            curr->tag = 1;
        }
    }
    printf("%d", arr[dest]);
    return arr[dest];
}

int shortsPath(int src, int dest){
    if(src == dest){
        return -1;
    }

    pvertex src_node = get_node(src,graph->_head);
    pvertex dest_node = get_node(dest,graph->_head);
    int arr[number_of_nodes];
    arr[src] = -1;

    pvertex head = graph->_head;

    while(head != NULL) {
        if (head->id != src) {
            pedge temp = get_edge(src_node, head->id);
            if(temp != NULL){
                arr[head->id] =  temp->weight;
            }
            else{
                arr[head->id] = INT_MAX;
            }
        }
        head = head->next;
    }

    while(dest_node->tag != 1){
        int index = lowest_dist(arr);

        if(index == -1){
            return -1;
        }
        else{
            pvertex curr = get_node(index, graph->_head);
            Dijkstra_algorithm(index, arr, curr);
            curr->tag = 1;
        }
    }
    printf("%d", arr[dest]);
    return arr[dest];
}

int cost = 0;

int tsp(int c, int len){
    int count, nearest_city = INT_MAX;
    int minimum = INT_MAX, temp;
    for(count = 0; count < len; count++){
        int shortest = shortsPath(c,count);
        if((shortest != 0) && (get_node(count, graph->_head)->tag == 0))
        {
            if(shortest < minimum)
            {
                minimum = shortsPath(count,0) + shortest;
            }
            temp = shortest;
            nearest_city = count;
        }
    }
    if(minimum != INT_MAX)
    {
        cost = cost + temp;
    }
    return nearest_city;
}

void minimum_cost(int city){
    int near_node;
    set_tag(city,graph->_head, 1);
    printf("%d ", city + 1);
    near_node = tsp(city, number_of_nodes);
    if(near_node == INT_MAX){
        near_node = 0;
        printf("%d", near_node + 1);
        cost += shortsPath(city,near_node);
        return;
    }
    minimum_cost(near_node);
}

void TSP_cmd() {
    int len;
    scanf("%d", &len);
    int list[len];
    for (int i = 0; i < len; ++i) {
        int temp;
        scanf("%d", &temp);
        list[i] = temp;
    }
    minimum_cost(list[0]);
}

void build_graph_cmd(){
    if(bool == 1){
        Graph_free(graph);
    }
    scanf("%d", &number_of_nodes);
    graph = Graph_alloc();
    int src;
    pvertex prev = NULL;

    char n;
    scanf(" %c", &n);
    if (n == 110) {
        scanf(" %d", &src);

        if (src == 0) {
            Graph_insertFirst(graph, src);
            prev = graph->_head;
        }
        else {
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
            }
            else {
                add_edge(src, dest, weight, prev);
            }
        }
    } else{
        if (n == 'B') {
            insert_node_cmd();
        } else if (n == 'D') {
            delete_node_cmd();
        } else if (n == 'S') {
            shortsPath_cmd();
        } else if(n == 'T'){
            TSP_cmd();
        }
    }
    bool = 1;
}