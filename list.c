#include "list.h"

List initList()
{
	List list;

	list = (List) malloc(sizeof(struct list));
	list->next = NULL;
	list->prev = NULL;
	return list;
}



