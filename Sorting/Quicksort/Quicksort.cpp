#include "Quicksort.h"
#include <algorithm>

using namespace std;

/* 
 * Main function of quicksort that partitions the array into two halves and recursively sorts each half of the array
 */
int * Quicksort::quicksort(int * arr, int low, int high) {

	if (low >= high) return arr;

	int pivot = partition(arr, low, high);	// The pivot is now in the correct place
	quicksort(arr, low, pivot - 1);		// Sort the left half
	quicksort(arr, pivot + 1, high);	// Sort the right half
	return arr;
}

/*
 * With the pivot as the last element, partition the left half of the array with values less than the pivot and the right half with values greater than the pivot
 */
int Quicksort::partition(int * arr, int low, int high) {
	int pivot = findPivot(arr, low, high);
	swap(arr[pivot], arr[high]);		// Temporarily move the pivot to the last element

	int i;			// Current index
	int marker = low;	// The marker is used to indicate the next index to put an element that is less than the pivot
	
	// If the current element is less than the pivot, swap with the marker and increment BOTH the index and marker. 
	// Otherwise, only increment the index
	for (i = low; i < high; i++) {
		if (arr[i] < arr[high]) {
			if (i != marker) swap(arr[i], arr[marker]);
			marker++;
		}
	}
	swap(arr[marker], arr[high]);
	return marker;
}

/*
 * Find the median value of three values and use it as the pivot
 */
int Quicksort::findPivot(int * arr, int low, int high) {
	int i = arr[low];
	int j = arr[high];
	int k = arr[(high + low) / 2];

	if ((i > j && i < k) || (i > k && i < j)) return low;
	else if ((j > i && j < k) || (j > k && j < i)) return high;
	else return ((high + low) / 2);
}
