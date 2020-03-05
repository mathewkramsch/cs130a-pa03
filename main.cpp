// main.cpp

#include "BST/bst.h"
#include "AVL/avl.h"
#include <sstream>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {

	if (argc!=2) { cerr << "no input\n"; return 1; }

	avl a;
	bst b;

	string type;
	if (argv[0]=="./bst") type="bst";
	else if (argv[0]=="./avl") type="avl";

	stringstream ss(argv[1]);
	string word="";  // to get word input
	int num=0;  // to get number input
	char comma;  // to parse out the comma after each input command
	string mssg="";  // message printed for each method
	bool success;  // true if insert/access/delete method successful

	while (ss >> word) {
		if (word=="print," || word=="print") { 
			if (type=="bst") cout << b.print() << endl; 
			else cout << a.print() << endl;
			continue; 
		}

		ss >> num;
		if (word=="insert") {
			if (type=="bst") success = b.insert(num);
			else success = a.insert(num);
			if (success) mssg = "Element inserted";
			else mssg = "Element already present";
		}
		else if (word=="access") {
			if (type=="bst") success = b.access(num);
			else success = a.access(num);
			if (success) mssg = "Element accessed";
			else mssg = "Element not found";
		}
		else if (word=="delete") {
			if (type=="bst") success = b.deleteVal(num);
			else success = a.deleteVal(num);
			if (success) mssg = "Element deleted";
			else mssg = "Element not found";
		}
		cout << mssg << endl;
		ss >> comma;
	}

	return 0;
}
