// node.h

#ifndef NODE_H
#define NODE_H

struct node {
	node (int d=0, int h=-1): data(d), height(h) {left=right=parent=0;}
	int data;
	int height;  // only used for avl tree
	node *left;
	node *right;
	node *parent;
};

#endif
