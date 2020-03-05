// avl.cpp

#include "avl.h"
using namespace std;

bool avl::insert(int val) { 
// PRECONDITION: val is the value to be inserted to avl
// POSTCONDITION: if val already in avl returns false, else inserts val & returns true
// tree is balanced after insert
	return false; 
}

bool avl::access(int val) { 
// PRECONDITION: val = to be checked if in avl
// POSTCONDITION: if val in avl return true, else return false
	return false; 
}

bool avl::deleteVal(int val) { 
// PRECONDITION: val = to be deleted from avl
// POSTCONDITION: if val != in avl return false, else delete val & return true
// tree is balanced after deletion
	return false; 
}

string avl::print() { 
// POSTCONDITION: if emptyl, returns "Empty tree"
// else returns string with pre-order,in-order,post-order w/ \n inbetween
	return "stub"; 
}

void avl::clear(node *n) {  // helper function for destructor
// PRECONDITION: n is the root of a tree (or subtree)
// POSTCONDITION: deletes left/right subtrees of n, deletes n
	if (n) {
		clear(n->left);
		clear(n->right);
		delete n;
	}
}
