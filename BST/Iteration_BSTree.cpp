#include "BSTree.h"
#include <string>

/*
 * Creates a BST with a null root
 */
BSTree::BSTree() {
	root = NULL;
}

/*
 * Determines if the BST is empty or not
 */
bool BSTree::empty() {
	return (root == NULL);
}

/*
 * If the BST is empty, insert the node at the root
 * Otherwise, insert the node in the proper position
 * 
 * This method does not insert a duplicate node
 * Returns whether a node was successfully inserted
 */
bool BSTree::insert(int val) {

	// Set root to new node if tree is empty
	if (empty()) {
		root = new BSTree::Node(val);
		return true;
	}

	Node * temp = root;
	Node * parent = NULL;

	// Go through the BST iteratively until either the value can be placed in the tree or a duplicate value already exists
	while (temp) {
		parent = temp;	// Keep updating the parent until null is reached
		if (val < temp->data) temp = temp->left;
		else if (val > temp->data) temp = temp->right;
		else return false;
	}

	temp = new BSTree::Node(val);
	temp->parent = parent;	// Update parent of new child node

	// Update child of parent node
	if (parent) {
		if (val < parent->data) parent->left = temp;
		else if (val > parent->data) parent->right = temp;
	}

	return true;
}

// Search for a value in the BST and returns whether it exists in the tree or not
bool BSTree::find(int val) {

	Node * temp = root;

	// Compare val to the current node until null is reached or the value is found
	while (temp) {
		if (val < temp->data) temp = temp->left;
		else if (val == temp->data) return true;
		else if (val > temp->data) temp = temp->right;
	}

	return false;	// Cannot find the value
}

// Creates a new node
BSTree::Node::Node(int val) {
	data = val;
	left = right = parent = NULL;
}
