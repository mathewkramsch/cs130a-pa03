// avl.h

#ifndef AVL_H
#define AVL_H
#include "../node.h"
#include "../BST/bst.h"
#include "string"

class avl : public bst {
	public:
		bool insert(int val);  // override to balance after insert/deleteVal
		bool deleteVal(int val);

	private:
		void heightUpdate(node *n);
		void balance();
};

#endif
