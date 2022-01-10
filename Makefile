CC = gcc
AR = ar
FLAGS= -Wall -g
all: graph

graph: main.o algo.a

algo.a: vertex.o graph.o algo.o
		$(AR) -rcs algo.a vertex.o graph.o algo.o
main.o: main.c algo.h
		$(CC) $(FLAGS) -c main.c
graph.o: graph.c graph.h vertex.h
		$(CC) $(FLAGS) -c graph.c
vertex.o: vertex.c vertex.h
		$(CC) $(FLAGS) -c vertex.c
algo.o: algo.c algo.h
		$(CC) $(FLAGS) -c algo.c

.PHONY: all clean
clean:
		rm -f *.o *.a *.gch graph
