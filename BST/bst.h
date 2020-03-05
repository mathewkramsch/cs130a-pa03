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

		void clear(node *n);
};

#endif
