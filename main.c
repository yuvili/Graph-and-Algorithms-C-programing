#include <stdio.h>
#include "algo.h"

int main() {

    char func;
    while (scanf("%c", &func) != EOF) {
        if (func == 'A') {
            build_graph_cmd();
        } else if (func == 'B') {
            insert_node_cmd();
        } else if (func == 'D') {
            delete_node_cmd();
        } else if (func == 'S') {
            shortsPath_cmd();
        } else if(func == 'T'){
            TSP_cmd();
        }
    }

    return 0;
}