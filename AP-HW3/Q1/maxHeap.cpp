#include "maxHeap.h"

MaxHeap::MaxHeap() = default;
MaxHeap::MaxHeap(int* arr, size_t size) {
	for (size_t i{}; i < size; i++)
	{
		vec.push_back(arr[i]);
		buildMaxHeap();
	}
}

size_t MaxHeap::parentIndex(size_t i) {
	return static_cast<int>(i/2);
}

size_t MaxHeap::leftChildIndex(size_t i) {
	return (i * 2);
}

size_t MaxHeap::rightChildIndex(size_t i) {
	return (i * 2) + 1; 
}

int MaxHeap::parent(size_t i) {
	return vec[static_cast<int>(i/2) - 1];
}

int MaxHeap::leftChild(size_t i) {
	return vec[(i * 2) - 1];
}

int MaxHeap::rightChild(size_t i) {
	return vec[(i * 2 + 1) - 1]; 
}

void MaxHeap::maxHeapify(size_t i) {
	size_t largest{};
	size_t l{ leftChildIndex(i) };
	size_t r{ rightChildIndex(i) };
	
	if (l <= heapSize && vec[l-1] > vec[i-1])
	{
		largest = l;
	}
	else
	{
		largest = i;
	}
	if (r <= heapSize && vec[r-1] > vec[largest-1])
	{
		largest = r;
	}
	if (largest != i)
	{
		swap(i, largest);
		maxHeapify(largest);
	}
	//std::cout << "in maxHeapify" << std::endl;
}

void MaxHeap::swap(size_t i, size_t j) {
	std::swap(vec[i-1], vec[j-1]);
	//std::cout << "in swap" << std::endl;
}

void MaxHeap::printMaxHeap() {
	for (size_t i{1}; i <= vec.size(); i++)
	{
		std::cout << std::setw(3) << vec[i-1] << ", ";

		//Checking if i == 2^(x)-1
		size_t log2Ofi{static_cast<size_t>(std::log2(i+1))};
		if (i+1 == static_cast<size_t>(1 << log2Ofi))
			std::cout << std::endl;
	}
	std::cout << std::endl;
}

void MaxHeap::buildMaxHeap() {
	heapSize = vec.size();
	for(size_t i{static_cast<size_t>(heapSize/2)}; i >= 1; i--)
	{
		maxHeapify(i);
		//std::cout << i << "build" << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, MaxHeap h) {
	std::cout << "The MaxHeap: " << std::endl;
	for (size_t i{1}; i <= h.vec.size(); i++)
	{
		std::cout << std::setw(3) << h.vec[i-1] << ", ";

		//Checking if i == 2^(x)-1
		size_t log2Ofi{static_cast<size_t>(std::log2(i+1))};
		if (i+1 == static_cast<size_t>(1 << log2Ofi))
			std::cout << std::endl;
	}
  	return os;
}

void MaxHeap::add(int key) {
	vec.push_back(key);
	buildMaxHeap();
	//std::cout << "key: " << key << std::endl << std::endl;
}

void MaxHeap::deleteMax() {
	if(vec.size() > 0)
	{
		for (size_t i{1}; i < vec.size(); i++)
		{
			swap(i, i+1);
		}
		vec.pop_back();
		buildMaxHeap();
	}
	else
	{
		std::cout << "Heap underflow" << std::endl;
	}
}

int MaxHeap::max() {
	return vec[0];
}

size_t MaxHeap::getHeight() {
	size_t log2OfSize{static_cast<size_t>(std::log2(vec.size()))};
	return (log2OfSize);
}

void MaxHeap::printArray() {
	for (auto i : vec)
		std::cout << i << ", ";
	std::cout << std::endl;
}

void MaxHeap::heapSort() {
	buildMaxHeap();

	//Sorting
	for (size_t i{heapSize}; i >= 2; i--)
	{
		swap(1, i);
		heapSize--;
		maxHeapify(1);
	}

    //Reversing vector
	size_t tempSize{vec.size()};
	for (size_t i{}; i < tempSize/2; i++)
	{
		std::swap(vec[i], vec[tempSize - i - 1]);
	}
}
