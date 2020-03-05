# Makefile

CXX=g++
FLAGS=-std=c++11 -Wall -Wextra -Werror
DEPENDENCIES= main.o BST/bst.o AVL/avl.o

all: bst avl
bst: ${DEPENDENCIES}
	${CXX} $^ ${FLAGS} -o $@
avl: ${DEPENDENCIES}
	${CXX} $^ ${FLAGS} -o $@
clean:
	/bin/rm -f *.o BST/*.o AVL/*.o avl bst vgcore*
