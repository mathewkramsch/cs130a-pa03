// node.h

#ifndef NODE_H
#define NODE_H

struct node {
	node (int d, int h=0): data(d), height(h) {left=right=parent=0;}
	int data;
	int height;  // only care about for avl tree
	node *left;
	node *right;
	node *parent;
};

#endif
