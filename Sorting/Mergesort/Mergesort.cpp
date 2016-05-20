#include "Mergesort.h"
#include <algorithm>

using namespace std;

int * Mergesort::mergesort(int * a, int size) {

	if (size == 1) return a;
	else if (size == 2) {
		if (a[0] > a[1]) swap(a[0], a[1]);
		return a;
	}

	int * aLeft = new int[size / 2];
	int * aRight = new int[size - size / 2];

	for (int i = 0; i < size / 2; i++) {
		aLeft[i] = a[i];
	}

	for (int i = 0, j = size / 2; j < size; i++, j++) {
		aRight[i] = a[j];
	}

	aLeft = mergesort(aLeft, size / 2);
	aRight = mergesort(aRight, size - size / 2);
	int * merged = merge(aLeft, aRight, size / 2, size - size / 2);

	for (int i = 0; i < size; i++) {
		a[i] = merged[i];
	}

	return a;
}

int * Mergesort::merge(int * a, int * b, int sizeA, int sizeB) {
	int * array = new int[sizeA + sizeB];
	int i = 0, j = 0, k = 0;

	for (; i < sizeA && j < sizeB; k++) {
		if (a[i] < b[j]) array[k] = a[i++];
		else array[k] = b[j++];
	}

	if (i < sizeA) {
		for (; i < sizeA; k++) {
			array[k] = a[i++];
		}
	}
	else {
		for (; j < sizeB; k++) {
			array[k] = b[j++];
		}
	}

	return array;
}