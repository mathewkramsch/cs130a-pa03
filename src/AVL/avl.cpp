// avl.cpp

#include "avl.h"
#include "../utility.h"
#include <iostream>  // DELETE, JUST FOR DEBUGGING
using namespace std;

bool avl::insert(int val) { 
// PRECONDITION: val is the value to be inserted to avl
// POSTCONDITION: if val already in avl returns false, else inserts val & returns true
// tree is balanced after insert
	if (!root) {
		root = new node(val,0);
		return true;
	}

	node *n = bst::insert_helper(val,root);  // n is the parent of node inserted
	if (!n) return false;  // if n=nullptr, then val already in avl
	heightUpdate(n);
	balance(root);
	return true;
}

bool avl::deleteVal(int val) { 
// PRECONDITION: val = to be deleted from avl
// POSTCONDITION: if val != in avl return false, else delete val & return true
// tree is balanced after deletion

	pair<node*,bool> p = bst::deleteVal_helper(val);
	if (!p.second) return false;
	heightUpdate(p.first);
	balance(root);
	return true;
}

void avl::heightUpdate(node *n) {
// PRECONDITION: n is the deepest node in avl in need of height-updating
// POSTCONDITION: all nodes in tree n-up get +1 height
	while (n) {
		n->height = 1 + max(getHeight(n->left),getHeight(n->right));
		n = n->parent;
	}	
}

void avl::balance(node *n) { 
// PRECONDITION: n is the root of a tree/subtree
// POSTCONDITION: avl tree is balanced: every node's |balance factor| <= 1
	if (!n) return;
	int balanceFactor = getBalanceFactor(n);

	if (balanceFactor < -1 && n->height < 3) {  // too tall on left side (make sure dont rotate unless w/ leaf)
		if (getBalanceFactor(n->left) < 0) rightRotate(n);  // left-left case
		else if (getBalanceFactor(n->left) > 0) {  // left-right case
			cout << "left-right\n";
		}
	}
	else if (balanceFactor > 1 && n->height < 3) {  // too tall on right side
		if (getBalanceFactor(n->right) > 0) leftRotate(n);  // right-right case
		else if (getBalanceFactor(n->right) < 0) {  // right-left case
			cout << "right-left\n";
		}
	}
	balance(n->left);
	balance(n->right);
}

void avl::leftRotate(node *n) { 
// PRECONDTION: n's |balanceFactor| > 1
// POSTCONDITION: does a left rotation (|balanceFactor| <= 1 not guaranteed)
	cout << "left rotate that bitch\n";
}

void avl::rightRotate(node *n) { 
// PRECONDTION: n's |balanceFactor| > 1
// POSTCONDITION: does a right rotation (|balanceFactor| <= 1 not guaranteed)
	cout << "right rotate that bitch\n";
}
