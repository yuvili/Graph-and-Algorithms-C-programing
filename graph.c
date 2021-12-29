#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

pnode newNode(int data, pnode prev)
{
    node p = malloc(sizeof(node));
    p.node_num = data;
    p.next = NULL;
    prev->next = p;
    pnode pp = &p;
    return pp;
}

pnode creatList(int nodeSum)
{
    node head = malloc(sizeof(node)); // set the head
    pnode prev = &head;                     // pointer that keep the prev address
    for (int data = 1; data < nodeSum; data++)
    {
        prev = newNode(data, prev);
    }
    prev = &head;
    return prev;
}

pnode serach(int data, pnode head)
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

pedge creatEdge(pnode to, int w)
{
    edge p = malloc(sizeof(edge));
    p.endpoint = &to;
    p.weight = w;
    pedge pp = &p;
    return pp;
}

pnode build_graph_cmd(int nodeSum)
{
    pnode head = creatList(nodeSum); // create list of all the nodes pointers
    pnode tmpHead = head;            // build cause we don't what to change the val of the head pointer,use when you send the head ptr to other punc
    int dis = 0, w = 0, src = 0, count = 0;

    while (count != nodeSum) // while we didnt pass all the nodes
    {
        if (scanf("%d", &src))
        {
            pnode from = serach(src, tmpHead); // return the address of the src node
            tmpHead = head;                    // reaset the tmpHead
            int firstEdge = 1;                 // indicate that its tne first edge that create
            pedge curEdeg = NULL;
            pedge prev = NULL; // pointer to the previos edge that connected to the *same* node
            while (scanf("%d", &dis))
            {
                pnode to = serach(dis, tmpHead);
                tmpHead = head; // reaset the tmpHead
                scanf("%d", &w);
                curEdeg = creatEdge(to, w);
                if (firstEdge)
                {
                    from->edges = curEdeg; // the src node point to the first edge that we create
                    firstEdge = 0;
                    prev = curEdeg;
                }
                else
                {
                    prev->next = curEdeg; // the edge that came before will point to the curr edge (i.e edge)
                    curEdeg->next = NULL;
                    prev = curEdeg;
                }
            }
        }
        count++;
    }
    return head;
}
// A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 n 3 T 3 2 1 3 S 2 0
// . . .

void del_edges(pedge first) // delete all the edges that Coming out from the curr node
{
    pedge temp = first;
    while (temp != NULL)
    {
        temp = first->next;
        free(first);
        first = temp;
    }
}

pnode del_graph(pnode head)
{
    pnode temp = head;
    while (temp != NULL)
    {
        temp = head->next;
        del_edges(head->edges);
        free(head);
        head = temp;
    }

    return head;
}
/// B 5 0 4 2 1
/// * *
pnode insert_node_cmd(pnode head)
{
    int id;
    pnode tmpHead = head;
    pnode ans = NULL;
    scanf(" %d", &id); // scan the node id
    ans = serach(id, tmpHead);
    tmpHead = head;
    if (ans != NULL) // there is node with the same id:
    {
        del_edges(ans);
    }
    else
    {
        node p = malloc(sizeof(node));
        p.node_num = id;
        p.next = head;
         while (scanf("%d", &dis)) // how can i stop scan 
            {
                pnode to = serach(dis, tmpHead);
                tmpHead = head; // reaset the tmpHead
                scanf("%d", &w);
                curEdeg = creatEdge(to, w);
                if (firstEdge)
                {
                    from->edges = curEdeg; // the src node point to the first edge that we create
                    firstEdge = 0;
                    prev = curEdeg;
                }
                else
                {
                    prev->next = curEdeg; // the edge that came before will point to the curr edge (i.e edge)
                    curEdeg->next = NULL;
                    prev = curEdeg;
                }
            }

        head = &p;

    }
    return head;
}