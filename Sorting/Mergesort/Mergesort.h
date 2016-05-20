#ifndef MERGESORT_H
#define MERGESORT_H

class Mergesort {

private:
	int * merge(int * a, int * b, int sizeA, int sizeB);

public:
	int * mergesort(int * a, int size);

};

#endif

