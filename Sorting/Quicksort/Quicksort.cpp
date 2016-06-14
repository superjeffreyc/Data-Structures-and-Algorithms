#include "Quicksort.h"
#include <algorithm>

using namespace std;

int * Quicksort::quicksort(int * arr, int low, int high) {

	if (low >= high) return arr;

	int pivot = partition(arr, low, high);
	quicksort(arr, low, pivot - 1);
	quicksort(arr, pivot + 1, high);
	return arr;
}

/*
 * With the pivot as the last element, partition the left half of the array with values less than the pivot and the right half with values greater than the pivot
 */
int Quicksort::partition(int * arr, int low, int high) {
	int pivot = findPivot(arr, low, high);
	swap(arr[pivot], arr[high]);

	int i, marker = low;
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
