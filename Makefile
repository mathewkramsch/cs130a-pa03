# Makefile

CXX=g++
FLAGS=-std=c++11 -Wall -Wextra -Werror
DEPENDENCIES= src/main.o src/BST/bst.o src/AVL/avl.o

#test: all
#	./avl "insert 10, insert 20, insert 30, print"
#	./bst "insert 50, insert 60, insert 40, insert 10, insert 20, insert 15, insert 30, print, delete 40, print, insert 40, insert 70, print"
#	./avl "insert 50, insert 60, insert 40, insert 10, insert 20, insert 15, insert 30, print, delete 40, print, insert 40, insert 70, print"


all: make_obj_dir bst avl cleanup

bst: ${DEPENDENCIES}
	${CXX} $^ ${FLAGS} -o $@
avl: ${DEPENDENCIES}
	${CXX} $^ ${FLAGS} -o $@

make_obj_dir:
	mkdir -p obj
cleanup:
	mv src/*.o src/AVL/*.o src/BST/*.o -t obj
clean:
	/bin/rm -f -r obj src/*.o src/AVL/*.o src/BST/*.o avl bst vgcore*
