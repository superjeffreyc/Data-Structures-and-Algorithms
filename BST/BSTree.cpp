#include "BSTree.h"
#include <string>

BSTree::BSTree() {
	root = NULL;
}

bool BSTree::empty() {
	return (root == NULL);
}

bool BSTree::insert(int val) {

	if (empty()) {
		root = new BSTree::Node(val);
		return true;
	}

	Node * temp = root;
	Node * parent = NULL;

	while (temp) {
		parent = temp;
		if (val < temp->data) temp = temp->left;
		else if (val > temp->data) temp = temp->right;
		else return false;
	}

	temp = new BSTree::Node(val);
	temp->parent = parent;

	if (parent) {
		if (val < parent->data) parent->left = temp;
		else if (val > parent->data) parent->right = temp;
	}

	return true;
}

bool BSTree::find(int val) {

	Node * temp = root;

	while (temp) {
		if (val < temp->data) temp = temp->left;
		else if (val == temp->data) return true;
		else if (val > temp->data) temp = temp->right;
	}

	return false;
}

BSTree::Node::Node(int val) {
	data = val;
	left = right = parent = NULL;
}
