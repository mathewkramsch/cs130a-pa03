# Makefile

CXX=g++
FLAGS=-std=c++11 -Wall -Wextra -Werror
DEPENDENCIES= src/main.o src/BST/bst.o src/AVL/avl.o

all: obj bst avl cleanup

bst: ${DEPENDENCIES}
	${CXX} $^ ${FLAGS} -o $@
avl: ${DEPENDENCIES}
	${CXX} $^ ${FLAGS} -o $@

obj:
	mkdir obj
cleanup:
	mv src/*.o src/AVL/*.o src/BST/*.o -t obj
clean:
	/bin/rm -f -r obj avl bst vgcore*
