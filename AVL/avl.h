// avl.h

#ifndef AVL_H
#define AVL_H
#include "../node.h"
#include "string"

class avl {
	public:
		avl(): root(0) {}
		~avl() { clear(root); }

		bool insert(int val);
		bool access(int val);
		bool deleteVal(int val);
		std::string print();

	private:
		node *root;

		void clear(node *n);
};

#endif
