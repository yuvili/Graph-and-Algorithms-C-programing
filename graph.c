#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

pnode build_graph_cmd(int nodeSum){
    int curr;
    int first = 1;
  while (nodeSum)
  {
    if (!scanf(" %d", &curr)) //if  char == (n)
    {
        if(first){


            first = 0;
        }
        scanf(" %d", &curr);

    }
    nodeSum--;
  }
 
}
 //  node head = malloc(sizeof(node));
         //   pnode phead = &head;
          //  a.start = phead;