// avl.h

#ifndef AVL_H
#define AVL_H
#include "../node.h"
#include "string"

class avl {
	public:
		avl(): root(0) {}
		~avl();

		bool insert(int val);
		bool access(int val);
		bool deleteVal(int val);
		std::string print();

	private:
		node *root;
};

#endif
