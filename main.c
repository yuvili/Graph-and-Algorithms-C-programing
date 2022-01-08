#include <stdio.h>
#include "algo.h"

int main()
{
    char func;

//    A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2
    scanf("%c" ,&func);
    switch (func)
    {
        case 'A':
            build_graph_cmd();
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
        default:
            printf("Error! operator is not correct");
    }

    return 0;
}