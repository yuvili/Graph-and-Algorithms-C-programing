#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

pnode build_graph_cmd(int nodeSum)
{
    char Ccurr;
    int Icurr;
    int first = 1;
    pnode prev;
    while (nodeSum)
    {
        if (scanf(" %c", &Ccurr)) // if  char == (n)
        {
            while (scanf(" %d", &Icurr)) // while the input isn't n:
            {
                if (first)
                { // define the head node:
                    node head = malloc(sizeof(node));
                    pnode phead = &head;
                    prev = &head;
                    head.node_num = Icurr;
                    head.next = NULL;
                    first = 0;
                }
                else
                {
                 node n = malloc(sizeof(node));
                 pnode pn = &n;
                 n.node_num = Icurr; //need to connect the frev
                 n.next = prev;
                 prev = pn;
                }
                
                    int dest = Icurr;
                    scanf(" %d", &Icurr);
                    int weight = Icurr;
                    edge e = malloc(sizeof(edge));
                    e.weight = weight;
                    //check if the dest node already exist - need to build a function..
                    e.endpoint = dest;
                
            }

            //  scanf(" %d", &curr);
        }
        nodeSum--;
    }
    return phead;
}
