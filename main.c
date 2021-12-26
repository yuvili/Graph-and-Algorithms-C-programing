#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main()
{
    exist a;
    a.bol = 0;

    char choice;

    scanf(" %c", &choice);
    switch (choice)
    {
    case 'A':
        if (a.bol == 0)
        { // there isn't exist graph:
            char nodeSum;
            scanf(" %d", &nodeSum); // get the node number
            a.start = build_graph_cmd(nodeSum);
            a.bol=1;
        }
        else
        {
            // need to del all the graph by free all nodes and edges
            // build_graph_cmd();
        }

        break;

    case 'B':
        insert_node_cmd();
        break;

    case 'D':
        delete_node_cmd();
        break;

    case 'S':
        shortsPath_cmd();
        break;

    case 'T':
        TSP_cmd();
        break;
    }

    return 0;
}