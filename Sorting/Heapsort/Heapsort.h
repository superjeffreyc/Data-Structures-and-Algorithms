#ifndef HEAPSORT_H
#define HEAPSORT_H

class Heapsort {

private:
	void heapify(int * a, int size);
	int siftdown(int * a, int size, int i);
	bool isLeaf(int size, int i);
	int getLeft(int i);

public:
	int * heapsort(int * a, int size);

};

#endif
