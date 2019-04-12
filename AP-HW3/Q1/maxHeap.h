#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath> //log2

/***********************************************************

CAUTION:

1. Use deleteMax() method instead of delete() (delete can not to be used in main!)
2. Use 1 starting indexes like matlab in main!! (important)
3. All of the  method's and variable's names are cammelCase words! (important)

************************************************************/



class MaxHeap;
std::ostream& operator<<(std::ostream& os, MaxHeap h);

class MaxHeap {
public:
	MaxHeap();
	MaxHeap(int* arr, size_t size);
	
	int parent(size_t);
	int leftChild(size_t);
	int rightChild(size_t);
	void printMaxHeap();
	void add(int);
	void deleteMax();
	void buildMaxHeap();
	int max();
	size_t getHeight();
	void printArray();
	void heapSort();

	int operator[](int i) const {return vec[i-1];}
    int& operator[](int i) {return vec[i-1];}
	
	std::vector<int> vec; //for cout, it must public;
private:
	size_t parentIndex(size_t);
	size_t leftChildIndex(size_t);
	size_t rightChildIndex(size_t);
	void swap(size_t, size_t);
	void maxHeapify(size_t);
	

	size_t heapSize;
	size_t heapHeight;
	
};

#endif
