// bst.h

#ifndef BST_H
#define BST_H
#include "../node.h"
#include "string"

class bst {
	public:
		bst(): root(0) {}
		~bst() { clear(root); }
		
		bool insert(int val);
		bool access(int val);
		bool deleteVal(int val);
		std::string print();

	protected:
		node *root;

		bool insert_helper(int val, node *n);
		node* access_helper(int val, node *n);
		node* findSuccessor(node *n);
		std::string print_preorder();
		std::string print_inorder();
		std::string print_postorder();
		void clear(node *n);
};

#endif
