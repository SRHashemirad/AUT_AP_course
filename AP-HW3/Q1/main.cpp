#include <iostream>
#include "maxHeap.h"


int main() {

	MaxHeap h1{};
	h1.add(25);
	h1.add(32);
	h1.add(17);
	h1.add(23);
	h1.add(101);  
 
	std::cout << h1 << std::endl;  
	/* 
	101,
	32, 17,
	23, 25
	*/
	std::cout << h1.parent(3) << std::endl; // 101
	std::cout << h1.leftChild(1) << std::endl;  // 32
	std::cout << h1.rightChild(1) << std::endl;  // 17


	int arr[7] {23, 1, 7, 52, 11, 10, 75};
	MaxHeap h2{arr, 7};
			
	std::cout << h2 << std::endl;;  
	std::cout << h2.getHeight() << std::endl; // 2


	MaxHeap h3{h2};

	h2.heapSort();
	h2.printArray(); // 75, 52, 23, 11, 10, 7, 1

	
	std::cout << h3.max() << std::endl;; //75

	h3.deleteMax();
	std::cout << h3.max() << std::endl; //52

	return 0;
}
