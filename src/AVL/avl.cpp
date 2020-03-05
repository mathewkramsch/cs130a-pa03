// avl.cpp

#include "avl.h"
#include <iostream>  // DELETE, JUST FOR DEBUGGING
using namespace std;

bool avl::insert(int val) { 
// PRECONDITION: val is the value to be inserted to avl
// POSTCONDITION: if val already in avl returns false, else inserts val & returns true
// tree is balanced after insert
	bool returnVal = bst::insert(val);
	balance();
	return returnVal;
}

bool avl::deleteVal(int val) { 
// PRECONDITION: val = to be deleted from avl
// POSTCONDITION: if val != in avl return false, else delete val & return true
// tree is balanced after deletion
	bool returnVal = bst::deleteVal(val);
	balance();
	return returnVal; 
}

void avl::balance() { cout << "balanced that shit\n"; }
