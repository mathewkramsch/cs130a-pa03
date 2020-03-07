// avl.cpp

#include "avl.h"
#include "../utility.h"
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
	balance(n);
	return true;
}

bool avl::deleteVal(int val) { 
// PRECONDITION: val = to be deleted from avl
// POSTCONDITION: if val != in avl return false, else delete val & return true
// tree is balanced after deletion
	pair<node*,bool> p = bst::deleteVal_helper(val);
	if (!p.second) return false;
	heightUpdate(p.first);
	balance(p.first);
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
// PRECONDITION: n is the deepest node in avl in need of balancing
// POSTCONDITION: avl tree is balanced: every node's |balance factor| <= 1
	if (!n) return;
	int balanceFactor = getBalanceFactor(n);
	node *tmp =n;

	if (balanceFactor < -1) {  // too tall on left side (make sure dont rotate unless w/ leaf)
		if (getBalanceFactor(n->left) < 0) { rightRotate(n); return; } // left-left case
		else if (getBalanceFactor(n->left) > 0) {  // left-right case
			leftRotate(n->left);
			rightRotate(tmp);
			return;
		}
	}
	else if (balanceFactor > 1) {  // too tall on right side
		if (getBalanceFactor(n->right) > 0) { leftRotate(n); return; } // right-right case
		else if (getBalanceFactor(n->right) < 0) {  // right-left case
			rightRotate(n->right);
			leftRotate(tmp);
			return;
		}
	}
	balance(n->parent);
}

void avl::leftRotate(node *n) { 
// PRECONDTION: n's |balanceFactor| > 1
// POSTCONDITION: does a left rotation (|balanceFactor| <= 1 not guaranteed)
	bool nIsAleftChild(false), nIsArightChild(false);
	node *p = n->parent;
	if (p) {
		if (p->left && p->left->data==n->data) nIsAleftChild = true;
		else if (p->right && p->right->data==n->data) nIsArightChild = true;
	}

	node *rightTmp = n->right;

	rightTmp->parent = p;
	if (nIsAleftChild) p->left = rightTmp;
	else if (nIsArightChild) p->right = rightTmp;
	else root = rightTmp;

	n->right = n->right->left;  // may be nullptr
	if (n->right) n->right->parent = n;
	rightTmp->left = n;
	n->parent = rightTmp;

	heightUpdate(n);
}

void avl::rightRotate(node *n) { 
// PRECONDTION: n's |balanceFactor| > 1
// POSTCONDITION: does a right rotation (|balanceFactor| <= 1 not guaranteed)
	bool nIsAleftChild(false), nIsArightChild(false);
	node *p = n->parent;
	if (p) {
		if (p->left && p->left->data==n->data) nIsAleftChild = true;
		else if (p->right && p->right->data==n->data) nIsArightChild = true;
	}

	node *leftTmp = n->left;

	leftTmp->parent = p;
	if (nIsAleftChild) p->left = leftTmp;
	else if (nIsArightChild) p->right = leftTmp;
	else root = leftTmp;

	n->left = n->left->right;  // may be nullptr
	if (n->left) n->left->parent = n;
	leftTmp->right = n;
	n->parent = leftTmp;

	heightUpdate(n);
}
