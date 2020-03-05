// bst.cpp

#include "bst.h"
#include <iostream>  // DELETE, JUST FOR DEBUGGING
#include <stack>
using namespace std;

bool bst::insert(int val) { 
// PRECONDITION: val is the value to be inserted to bst
// POSTCONDITION: if val already in bst returns false, else inserts val & returns true
	if (!root) {
		root = new node(val);
		return true;
	}
	return insert_helper(val,root);
}
bool bst::insert_helper(int val, node *n) {
// PRECONDITION: val = value to be inserted to bst, n = root of tree/subtree (may = nullptr)
// POSTCONDITION: if val already in bst returns false, else inserts val & returns true
	if (val == n->data) return false;
	if (val < n->data) {
		if (n->left) return insert_helper(val,n->left);
		else { n->left = new node(val); n->left->parent = n; }
	}
	else if (val > n->data) {
		if (n->right) return insert_helper(val,n->right);
		else { n->right = new node(val); n->right->parent = n; }
	}
	return true;
}

bool bst::access(int val) { 
// PRECONDITION: val = to be checked if in bst
// POSTCONDITION: if val in bst return true, else return false
	return access_helper(val,root); 
}
bool bst::access_helper(int val, node *n) {
// PRECONDITION: val = to be checked if in bst, n = root of tree/subtree
// POSTCONDITION: if val in bst return true, else return false
	if (!n) return false;
	if (val == n->data) return true;
	if (val < n->data) return access_helper(val, n->left);
	return access_helper(val, n->right);

}

bool bst::deleteVal(int val) { 
// PRECONDITION: val = to be deleted from bst
// POSTCONDITION: if val != in bst return false, else delete val & return true
	return false; 
}

string bst::print() { 
// POSTCONDITION: if empty, returns "Empty tree"
// else returns string with pre-order,in-order,post-order w/ "\n" inbetween
	if (!root) return "Empty tree";
	string str = "";
	str += print_preorder();
	str += print_inorder();
	// str += print_postorder();
	return str;
}
string bst::print_preorder() {
// PRECONDITION: tree is not empty
// POSTCONDITION: returns string with pre-order w/ "\n" at end
	string str = "";
	stack<node *> s;
	s.push(root);
	while (!s.empty()) {
		node *n = s.top();  // make n = to current (root)
		s.pop();  // pop off top of stack
		str += to_string(n->data) + " ";

		if (n->right) s.push(n->right);  // push right first (backwards bc stack)
		if (n->left) s.push(n->left);  // then push left
	}
	str += "\n";
	return str;
}

string bst::print_inorder() {
// PRECONDITION: tree is not empty
// POSTCONDITION: returns string with in-order w/ "\n" at end
	string str = "";
	stack<node *> s;
	node *n = root;
	while (n || !s.empty()) {
		while (n) {  // go all the way to the left
			s.push(n);
			n = n->left;
		}
		n = s.top();
		s.pop();
		str += to_string(n->data) + " ";  // print leftmost
		n = n->right;  // go to the right
	}
	str += "\n";
	return str;
}
string bst::print_postorder() {
// PRECONDITION: tree is not empty
// POSTCONDITION: returns string with post-order w/ "\n" at end
	return "poo";
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
