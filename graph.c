#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

node *newNde(int data, pnode prev)
{
    node *p = (node *)malloc(sizeof(node));
    p->node_num = data;
    p->next = NULL;
    prev->next = p;
    return p;
}

node *creatList(int nodeSum)
{
    node *head = (node *)malloc(sizeof(node)); // set the head
    pnode prev = head;                         // pointer that keep the prev address
    for (int data = 1; data < nodeSum; data++)
    {
        prev = newNde(data, prev);
    }
    return head;
}

node *serach(int data, node *head)
{
    if (head == NULL)
    {
        return;
    }
    while (head != NULL)
    {
        if (head->node_num == data)
        {
            return &head;
        }
        head->next = head->next->next;
    }
    return NULL;
}

edge *creatEdge(node *from, node *to, int w)
{
    edge *p = (edge *)malloc(sizeof(edge));
    p->endpoint = &to;
    p->weight = w;
    return p;
}

pnode build_graph_cmd(int nodeSum)
{
    node *head = creatList(nodeSum);
    int dis = 0, w = 0, src = 0;
    int count = 0;
    while (count != nodeSum)
    {
        if (scanf("%d", &src))
        {                                   //  *need to check if the head pointer change while send him to other function*
            node *from = serach(src, head); // return the address of the src node(if exist..)
            edge *curEdeg = NULL;
            int firstEdge = 1;
            pedge prev = null; //pointer to the previos edge that connected to the *same* node
            while (scanf("%d", &dis))
            {
                node *to = serach(dis, head);
                scanf("%d", &w);
                curEdeg = creatEdge(to, w);
                if (firstEdge)
                {
                    from->edges = curEdeg; //the src node point to the first edge that we create
                    firstEdge = 0;
                    prev = curEdeg;
                }
                else{
                    prev->next = curEdeg; //the edge that came before will point to the curr edge (i.e edge)
                    prev = curEdeg;
                }

            }
        }
        count++;
    }
    return head;
}               // A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 n 3 T 3 2 1 3 S 2 0
                // . . .
