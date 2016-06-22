/*
 * This program uses an array to represent a heap.
 *
 * For example, [1,2,3,4,5,6,7] is equivalent to:
 *
 *             1
 *            / \
 *           2   3
 *          / \ / \
 *         4  5 6  7
 *
 * Left Index: 2i + 1
 * Right Index: 2i + 2
 *
 */

#include "Heapsort.h"
#include <algorithm>

using namespace std;

// Sorts an array by turning it into a max-heap and repeatedly swapping the root with the last element of the effective array 
int * Heapsort::heapsort(int * array, int size) {

	if (size == 1) return array;

	// Convert the array into a max-heap
	heapify(array, size);
	
	// Continue swapping elements until the effective size is 0
	// All correctly sorted elements will be outside the effective size of the array
	while (size) {
		
		// Swap the largest element in the heap (element 0) with the last element
		swap(array[0], array[size - 1]);
		
		// Decrement the effective size of the array
		size--;
		
		// Correct the heap structure since we just swapped two elements
		siftdown(array, size, 0);
	}

	return array;
}

// Convert the current array into a heap
void Heapsort::heapify(int * array, int size) {
	
	// Start at the last parent node and work back towards the top of the heap
	for (int i = (size - 2) / 2; i >= 0; i--) {
		// Move the current node down the heap if there are larger children
		siftdown(array, size, i);
	}
}

// If there is a larger child node below the current node, move the current node down by swapping it with that child
int Heapsort::siftdown(int * array, int size, int parentIndex) {
	if (parentIndex < 0 || parentIndex >= size) return parentIndex;

	// Continue until we have reached a leaf, in which there can be no more swapping done
	while (!isLeaf(parentIndex, size)) {
		// Temporary placeholder until comparison with other child node
		int maxChildIndex = getLeft(parentIndex);

		// Determines the larger of the two children
		if (maxChildIndex + 1 < size && array[maxChildIndex] < array[maxChildIndex + 1]) {
			maxChildIndex += 1;
		}

		if (array[maxChildIndex] <= array[parentIndex]) return parentIndex;
		
		swap(array[maxChildIndex], array[parentIndex]);
		parentIndex = maxChildIndex;	// Keep the same parent that was just sifted down
	}

	return i;
}

// Checks if the node has any children
bool Heapsort::isLeaf(int nodeIndex, int size) {
	// If a parent has a child, it must exist within the bounds of the array
	if (((2 * nodeIndex) + 2) < size || ((2 * nodeIndex) + 1) < size) return false;
	return true;
}

// Get the left child of the parent
int Heapsort::getLeft(int parentIndex) {
	return ((2 * parentIndex) + 1);
}

