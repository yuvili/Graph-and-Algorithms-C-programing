#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
int main()
{
    exist a;
    a.bool = 0;

    char choice;

    scanf(" %c", &choice);
    switch (choice)
    {
    case 'A':
        if (a.bool == 0)
        { // there isn't exist graph:
            char nodeSum;
            scanf(" %d", &nodeSum); // get the node number
            a.start = build_graph_cmd(nodeSum);
            a.bol = 1;
        }
        else
        {

            // need to del all the graph by free all nodes and edges
            a.start = del_graph(a.start);
            if (a.start == NULL)  //TODO: only for checking..
            {
                printf("DELETE SUCCSESFULLY")
            }
        }

        break;

    case 'B':
       a.start = insert_node_cmd(a.start); //pass the refer of the head i.e pointer to pointer
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