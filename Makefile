SRC = graph.c 
SRC2 = list.c
DEPS = BlockDag.h
DEPS2 =list.h
EXEC = blockdag
CFLAGS= -g -Wall
build: blockdag
blockdag: graph.c list.c graph.h list.h
	gcc $(CFLAGS) graph.c list.c graph.h list.h -o $(EXEC)

clean:
	rm blockdag

