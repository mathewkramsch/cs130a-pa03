// utility.h - utility functions for bst.cpp

#ifndef UTILITY_H
#define UTILITY_H
#include "node.h"
// DELETE THESE
// #include <iostream>
// using namespace std;

int getHeight(node *n) {  // used for calculating height
// POSTCONDITION: returns height of node if exists, else returns 0
// bc leaf height =1, nulltpr height = 0
	if (!n) return 0;
	else return n->height;
}

int max(int a, int b) {
// POSTCONDITION: returns max of a and b, if equal returns a
	if (a==b) return a;
	if (a>b) return a;
	return b;
}

int getBalanceFactor(node *n) {  // used for calculating if subtree is unbalanced (for avl)
// POSTCONDITION: returns (height of left subtree) - (height of right subtree), if !n returns 0
	if (!n) return 0;

	// cout << "balanceFactor(" << n->data << "): " << getHeight(n->right)-getHeight(n->left) << endl;

	return getHeight(n->right) - getHeight(n->left);  // if n->left/right != exist, they = -1
}

#endif
