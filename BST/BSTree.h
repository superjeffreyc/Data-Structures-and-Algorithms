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
	
	void removeLeaf(Node *);
	void shortCircuit(Node *);
	void promotion(Node *);
	Node * findMin(Node *);
	Node * findMax(Node *);

public:
	BSTree();
	bool empty();
	bool insert(int val);
	bool find(int val);
	Node * root;
	bool remove(int);

};

#endif
