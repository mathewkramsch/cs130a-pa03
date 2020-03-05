// bst.h

#ifndef BST_H
#define BST_H
#include "../node.h"
#include "string"

class bst {
	public:
		bst(): root(0) {}
		~bst();
		
		bool insert(int val);  // true=inserted, false= val already present
		bool access(int val);  // true=found, false= not found
		bool deleteVal(int val);  // true=deleted, false= not found
		std::string print();  // returns "Empty tree" or prints pre-order,in-order,post-order

	private:
		node *root;
};

#endif
