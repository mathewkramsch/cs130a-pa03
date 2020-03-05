# makefile

CXX=g++
FLAGS=-std=c++11 -Wall -Wextra -Werror
DEPENDENCIES= main.o BST/bst.o AVL/avl.o

bst: program
	mv program bst
avl: program
	mv program avl
program: ${DEPENDENCIES}
	${CXX} $^ ${FLAGS} -o $@
clean:
	/bin/rm -f *.o BST/*.o AVL/*.o avl bst program vgcore*
