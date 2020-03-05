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

	private:
		node *root;

		bool insert_helper(int al, node *n);
		bool access_helper(int val, node *n);
		std::string print_preorder();
		std::string print_inorder();
		std::string print_postorder();
		void clear(node *n);
};

#endif
