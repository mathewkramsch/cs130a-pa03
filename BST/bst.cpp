// bst.cpp

#include "bst.h"
using namespace std;

bool bst::insert(int val) { 
// PRECONDITION: val is the value to be inserted to bst
// POSTCONDITION: if val already in bst returns false, else inserts val & returns true
	return false; 
}

bool bst::access(int val) { 
// PRECONDITION: val = to be checked if in bst
// POSTCONDITION: if val in bst return true, else return false
	return false; 
}

bool bst::deleteVal(int val) { 
// PRECONDITION: val = to be deleted from bst
// POSTCONDITION: if val != in bst return false, else delete val & return true
	return false; 
}

string bst::print() { 
// POSTCONDITION: if emptyl, returns "Empty tree"
// else returns string with pre-order,in-order,post-order w/ \n inbetween
	return "stub"; 
}

void bst::clear(node *n) {  // helper function for destructor
// PRECONDITION: n is the root of a tree (or subtree)
// POSTCONDITION: deletes left/right subtrees of n, deletes n
	if (n) {
		clear(n->left);
		clear(n->right);
		delete n;
	}
}
