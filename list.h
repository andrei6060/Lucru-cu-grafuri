#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <stdlib.h>	


typedef struct list {
	char data[100];
	struct list *prev, *next;
}*List;


List initList();


#endif 
