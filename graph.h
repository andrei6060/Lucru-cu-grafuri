#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct graph {
	int V; 
	List *adjLists; 
	int *visited; 
}*Graph;


Graph initGraph(int V);

#endif 
