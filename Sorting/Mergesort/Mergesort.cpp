#include "Mergesort.h"
#include <algorithm>

using namespace std;

// Recursively split the array into two parts until there are only 1 or 2 elements remaining, then merge everything back together
int * Mergesort::mergesort(int * array, int size) {

	// Base cases for recursive calls
	if (size == 1) return array;	// A single element is already sorted
	else if (size == 2) {		// Manually sort two elements
		if (array[0] > array[1]) swap(array[0], array[1]);
		return array;
	}

	// Create two new arrays for each half
	int * arrayLeft = new int[size / 2];
	int * arrayRight = new int[size - size / 2];

	// Fill the first array with the left half
	for (int i = 0; i < size / 2; i++) {
		arrayLeft[i] = array[i];
	}

	// Fill the second array with the right half
	// Needs two counters: one for half-filled original array and one for arrayRight
	for (int i = 0, j = size / 2; j < size; i++, j++) {
		arrayRight[i] = array[j];
	}

	// Recursively split the two arrays in half again
	arrayLeft = mergesort(arrayLeft, size / 2);
	arrayRight = mergesort(arrayRight, size - size / 2);
	
	// Merge the two halves back together in sorted order
	int * merged = merge(arrayLeft, arrayRight, size / 2, size - size / 2);

	// Copy the sorted array into the original array
	for (int i = 0; i < size; i++) {
		array[i] = merged[i];
	}

	return array;
}

// Merge two smaller arrays into a single larger array
int * Mergesort::merge(int * arrayA, int * arrayB, int sizeA, int sizeB) {
	int * array = new int[sizeA + sizeB];	// Create enough space to combine two arrays
	int aIndex = 0, bIndex = 0;		// Indices for the two arrays
	int i = 0;				// Index for the new array

	// Comparing elements starting at the beginning of both array A and B, put the smaller element into the new array
	// Then, increment the counter for either array A or B, depending on which one inserted a value into the new array
	for (; aIndex < sizeA && bIndex < sizeB; i++) {
		if (arrayA[aIndex] < arrayB[bIndex]) array[i] = arrayA[aIndex++];
		else array[i] = arrayB[bIndex++];
	}

	// If array A still has elements
	if (aIndex < sizeA) {
		for (; aIndex < sizeA; i++) {
			array[i] = arrayA[aIndex++];
		}
	}
	// array B still has more elements
	else {
		for (; bIndex < sizeB; i++) {
			array[i] = arrayB[bIndex++];
		}
	}

	return array;
}
