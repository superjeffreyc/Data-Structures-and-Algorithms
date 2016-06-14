#ifndef QUICKSORT_H
#define QUICKSORT_H

class Quicksort {

private:
	int partition(int * arr, int low, int high);
	int findPivot(int * arr, int low, int high);
public:
	int * quicksort(int * arr, int low, int high);
};

#endif
