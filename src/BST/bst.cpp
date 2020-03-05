// bst.cpp

#include "bst.h"
#include <iostream>  // DELETE, JUST FOR DEBUGGING
#include <stack>
using namespace std;

bool bst::insert(int val) { 
// PRECONDITION: val is the value to be inserted to bst
// POSTCONDITION: if val already in bst returns false, else inserts val & returns true
	if (!root) {
		root = new node(val,0);
		return true;
	}
	return insert_helper(val,root,0);
}
bool bst::insert_helper(int val, node *n, int height) {
// PRECONDITION: val = value to be inserted to bst, n = root of tree/subtree (may = nullptr)
// POSTCONDITION: if val already in bst returns false, else inserts val & returns true
	if (val == n->data) return false;
	height++;
	if (val < n->data) {
		if (n->left) return insert_helper(val,n->left,height);
		else { n->left = new node(val,height); n->left->parent = n; }
	}
	else if (val > n->data) {
		if (n->right) return insert_helper(val,n->right,height);
		else { n->right = new node(val,height); n->right->parent = n; }
	}
	return true;
}

bool bst::access(int val) const { 
// PRECONDITION: val = to be checked if in bst
// POSTCONDITION: if val in bst return true, else return false
	if (access_helper(val,root)) return true;
	else return false;
}
node* bst::access_helper(int val, node *n) const {
// PRECONDITION: val = to be checked if in bst, n = root of tree/subtree
// POSTCONDITION: if val in bst returns node, else return nullptr
	if (!n) return nullptr;
	if (val == n->data) return n;
	if (val < n->data) return access_helper(val, n->left);
	return access_helper(val, n->right);

}

bool bst::deleteVal(int val) { 
// PRECONDITION: val = to be deleted from bst
// POSTCONDITION: if val != in bst return false, else delete val & return true
	node *n = access_helper(val, root);
	if (!n) return false;

	bool isAleftChild(false), isArightChild(false);
	node *p = n->parent;
	if (p) {
		if (p->left && p->left->data==val) isAleftChild=true;
		else isArightChild=true;
	}

	// if no children
	if (!n->left && !n->right) {  // if no children
		if (isAleftChild) p->left = nullptr;
		else if (isArightChild) p->right = nullptr;
		else root = nullptr;
	} else if (n->left && n->right) {  // if 2 children
		node *s = findSuccessor(n);  // s must exist since n has 2 children
		int sVal = s->data;
		deleteVal(s->data);
		n->data = sVal;  // swap values of n and n's successor (not height)
		return true;
	} else if (n->left) {  // if 1 child (left)
		if (isAleftChild) p->left = n->left;
		else if (isArightChild) p->right = n->left;
		else root = n->left;
		n->left->parent = p;
		n->left->height--;  // n->left moves up + replaces n
	} else {  // if 1 child (right)
		if (isAleftChild) p->left = n->right;
		else if (isArightChild) p->right = n->right;
		else root = n->right;
		n->right->parent = p;
		n->right->height--;
	}

	delete n;
	return true;
}
node* bst::findSuccessor(node *n) const {
// PRECONDITION: n exists and has 2 children
// POSTCONDITION: returns n's successor (greater node than n w/ least value in bst)
	n = n->right;
	while (n->left) n=n->left;
	return n;
}


string bst::print() const { 
// POSTCONDITION: if empty, returns "Empty tree"
// else returns string with pre-order,in-order,post-order w/ "\n" inbetween
	if (!root) return "Empty tree\n";
	string str = "";
	str += print_preorder();
	str += print_inorder();
	str += print_postorder();
	return str;
}
string bst::print_preorder() const {
// PRECONDITION: tree is not empty
// POSTCONDITION: returns string with pre-order w/ "\n" at end
	string str = "";
	stack<node *> s;
	node *n;
	s.push(root);
	while (!s.empty()) {
		n = s.top();  // make n = to current (root)
		s.pop();  // pop off top of stack
		str += to_string(n->data) + " ";

		if (n->right) s.push(n->right);  // push right first (backwards bc stack)
		if (n->left) s.push(n->left);  // then push left
	}
	str += "\n";
	return str;
}

string bst::print_inorder() const {
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
string bst::print_postorder() const {
// PRECONDITION: tree is not empty
// POSTCONDITION: returns string with post-order w/ "\n" at end
	string str = "";
	stack<node *> s1, s2;
	s1.push(root);
	node *n;
	while (!s1.empty()) {
		n = s1.top();
		s1.pop();
		s2.push(n);
		if (n->left) s1.push(n->left);  // can do left->right bc 2nd stack flips order
		if (n->right) s1.push(n->right);
	}
	while(!s2.empty()) {
		n = s2.top();
		s2.pop();
		str += to_string(n->data) + " ";
	}
	str += "\n";
	return str;
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
