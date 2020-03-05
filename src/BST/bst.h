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
		bool access(int val) const;
		bool deleteVal(int val);
		std::string print() const;

	protected:
		node *root;

		bool insert_helper(int val, node *n);
		node* access_helper(int val, node *n) const;
		node* findSuccessor(node *n) const;
		std::string print_preorder() const;
		std::string print_inorder() const;
		std::string print_postorder() const;
		void clear(node *n);
};

#endif
