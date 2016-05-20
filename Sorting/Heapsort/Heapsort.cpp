#include "Heapsort.h"
#include <algorithm>

using namespace std;

int * Heapsort::heapsort(int * a, int size) {

	if (size == 1) return a;

	heapify(a, size);

	while (size) {
		swap(a[0], a[size - 1]);
		size--;
		siftdown(a, size, 0);
	}

	return a;
}

void Heapsort::heapify(int * a, int size) {
	for (int i = (size - 2) / 2; i >= 0; i--) {
		siftdown(a, size, i);
	}
}

int Heapsort::siftdown(int * a, int size, int i) {
	if (i < 0 || i >= size) return i;

	while (!isLeaf(i, size)) {
		int max = getLeft(i);

		if (max + 1 < size && a[max] < a[max + 1]) {
			max += 1;
		}

		if (a[max] <= a[i]) return i;
		swap(a[max], a[i]);
		i = max;
	}

	return i;
}

bool Heapsort::isLeaf(int i, int size) {
	if (((2 * i) + 2) < size || ((2 * i) + 1) < size) return false;
	return true;
}

int Heapsort::getLeft(int i) {
	return ((2 * i) + 1);
}

