#ifndef BSTREE_H
#define BSTREE_H

class BSTree {

private:
	class Node {

	public:
		int data;
		Node * left;
		Node * right;
		Node * parent;
		Node(int val);
	};

public:
	BSTree();
	bool empty();
	bool insert(int val);
	bool find(int val);
	Node * root;

};

#endif
