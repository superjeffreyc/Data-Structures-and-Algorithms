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

void BSTree::removeLeaf(Node * node){
	if (node->parent){
		if (node->parent->left == node) node->parent->left = NULL;
		else node->parent->right = NULL;
	} else {
		root = NULL;
	}
	
	delete node;
}

void BSTree::shortCircuit(Node * node){
	if (root == node){
		if (node->left) {
			node->left->parent = NULL;
			root = node->left;			
		}
		else if (node->right) {
			node->right->parent = NULL;
			root = node->right;
		}
	} else if (node->parent->left == node){
		if (node->left) {
			node->parent->left = node->left;
			node->left->parent = node->parent;
		}
		else {
			node->parent->left = node->right;
			node->right->parent = node->parent;
		}
	} else {
		if (node->left) {
			node->parent->right = node->left;
			node->left->parent = node->parent;
		}
		else {
			node->parent->right = node->right;
			node->right->parent = node->parent;
		}
	}

	delete node;
}

void BSTree::promotion(Node * node){
	Node * temp = findMax(node->right);
	node->data = temp->data;
	if (temp->left == NULL && temp->right == NULL) removeLeaf(temp);
	else shortCircuit(temp);
}

BSTree::Node * BSTree::findMin(Node * node){
	if (node->right) return findMin(node->right);
	return node;
}

BSTree::Node * BSTree::findMax(Node * node){
	if (node->left) return findMax(node->left);	
	return node;
}

bool BSTree::remove(int num){
	if (!find(num)) return false;
	
	Node * node = getNode(num);
	
	if (node->left == NULL && node->right == NULL){
		removeLeaf(node);
	}
	else if (node->left == NULL || node->right == NULL){
		shortCircuit(node);
	}
	else {
		promotion(node);
	}
		
	return true;
}

BSTree::BSTree(const BSTree &old_tree){
	if (old_tree.root) deepCopy(old_tree.root);
}

void BSTree::deepCopy(Node * node){
	insert(node->data);
	if (node->left) deepCopy(node->left);
	if (node->right) deepCopy(node->right);
}

BSTree::~BSTree(){
	if (root != NULL) deleteNode(root);
}

void BSTree::deleteNode(Node * node){
	if (node->left) deleteNode(node->left);
	if (node->right) deleteNode(node->right);
	delete node;
}

void BSTree::sortedArray(vector<int> &list){
	if (root != NULL) traverseSort(root, list);
}

void BSTree::traverseSort(Node * node, vector<int> &list){
	if (node->left) traverseSort(node->left, list);
	list.push_back(node->data);
	if (node->right) traverseSort(node->right, list);
}